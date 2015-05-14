#include <math.h>
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
			rgb = ray_cast(new_pos(x, y, 0), env->camera, env->objects, env->lights);
			put_pixel_to_image(env->img, new_pixel(new_pos(x, y, 0), rgb));
			++x;
		}
		++y;
		if (y % (env->img.dim.y / 10) == 0)
		{
			update_screen(env);
			mlx_do_sync(env->mlx);
		}
	}
	return (0);
}

int	main(void)
{
	t_env	env;

	ft_bzero(&env, sizeof(env));
	env.camera = new_camera(vtx_new(0, 0, -20, 1), vtx_new(0, 0, -1, 1), new_pos(1350, 750, 0));
	env.objects[6] = new_cone(vtx_new(1, 1, 1.0, 1),
			vtx_new(90 * M_PI / 180, 00 * M_PI / 180, 00 * M_PI / 180, 1),
			vtx_new(0, 0, -105, 1),
			new_color(0xFF, 0x00, 0x00, 0x00));
	env.objects[0] = new_sphere(vtx_new(25, 25, 25, 1),
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
	env.objects[4] = new_cylinder(vtx_new(5, 5, 5, 1),
			vtx_new(90 * M_PI / 180, 0 * M_PI / 180, 00 * M_PI / 180, 1),
			vtx_new(15, 0, -64, 1),
			new_color(0x00, 0xFF, 0x00, 0x00));
	env.objects[5] = new_plane(vtx_new(25, 25, 25, 1),
			vtx_new(000 * M_PI / 180, 000 * M_PI / 180, 00 * M_PI / 180, 1),
			vtx_new(-200, 0, -105, 1),
			new_color(0xFF, 0x00, 0x00, 0x00));
	env.lights[0] = new_light(vtx_new(0, 0, 0, 1));
	env.lights[2] = new_light(vtx_new(-50, 0, -105, 1));
	env.mlx = new_mlx();
	env.win = new_window(env.mlx, env.camera.screen.x, env.camera.screen.y,
			"holy carp");
	env.img = new_image(env.mlx, env.camera.screen.x, env.camera.screen.y);
	mlx_loop_hook(env.mlx, test, &env);
	mlx_key_hook(env.win.win, key_press, &env);
	mlx_expose_hook(env.win.win, update_screen, &env);
	mlx_loop(env.mlx);
	return (0);
}
