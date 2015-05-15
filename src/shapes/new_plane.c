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
	plane.quadric.mtx[2 * 4 + 2] = 1;
	plane.quadric = mtx_product(mtx_transpose(plane.pipe.i_pos), mtx_product(plane.quadric, plane.pipe.i_pos));
	return (plane);
}
