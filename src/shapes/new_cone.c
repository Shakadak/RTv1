#include "rtv1.h"

t_object	new_cone(t_vtx const scale,
		t_rot const rotate,
		t_vec const translate,
		t_color const color)
{
	t_object	cone;

	cone.kind = CONE;
	cone.rgb = color;
	cone.intersec = intersec_cone;
	cone.pipe = transform_pipeline(scale, rotate, translate);
	return (cone);
}
