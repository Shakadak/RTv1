#include "rtv1.h"

t_ray	transform_ray(t_ray const ray, t_pipe const pipe)
{
	t_ray	transformed;

	transformed.pos = vtx_transform(ray.pos, pipe.inverse);
	transformed.dir = vtx_transform(ray.dir, pipe.inverse);
	return (transformed);
}
