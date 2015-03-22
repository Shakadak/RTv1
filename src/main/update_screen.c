#include "rtv1.h"

int	update_screen(t_env const *env)
{
	apply_image(env->win, env->img, new_pos(0, 0, 0));
	return (0);
}
