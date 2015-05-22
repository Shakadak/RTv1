/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atom_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:30:21 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:30:23 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_atom	atom_new(void)
{
	t_atom	new;

	ft_bzero(&new, sizeof(new));
	new.scale = vtx_new(1, 1, 1, 1);
	new.rotation = vtx_new(0, 0, 0, 1);
	new.translation = vtx_new(0, 0, 0, 1);
	new.color = new_color(0xFF, 0xFF, 0xFF, 0x00);
	new.intensity = 1;
	return (new);
}
