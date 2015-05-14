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
	sphere.quadric = mtx_new(4, 4);
	sphere.quadric.mtx[0 * 4 + 0] = 1;
	sphere.quadric.mtx[1 * 4 + 1] = 1;
	sphere.quadric.mtx[2 * 4 + 2] = 1;
	sphere.quadric.mtx[3 * 4 + 3] = -1;
	sphere.quadric = mtx_product(mtx_transpose(mtx_adjugate(sphere.pipe.t_pos)), mtx_product(sphere.quadric, mtx_adjugate(sphere.pipe.t_pos)));
	return (sphere);
}
