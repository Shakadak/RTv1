/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec_quadric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:32:05 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:52:07 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	intersec_quadric(t_object const object, t_ray const ray)
{
	double	a;
	double	b;
	double	c;
	t_mtx	qdir;
	t_mtx	qpos;

	qdir = mtx_product(object.quadric, ray.dir);
	qpos = mtx_product(object.quadric, ray.pos);
	a = vec_dot(ray.dir, qdir);
	b = 2 * vec_dot(ray.dir, qpos);
	c = vec_dot(ray.pos, qpos);
	return (solve_quadratic(a, b, c));
}
