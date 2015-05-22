/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 19:34:42 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:32:13 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_camera	new_camera(t_mtx const translation,
		t_mtx const rotation,
		t_pos const dim)
{
	t_camera	camera;

	camera.transform = transform_pipeline(vtx_new(1, 1, 1, 1),
			mtx_scalar_mult(M_PI / 180, rotation), translation);
	camera.fov = FOV * M_PI / 180;
	camera.screen = dim;
	return (camera);
}
