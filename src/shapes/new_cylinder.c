#include "rtv1.h"

t_object	new_cylinder(t_vtx const pos,
		t_color const color,
		t_vec const dir,
		double radius)
{
	t_object	cylinder;

	cylinder.kind = CYLINDER;
	cylinder.pos = pos;
	cylinder.rgb = color;
	cylinder.intersec = intersec_cylinder;
	cylinder.shape.cylinder.radius = radius;
	cylinder.shape.cylinder.dir = dir;
	return (cylinder);
}
