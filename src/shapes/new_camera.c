#include "rtv1.h"
#include <math.h>

int		set_camera(char *const *array, t_env *env)
{
	static int	i = 0;

	if (ft_split_len(array) == 9 && i < MAX_CAMERAS)
	{
		env->camera[i] = new_camera(
				vtx_new(ft_atoi(array[1]),
					ft_atoi(array[2]),
					ft_atoi(array[3]), 1),
				vtx_new(ft_atoi(array[4]),
					ft_atoi(array[5]),
					ft_atoi(array[6]), 1),
				new_pos(ft_atoi(array[7]), ft_atoi(array[8]), 0));
		++i;
		return (1);
	}
	else
	{
		ft_putendl_fd("Error while setting light, skipping.", 2);
		return (-1);
	}
}

t_camera	new_camera(t_mtx const pos, t_mtx const dir, t_pos const dim)
{
	t_camera	camera;

	camera.dir = mtx_dup(dir);
	camera.fov = 90 * M_PI / 180;
	camera.pos = mtx_dup(pos);
	camera.screen = dim;
	return (camera);
}
