/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 16:43:08 by npineau           #+#    #+#             */
/*   Updated: 2015/02/17 14:15:00 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	main(void)
{
	t_object	objects[2];

	objects[0] = new_sphere(new_coordinate(3, 3, 3), 3, new_color(0xFF, 0xFF, 0x88));
	ft_putnbr_fd(objects[1].shape.sphere.radius, 2);
	return (0);
}
