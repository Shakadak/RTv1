/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 15:01:01 by npineau           #+#    #+#             */
/*   Updated: 2015/05/21 16:43:07 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_pipe	transform_pipeline(t_mtx const scale,
		t_mtx const rotate,
		t_mtx const translate)
{
	t_pipe pipe;
/*
	pipe.scale = mtx_scale(scale.mtx[0], scale.mtx[1], scale.mtx[2]);
	pipe.rotateX = mtx_rotateX(rotate.mtx[0]);
	pipe.rotateY = mtx_rotateY(rotate.mtx[1]);
	pipe.rotateZ = mtx_rotateZ(rotate.mtx[2]);
	pipe.rotate = mtx_product(pipe.rotateZ,
			mtx_product(pipe.rotateY, pipe.rotateX));
	pipe.translate = mtx_translate(translate);*/
	pipe.i_translate = mtx_translate(mtx_scalar_mult(-1, translate));
	pipe.i_rotateZ = mtx_rotateZ(-(rotate.mtx[2]));
	pipe.i_rotateY = mtx_rotateY(-(rotate.mtx[1]));
	pipe.i_rotateX = mtx_rotateX(-(rotate.mtx[0]));
	pipe.i_rotate = mtx_product(pipe.i_rotateX,
			mtx_product(pipe.i_rotateY, pipe.i_rotateZ));
	pipe.i_scale = mtx_scale(
			1 / scale.mtx[0], 1 / scale.mtx[1], 1 / scale.mtx[2]);/*
	pipe.t_pos = mtx_product(pipe.translate,
			mtx_product(pipe.rotate, pipe.scale));*/
	pipe.i_pos = mtx_product(pipe.i_scale,
			mtx_product(pipe.i_rotate, pipe.i_translate));
	return (pipe);
}
