/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:32:24 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:32:28 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light	new_light(t_mtx const coordinate, double const intensity)
{
	t_light	new;

	new.defined = 1;
	new.pos = coordinate;
	new.intensity = intensity;
	return (new);
}
