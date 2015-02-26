#include "rtv1.h"

double	intersec_sphere(t_object const self, t_ray const ray)
{
	double	a;
	double	b;
	double	c;
	t_vec	line;

	line = vec_sub(ray.pos, self.pos);
	a = vec_dot(ray.dir, ray.dir);
	b = 2 * vec_dot(ray.dir, line);
	c = vec_dot(line, line) - self.shape.sphere.radius * self.shape.sphere.radius;
	return (solve_quadratic(a, b, c));
}
