#include "rtv1.h"

t_object	new_sphere(t_coordinate const pos, double const radius, t_color const color)
{
	t_object	sphere;

	sphere.kind = SPHERE;
	sphere.shape.sphere.radius = radius;
	sphere.pos = pos;
	sphere.rgb = color;
	return (sphere);
}
