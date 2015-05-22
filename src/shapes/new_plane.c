/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:32:31 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:32:32 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object	new_plane(t_pipe const pipe, t_color const color)
{
	t_object	plane;

	plane.defined = !0;
	plane.rgb = color;
	plane.pipe = pipe;
	plane.quadric = mtx_new(4, 4);
	plane.quadric.mtx[2 * 4 + 2] = 1;
	plane.quadric = mtx_product(mtx_transpose(plane.pipe.i_pos),
			mtx_product(plane.quadric, plane.pipe.i_pos));
	return (plane);
}
