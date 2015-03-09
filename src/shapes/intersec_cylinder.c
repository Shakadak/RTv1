#include "rtv1.h"

double	intersec_cylinder(t_ray const ray)
{
	double	a;
	double	b;
	double	c;

	a = SQR(ray.dir.x) + SQR(ray.dir.y);
	b = 2 * (ray.pos.x * ray.dir.x + ray.pos.y * ray.dir.y);
	c = SQR(ray.pos.x) + SQR(ray.pos.y) - 1;
	return (solve_quadratic(a, b, c));
}
