#include <math.h>
#include "rtv1.h"

int	test(t_env *env)
{
	t_ray		ray;
	int			x;
	int			y;
	int			dist;

	y = 0;
	while (y < env->img.dim.y)
	{
		x = 0;
		while (x < env->img.dim.x)
		{
			ray = new_ray(env->camera, new_pos(x, y, 0), env->img.dim);
			dist = env->objects[1].intersec(ray_transform(ray, env->objects[1].pipe));
			put_pixel_to_image(env->img, new_pixel(new_pos(x, y, 0), new_color(0, 0, (dist > 0 ? 200 : 0))));
			++x;
		}
		++y;
	}
	apply_image(env->win, env->img, new_pos(0, 0, 0));
	return (0);
}

int	main(void)
{
	t_env	env;

	env.camera = new_camera(vtx_new(0, 1, 0, 1), vtx_new(0, 0, -1, 1));
	env.objects[1] = new_cone(vtx_new(5, 1, 1, 1),
			vtx_new(45 * M_PI / 180, 45 * M_PI / 180, 00 * M_PI / 180, 1),
			vtx_new(0, 0, -105, 1),
			new_color(0xFF, 0xFF, 0x88));
	env.mlx = new_mlx();
	env.win = new_window(env.mlx, 1366, 768, "holy carp");
	env.img = new_image(env.mlx, 1366, 768);
	mlx_loop_hook(env.mlx, test, (void *)&env);
	mlx_key_hook(env.win.win, key_press, NULL);
	mlx_loop(env.mlx);
	return (0);
}
