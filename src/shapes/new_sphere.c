/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:32:38 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:32:39 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object	new_sphere(t_pipe const pipe, t_color const color)
{
	t_object	sphere;

	sphere.defined = !0;
	sphere.rgb = color;
	sphere.pipe = pipe;
	sphere.quadric = mtx_new(4, 4);
	sphere.quadric.mtx[0 * 4 + 0] = 1;
	sphere.quadric.mtx[1 * 4 + 1] = 1;
	sphere.quadric.mtx[2 * 4 + 2] = 1;
	sphere.quadric.mtx[3 * 4 + 3] = -1;
	sphere.quadric = mtx_product(mtx_transpose(sphere.pipe.i_pos),
			mtx_product(sphere.quadric, sphere.pipe.i_pos));
	return (sphere);
}
