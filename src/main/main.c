#include "rtv1.h"

int	test(t_env *env)
{
	t_object	objects[2];
	t_ray		ray;
	int			x;
	int			y;
	t_pos		dim;
	t_camera	camera;
	int			dist;

			ft_putendl("yol");
	dim = new_pos(1366, 768, 0);
	camera = new_camera(vtx_new(0, 1, 0, 1), vtx_new(0, 0, -1, 1));
	objects[1] = new_sphere(vtx_new(10, 10, 10, 1),
			vtx_new(0, 0, 0, 1),
			vtx_new(0, 0, -105, 1),
			new_color(0xFF, 0xFF, 0x88));
	y = 0;
	while (y < dim.y)
	{
		x = 0;
		while (x < dim.x)
		{
			ray = new_ray(camera, new_pos(x, y, 0), dim);
			dist = objects[1].intersec(ray_transform(ray, objects[1].pipe));
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

	env.mlx = new_mlx();
	env.win = new_window(env.mlx, 1366, 768, "caca");
	env.img = new_image(env.mlx, 1366, 768);
	mlx_loop_hook(env.mlx, test, (void *)&env);
			ft_putendl("yol");
	mlx_loop(env.mlx);
	return (0);
}
