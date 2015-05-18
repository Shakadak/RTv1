#include "rtv1.h"

int		set_light(char *const *array, t_env *env)
{
	static int	i = 0;

	if (ft_split_len(array) == 5 && i < MAX_LIGHTS)
	{
		env->lights[i] = new_light(
				vtx_new(ft_atoi(array[1]),
					ft_atoi(array[2]),
					ft_atoi(array[3]), 1),
				ft_atof(array[4]));
		++i;
		return (1);
	}
	else
	{
		ft_putendl_fd("Error while setting light, skipping.", 2);
		return (-1);
	}
}

t_light	new_light(t_mtx const coordinate, double const intensity)
{
	t_light	new;

	new.defined = 1;
	new.pos = coordinate;
	new.intensity = intensity;
	return (new);
}
