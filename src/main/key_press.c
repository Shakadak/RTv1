#include <stdlib.h>
#include "rtv1.h"

int	key_press(int key, t_env const *env)
{
	if (key == 53 || key == 65307)
	{
		mlx_destroy_image(env->mlx, env->img.img);
		mlx_destroy_image(env->mlx, env->win.win);
		exit(0);
	}
	return (0);
}
