#include "rtv1.h"

double	intersec_quadric(t_object const object, t_ray const ray)
{
	double	a;
	double	b;
	double	c;
	t_mtx	Qdir;
	t_mtx	Qpos;

	Qdir = mtx_product(object.quadric, ray.dir);
	Qpos = mtx_product(object.quadric, ray.pos);
	a = vec_dot(ray.dir, Qdir);
	b = 2 * vec_dot(ray.dir, Qpos);
	c = vec_dot(ray.pos, Qpos);
	mtx_free(Qdir);
	mtx_free(Qpos);
	return (solve_quadratic(a, b, c));
}
