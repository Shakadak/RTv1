#include "rtv1.h"

t_object	new_plane(t_mtx const scale,
		t_mtx const rotate,
		t_mtx const translate,
		t_color const color)
{
	t_object	plane;

	plane.defined = !0;
	plane.rgb = color;
	plane.pipe = transform_pipeline(scale, rotate, translate);
	plane.quadric = mtx_new(4, 4);
	plane.quadric.mtx[0 * 4 + 0] = 1;
	return (plane);
}
