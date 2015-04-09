#include "rtv1.h"

t_color	ray_shade(t_object const obj,
		t_ray const ray,
		double const dist,
		t_object const *objects,
		t_light const *lights)
{
	t_ray	normal;
	t_ray	l_ray;
	double	dot;

	normal = ray_normal(obj, ray, dist);
	while (lights->defined)
	{
		l_ray.dir = mtx_sub(lights->pos, normal.pos);
		dot = vec_dot(normal.dir, l_ray);
		if (dot >= 1 || dot < 0)
			continue;
		++lights;
	}
}
