#include <float.h>
#include "rtv1.h"

t_color	ray_cast(t_pos const pos,
		t_camera const camera,
		t_object const * objects,
		t_light const * lights)
{
	t_ray		ray;
	t_ray		t_ray;
	t_object	nearest;
	double		distance;
	double		t_distance;

	if (objects == NULL || lights == NULL)
		ft_fatal("Objects or lights uninitialized", 0);
	distance = DBL_MAX;
	ft_bzero(&nearest, sizeof(nearest));
	ray = new_ray(camera, pos);
	int	i = 0;
	while (objects->defined)
	{
		t_ray = ray_transform(ray, objects->pipe);
		t_distance = intersec_quadric(*objects, t_ray);
		if (t_distance > 0 && t_distance < distance)
		{
			distance = t_distance;
			nearest = *objects;
		}
		++i;
		++objects;
	}
	return (nearest.rgb);
}
