/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 16:43:08 by npineau           #+#    #+#             */
/*   Updated: 2015/03/09 18:33:24 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	main(void)
{
	t_object	objects[2];
	t_ray		ray;
	int			x;
	int			y;
	t_pos		dim;
	t_camera	camera;

	dim = new_pos(100, 70, 0);
	camera = new_camera(vtx_new(0, 0, 0, 1), vtx_new(0, 0, -1, 1));
	objects[1] = new_sphere(vtx_new(5, 5, 5, 1),
			vtx_new(0, 0, 0, 1),
			vtx_new(0, 0, -30, 1),
			new_color(0xFF, 0xFF, 0x88));
	y = 0;
	while (y < dim.y)
	{
		x = 0;
		while (x < dim.x)
		{
			ray = new_ray(camera, new_pos(x, y, 0), dim);
			ft_putnbr_fd(objects[1].intersec(transform_ray(ray, objects[1].pipe)), 2);
			ft_putchar_fd('|', 2);
			(void)ray;
			++x;
		}
		ft_putchar_fd('\n', 2);
		++y;
	}
	return (0);
}
