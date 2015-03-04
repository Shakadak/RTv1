#include "rtv1.h"

double	intersec_cylinder(t_object const self, t_ray const ray)
{
	double	a;
	double	b;
	double	c;
	t_vec	VxAB;
	t_vec	AOxAB;

	VxAB = vec_cross(ray.dir, self.shape.cylinder.dir);
	VxAB = vec_cross(vec_from_vtx(self.pos, ray.pos), self.shape.cylinder.dir);
	a = vec_dot(VxAB, VxAB);
	b = 2 * vec_dot(VxAB, AOxAB);
	c = vec_dot(AOxAB, AOxAB)
		- self.shape.cylinder.radius * self.shape.cylinder.radius
		* vec_dot(self.shape.cylinder.dir, self.shape.cylinder.dir);
	return (solve_quadratic(a, b, c));
}
