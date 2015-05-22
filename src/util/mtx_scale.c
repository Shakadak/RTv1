/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:33:14 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:33:16 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_mtx	mtx_scale(double const x, double const y, double const z)
{
	t_mtx	scale;

	scale = mtx_identity(4);
	scale.mtx[0 * 4 + 0] = x;
	scale.mtx[1 * 4 + 1] = y;
	scale.mtx[2 * 4 + 2] = z;
	return (scale);
}
