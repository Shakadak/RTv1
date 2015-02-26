/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 16:43:08 by npineau           #+#    #+#             */
/*   Updated: 2015/02/26 16:36:31 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	main(void)
{
	t_object	objects[2];

	objects[0] = new_camera(new_vtx(0, 0, 0), new_vtx(0, 0, -1));
	objects[1] = new_sphere(new_vtx(0, 0, -15), 3, new_color(0xFF, 0xFF, 0x88));
	ft_putnbr_fd(objects[1].shape.sphere.radius, 2);
	ft_putendl_fd("", 2);
	ft_putnbr_fd(objects[1].intersec(objects[1], new_ray(objects[0].shape.camera, new_pos(160, 100, 0), new_pos(320, 200, 0))), 2);
	return (0);
}
