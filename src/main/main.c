/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 16:43:08 by npineau           #+#    #+#             */
/*   Updated: 2015/02/26 16:00:14 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	main(void)
{
	t_object	objects[2];

	objects[1] = new_sphere(new_vtx(0, 0, 0), 3, new_color(0xFF, 0xFF, 0x88));
	ft_putnbr_fd(objects[1].shape.sphere.radius, 2);
	return (0);
}
