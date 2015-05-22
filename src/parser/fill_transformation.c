/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_transformation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:30:36 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:30:37 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_mtx	fill_transformation(char const *const *const src, int *i)
{
	if (ft_split_len(src + *i) < 4)
		ft_fatal("Error while parsing transformation.\n", 0);
	return (vtx_new(ft_atof(src[++(*i)]), ft_atof(src[++(*i)]),
	ft_atof(src[++(*i)]), 1));
}
