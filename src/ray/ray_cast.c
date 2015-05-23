/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:31:08 by npineau           #+#    #+#             */
/*   Updated: 2015/05/23 09:30:09 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "rtv1.h"

static void	get_nearest(t_object const *olist, t_ray const ray,
		t_object *nearest_object, double *nearest_distance)
{
	double	distance;

	ft_bzero(nearest_object, sizeof(*nearest_object));
	*nearest_distance = DBL_MAX;
	while (olist->defined)
	{
		distance = intersec_quadric(*olist, ray);
		if (distance >= 0 && distance < *nearest_distance)
		{
			*nearest_distance = distance;
			*nearest_object = *olist;
		}
		++olist;
	}
}

t_color		ray_cast(t_pos const pos,
		t_camera const camera,
		t_env const *env)
{
	t_ray		ray;
	t_object	nearest;
	double		distance;

	ray = ray_new(camera, pos);
	get_nearest(env->objects, ray, &nearest, &distance);
	if (nearest.defined)
		return (ray_shade(nearest, ray, distance, env));
	else
		return (nearest.rgb);
}
