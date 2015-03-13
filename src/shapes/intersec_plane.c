#include "rtv1.h"

double	intersec_plane(t_ray const ray)
{
	double	a;
	double	b;
	double	c;

	a = 0;
	b = ray.dir.z;
	c = ray.pos.z;
	return (solve_quadratic(a, b, c));
}
