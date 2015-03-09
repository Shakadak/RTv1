#include "rtv1.h"

t_object			new_sphere(
		t_vtx const scale,
		t_rot const rotate,
		t_vec const translate,
		t_color const color)
{
	t_object	sphere;

	sphere.kind = SPHERE;
	sphere.rgb = color;
	sphere.intersec = intersec_sphere;
	sphere.pipe = transform_pipeline(scale, rotate, translate);
	return (sphere);
}
