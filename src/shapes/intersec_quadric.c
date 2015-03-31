#include "rtv1.h"

double			intersec_quadric(t_object const object, t_ray const ray)
{
	double	a;
	double	b;
	double	c;
	t_mtx	Qdir;
	t_mtx	Qpos;

	Qdir = mtx_mult(object.mtx, ray.dir);
	Qpos = mtx_mult(object.mtx, ray.pos);
	a = vec_dot(ray.dir, Qdir);
	b = 2 * vec_dot(ray.dir, Qpos);
	c = vec_dot(pos, Qpos);
	mtx_free(Qdir);
	mtx_free(Qpos);
	return (solve_quadratic(a, b, c));
}
