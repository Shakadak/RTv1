/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:29:56 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:29:59 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	test(t_env *env)
{
	int			x;
	static int	y = 0;
	t_color		rgb;

	if (y < env->img.dim.y)
	{
		x = 0;
		while (x < env->img.dim.x)
		{
			rgb = ray_cast(new_pos(x, y, 0), env->cameras[0], env->objects, env->lights);
			put_pixel_to_image(env->img, new_pixel(new_pos(x, y, 0), rgb));
			++x;
		}
		++y;
		update_screen(env);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./rtv1 path/to/map", 2);
		return (1);
	}
	ft_bzero(&env, sizeof(env));
	env.mlx = new_mlx();
	env.win = new_window(env.mlx, WIDTH, HEIGTH, "holy carp");
	env.img = new_image(env.mlx, env.win.dim.x, env.win.dim.y);
	scene_to_struct(argv[1], &env);
	mlx_loop_hook(env.mlx, test, &env);
	mlx_key_hook(env.win.win, key_press, &env);
	mlx_expose_hook(env.win.win, update_screen, &env);
	mlx_loop(env.mlx);
	return (0);
}
