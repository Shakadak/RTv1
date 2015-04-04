#include "rtv1.h"

t_object	new_cone(t_mtx const scale,
		t_mtx const rotate,
		t_mtx const translate,
		t_color const color)
{
	t_object	cone;

	cone.defined = !0;
	cone.rgb = color;
	cone.pipe = transform_pipeline(scale, rotate, translate);
	return (cone);
}
