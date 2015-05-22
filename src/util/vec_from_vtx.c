/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_from_vtx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:34:49 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:34:50 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_mtx	vec_from_vtx(t_mtx const origin, t_mtx const destination)
{
	return (mtx_sub(destination, origin));
}
