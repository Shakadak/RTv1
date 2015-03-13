#include "rtv1.h"

t_object	new_plane(t_vtx const scale,
		t_rot const rotate,
		t_vec const translate,
		t_color const color)
{
	t_object	plane;

	plane.kind = PLANE;
	plane.rgb = color;
	plane.intersec = intersec_plane;
	plane.pipe = transform_pipeline(scale, rotate, translate);
	return (plane);
}
