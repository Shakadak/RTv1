/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_magnitude.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:35:04 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:35:08 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

double	vec_magnitude(t_mtx const vec)
{
	return (sqrt(SQR(vec.mtx[0]) + SQR(vec.mtx[1]) + SQR(vec.mtx[2])));
}
