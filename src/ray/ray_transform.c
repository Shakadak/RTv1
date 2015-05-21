#include "rtv1.h"

t_ray	ray_transform(t_ray const ray, t_pipe const pipe)
{
	t_ray	transformed;

	transformed.pos = mtx_product(pipe.t_pos, ray.pos);
	transformed.dir = mtx_product(pipe.t_pos, ray.dir);
	return (transformed);
}
