#include "rtv1.h"
#include <stdio.h>////////////

double	intersec_sphere(t_ray const ray)
{
	double	a;
	double	b;
	double	c;

	printf("isphere ray.pos.x: %f, ray.pos.t: %f, ray.pos.z: %f\n", ray.pos.x, ray.pos.y, ray.pos.z);
	a = vec_dot(ray.dir, ray.dir);
	b = 2 * vec_dot(ray.dir, ray.pos);
	c = vec_dot(ray.pos, ray.pos) - 1;
	return (solve_quadratic(a, b, c));
}
