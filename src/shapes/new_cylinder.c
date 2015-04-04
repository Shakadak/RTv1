#include "rtv1.h"

t_object	new_cylinder(t_mtx const scale,
		t_mtx const rotate,
		t_mtx const translate,
		t_color const color)
{
	t_object	cylinder;

	cylinder.defined = !0;
	cylinder.rgb = color;
	cylinder.pipe = transform_pipeline(scale, rotate, translate);
	return (cylinder);
}
