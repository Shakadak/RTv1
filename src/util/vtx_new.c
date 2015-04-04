/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vtx_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 15:37:06 by npineau           #+#    #+#             */
/*   Updated: 2015/04/04 18:26:32 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_mtx	vtx_new(double const x, double const y, double const z, double const w)
{
	t_mtx	vtx;

	vtx = mtx_new(4, 1);
	vtx.mtx[0] = x;
	vtx.mtx[1] = y;
	vtx.mtx[2] = z;
	vtx.mtx[3] = w;
	return (vtx);
}
