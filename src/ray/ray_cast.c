#include <float.h>
#include "rtv1.h"

typedef struct	s_onear
{
	t_object	obj;
	double		distance;
}				t_onear;

static t_onear	get_nearest(t_object const * olist, t_ray const ray)
{
	double	distance;
	t_onear	nearest;

	ft_bzero(&nearest, sizeof(nearest));
	nearest.distance = DBL_MAX;
	while (olist->defined)
	{
		distance = intersec_quadric(*olist, ray);
		if (distance > 0 && distance < nearest.distance)
		{
			nearest.distance = distance;
			nearest.obj = *olist;
		}
		++olist;
	}
	return (nearest);
}

t_color		ray_cast(t_pos const pos,
		t_camera const camera,
		t_object *objects,
		t_light const *lights)
{
	t_ray	ray;
	t_onear	nearest;

	if (objects == NULL || lights == NULL)
		ft_fatal("Objects or lights uninitialized", 0);
	ray = ray_new(camera, pos);
	nearest = get_nearest(objects, ray);
	if (nearest.obj.defined)
		return (ray_shade(nearest.obj, ray, nearest.distance, objects, lights));
	else
		return (nearest.obj.rgb);
}
