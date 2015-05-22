/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shade.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:31:57 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 20:13:10 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		obstructed(t_object const *olist, t_ray const ray)
{
	double		d;

	while (olist->defined)
	{
		d = intersec_quadric(*olist, ray);
		if (0.0 + EPSILON < d && d <= 1)
			return (1);
		++olist;
	}
	return (0);
}

static t_color	update_color(t_color rgb, double factor)
{
	rgb.rgb[0] = factor * rgb.rgb[0] > 0xFF ? 255 : factor * rgb.rgb[0];
	rgb.rgb[1] = factor * rgb.rgb[1] > 0xFF ? 255 : factor * rgb.rgb[1];
	rgb.rgb[2] = factor * rgb.rgb[2] > 0xFF ? 255 : factor * rgb.rgb[2];
	return (rgb);
}

t_color			ray_shade(t_object obj,
		t_ray const ray,
		double const dist,
		t_object const *olist,
		t_light const *lights)
{
	t_ray		normal;
	t_ray		l_ray;
	double		dot;
	double		expo;

	expo = 0.85;
	normal = ray_normal(obj, ray, dist);
	while (lights->defined)
	{
		l_ray.dir = mtx_sub(lights->pos, normal.pos);
		dot = vec_dot(normal.dir, vec_normalize(l_ray.dir));
		if (!(0.0 < dot + EPSILON && dot <= 1.0 + EPSILON))
		{
			++lights;
			continue;
		}
		l_ray.pos = normal.pos;
		if (!obstructed(olist, l_ray))
		{
			expo *= (1 - dot * lights->intensity);
		}
		++lights;
	}
	return (update_color(obj.rgb, 1 - expo));
}
