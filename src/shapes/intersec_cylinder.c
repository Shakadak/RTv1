#include "rtv1.h"
#include <stdio.h>////////////
double	intersec_cylinder(t_ray const ray)
{
	double	a;
	double	b;
	double	c;

	printf("ray.pos.x: %f, ray.pos.t: %f, ray.pos.z: %f\n", ray.pos.x, ray.pos.y, ray.pos.z);
	a = SQR(ray.dir.x) + SQR(ray.dir.y);
	b = 2 * (ray.pos.x * ray.dir.x + ray.pos.y * ray.dir.y);
	c = SQR(ray.pos.x) + SQR(ray.pos.y) - 1;
	return (solve_quadratic(a, b, c));
}
