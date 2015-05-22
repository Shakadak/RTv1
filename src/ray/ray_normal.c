/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:31:23 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:31:24 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray	ray_normal(t_object const obj, t_ray const ray, double const dist)
{
	t_ray	normal;

	normal.pos = mtx_add(ray.pos, mtx_scalar_mult(dist, ray.dir));
	normal.dir = vec_new(obj.quadric.mtx[0] * normal.pos.mtx[0]
			+ obj.quadric.mtx[1] * normal.pos.mtx[1]
			+ obj.quadric.mtx[2] * normal.pos.mtx[2]
			+ obj.quadric.mtx[3],
			obj.quadric.mtx[4] * normal.pos.mtx[0]
			+ obj.quadric.mtx[5] * normal.pos.mtx[1]
			+ obj.quadric.mtx[6] * normal.pos.mtx[2]
			+ obj.quadric.mtx[7],
			obj.quadric.mtx[8] * normal.pos.mtx[0]
			+ obj.quadric.mtx[9] * normal.pos.mtx[1]
			+ obj.quadric.mtx[10] * normal.pos.mtx[2]
			+ obj.quadric.mtx[11]);
	normal.dir = vec_normalize(normal.dir);
	normal.pos = vtx_homogenize(normal.pos);
	if (vec_dot(normal.dir, ray.dir) > 0)
		normal.dir = mtx_scalar_mult(-1, normal.dir);
	return (normal);
}
