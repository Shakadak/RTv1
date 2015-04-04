#include "rtv1.h"

t_object			new_sphere(
		t_mtx const scale,
		t_mtx const rotate,
		t_mtx const translate,
		t_color const color)
{
	t_object	sphere;

	sphere.defined = !0;
	sphere.rgb = color;
	sphere.pipe = transform_pipeline(scale, rotate, translate);
	return (sphere);
}
