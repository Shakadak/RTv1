#include "rtv1.h"

t_object	new_cylinder(t_vtx const scale,
		t_rot const rotate,
		t_vec const translate,
		t_color const color)
{
	t_object	cylinder;

	cylinder.defined = !0;
	cylinder.kind = CYLINDER;
	cylinder.rgb = color;
	cylinder.intersec = intersec_cylinder;
	cylinder.pipe = transform_pipeline(scale, rotate, translate);
	return (cylinder);
}
