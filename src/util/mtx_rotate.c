/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:32:57 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:33:12 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

t_mtx	mtx_rotatex(double const angle)
{
	t_mtx	rotation;

	rotation = mtx_identity(4);
	rotation.mtx[1 * 4 + 1] = cos(angle);
	rotation.mtx[1 * 4 + 2] = -sin(angle);
	rotation.mtx[2 * 4 + 1] = sin(angle);
	rotation.mtx[2 * 4 + 2] = cos(angle);
	return (rotation);
}

t_mtx	mtx_rotatey(double const angle)
{
	t_mtx	rotation;

	rotation = mtx_identity(4);
	rotation.mtx[0 * 4 + 0] = cos(angle);
	rotation.mtx[0 * 4 + 2] = sin(angle);
	rotation.mtx[2 * 4 + 0] = -sin(angle);
	rotation.mtx[2 * 4 + 2] = cos(angle);
	return (rotation);
}

t_mtx	mtx_rotatez(double const angle)
{
	t_mtx	rotation;

	rotation = mtx_identity(4);
	rotation.mtx[0 * 4 + 0] = cos(angle);
	rotation.mtx[0 * 4 + 1] = -sin(angle);
	rotation.mtx[1 * 4 + 0] = sin(angle);
	rotation.mtx[1 * 4 + 1] = cos(angle);
	return (rotation);
}
