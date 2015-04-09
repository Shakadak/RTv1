#include "rtv1.h"

t_ray	ray_normal(t_object const obj, t_ray const ray, double const dist)
{
	t_ray	normal;
	t_ray	t_ray;

	t_ray = ray_transform(ray, obj.pipe);
	normal.pos = mtx_add(t_ray.pos, mtx_scalar_mult(dist, t_ray.dir));
	normal.dir = vec_new(obj.quadric.mtx[0] * normal.pos.mtx[0]
			+ obj.quadric.mtx[1] * normal.pos.mtx[1]
			+ obj.quadric.mtx[2] * normal.pos.mtx[2]
			+ obj.quadric.mtx[3],
			+ obj.quadric.mtx[4] * normal.pos.mtx[0]
			+ obj.quadric.mtx[5] * normal.pos.mtx[1]
			+ obj.quadric.mtx[6] * normal.pos.mtx[2]
			+ obj.quadric.mtx[7],
			+ obj.quadric.mtx[8] * normal.pos.mtx[0]
			+ obj.quadric.mtx[9] * normal.pos.mtx[1]
			+ obj.quadric.mtx[10] * normal.pos.mtx[2]
			+ obj.quadric.mtx[11]);
	normal.pos = mtx_product(obj.pipe.t_pos, normal.pos);
	normal.dir = mtx_product(obj.pipe.t_normal, normal.dir);
	normal.dir = vec_normalize(normal.dir);
	return (normal);
}
