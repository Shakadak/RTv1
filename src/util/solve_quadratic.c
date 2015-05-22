/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:34:14 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:34:16 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "rtv1.h"

double	solve_quadratic(double const a, double const b, double const c)
{
	double	delta;
	double	x0;
	double	x1;
	double	q;

	delta = b * b - 4.0 * a * c + EPSILON;
	if (delta < 0)
		return (-1);
	else if (delta == 0)
		return (x0 = -0.5 * b / a);
	else
	{
		q = (b > 0) ? -0.5 * (b + sqrt(delta)) : -0.5 * (b - sqrt(delta));
		x0 = q / a;
		x1 = c / q;
		if (x1 >= 0 && x0 >= 0)
			return (x0 < x1 ? x0 : x1);
		else if (x0 >= 0)
			return (x0);
		else if (x1 >= 0)
			return (x1);
		return (-2);
	}
}
