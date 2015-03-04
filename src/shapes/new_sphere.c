#include "rtv1.h"

t_object	new_sphere(t_vtx const pos, t_color const color, double const radius)
{
	t_object	sphere;

	sphere.kind = SPHERE;
	sphere.pos = pos;
	sphere.rgb = color;
	sphere.intersec = intersec_sphere;
	sphere.shape.sphere.radius = radius;
	return (sphere);
}
