#include <math.h>
#include <stdio.h>///////////////
#include "rtv1.h"

int	test(t_env *env)
{
	int			x;
	static int			y = 0;
	t_color		rgb;

//	y = 0;
	while (y < env->img.dim.y)
	{
		x = 0;
		while (x < env->img.dim.x)
		{
			rgb = ray_cast(new_pos(x, y, 0), env->camera, env->objects, env->lights);
			put_pixel_to_image(env->img, new_pixel(new_pos(x, y, 0), rgb));
			++x;
		}
		++y;
	}
	update_screen(env);
	mlx_do_sync(env->mlx);
//	apply_image(env->win, env->img, new_pos(0, 0, 0));
	return (0);
}

int	main(void)
{
	t_env	env;

	env.camera = new_camera(vtx_new(0, 1, 0, 1), vtx_new(0, 0, -1, 1), new_pos(1366, 768, 0));
	ft_bzero(env.objects, sizeof(env.objects));
	env.objects[0] = new_cone(vtx_new(0, 0, 0, 1),
			vtx_new(45 * M_PI / 180, 45 * M_PI / 180, 00 * M_PI / 180, 1),
			vtx_new(0, 0, -105, 1),
			new_color(0xFF, 0x88, 0x88, 0x00));
	env.objects[1] = new_sphere(vtx_new(25, 25, 25, 1),
			vtx_new(0 * M_PI / 180, 0 * M_PI / 180, 00 * M_PI / 180, 1),
			vtx_new(0, 0, -105, 1),
			new_color(0xFF, 0xFF, 0x00, 0x00));
	env.objects[2] = new_sphere(vtx_new(25, 25, 25, 1),
			vtx_new(0 * M_PI / 180, 0 * M_PI / 180, 00 * M_PI / 180, 1),
			vtx_new(-15, 0, -105, 1),
			new_color(0xFF, 0xFF, 0x00, 0x00));
	env.objects[3] = new_sphere(vtx_new(25, 25, 25, 1),
			vtx_new(0 * M_PI / 180, 0 * M_PI / 180, 00 * M_PI / 180, 1),
			vtx_new(15, 0, -105, 1),
			new_color(0xFF, 0xFF, 0x00, 0x00));
	env.objects[4] = new_cylinder(vtx_new(5, 6, 1, 1),
			vtx_new(90 * M_PI / 180, 0 * M_PI / 180, 00 * M_PI / 180, 1),
			vtx_new(15, 0, -84, 1),
			new_color(0x00, 0xFF, 0x00, 0x00));
	env.objects[5] = new_plane(vtx_new(25, 25, 25, 1),
			vtx_new(45 * M_PI / 180, 90 * M_PI / 180, 00 * M_PI / 180, 1),
			vtx_new(-200, 0, -105, 1),
			new_color(0xFF, 0x00, 0x00, 0x00));
	env.mlx = new_mlx();
	env.win = new_window(env.mlx, env.camera.screen.x, env.camera.screen.y, "holy carp");
	env.img = new_image(env.mlx, env.camera.screen.x, env.camera.screen.y);
	mlx_loop_hook(env.mlx, test, (void *)&env);
	mlx_key_hook(env.win.win, key_press, NULL);
	mlx_expose_hook(env.win.win, update_screen, &env);
	mlx_loop(env.mlx);
	return (0);
}
