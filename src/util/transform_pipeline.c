/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:39:43 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:57:39 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_pipe	transform_pipeline(t_mtx const scale,
		t_mtx const rotate,
		t_mtx const translate)
{
	t_pipe pipe;

	pipe.scale = mtx_scale(scale.mtx[0], scale.mtx[1], scale.mtx[2]);
	pipe.rotatex = mtx_rotatex(rotate.mtx[0]);
	pipe.rotatey = mtx_rotatey(rotate.mtx[1]);
	pipe.rotatez = mtx_rotatez(rotate.mtx[2]);
	pipe.rotate = mtx_product(pipe.rotatez,
			mtx_product(pipe.rotatey, pipe.rotatex));
	pipe.translate = mtx_translate(translate);
	pipe.i_translate = mtx_translate(mtx_scalar_mult(-1, translate));
	pipe.i_rotatez = mtx_rotatez(-(rotate.mtx[2]));
	pipe.i_rotatey = mtx_rotatey(-(rotate.mtx[1]));
	pipe.i_rotatex = mtx_rotatex(-(rotate.mtx[0]));
	pipe.i_rotate = mtx_product(pipe.i_rotatex,
			mtx_product(pipe.i_rotatey, pipe.i_rotatez));
	pipe.i_scale = mtx_scale(
			1 / scale.mtx[0], 1 / scale.mtx[1], 1 / scale.mtx[2]);
	pipe.t_pos = mtx_product(pipe.translate,
			mtx_product(pipe.rotate, pipe.scale));
	pipe.i_pos = mtx_product(pipe.i_scale,
			mtx_product(pipe.i_rotate, pipe.i_translate));
	return (pipe);
}
