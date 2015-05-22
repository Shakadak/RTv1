/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vtx_homogenize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:35:33 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:35:35 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_mtx	vtx_homogenize(t_mtx const vtx)
{
	t_mtx	homogenized;

	homogenized = vtx;
	homogenized.mtx[0] = vtx.mtx[0] / vtx.mtx[3];
	homogenized.mtx[1] = vtx.mtx[1] / vtx.mtx[3];
	homogenized.mtx[2] = vtx.mtx[2] / vtx.mtx[3];
	homogenized.mtx[3] = vtx.mtx[3] / vtx.mtx[3];
	return (homogenized);
}
