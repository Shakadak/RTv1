#include "rtv1.h"

double	intersec_cone(t_ray const ray)
{
	double	a;
	double	b;
	double	c;

	a = SQR(ray.dir.x) + SQR(ray.dir.y) - SQR(ray.dir.z);
	b = 2 * (ray.pos.x * ray.dir.x + ray.pos.y * ray.dir.y - ray.pos.z * ray.dir.z);
	c = SQR(ray.pos.x) + SQR(ray.pos.y) - SQR(ray.pos.z);
	return (solve_quadratic(a, b, c));
}
