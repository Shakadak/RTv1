#include "rtv1.h"

t_object	new_cone(t_pipe const pipe, t_color const color)
{
	t_object	cone;

	cone.defined = !0;
	cone.rgb = color;
	cone.pipe = pipe;
	cone.quadric = mtx_new(4, 4);
	cone.quadric.mtx[0 * 4 + 0] = 1;
	cone.quadric.mtx[1 * 4 + 1] = 1;
	cone.quadric.mtx[2 * 4 + 2] = -1;
	cone.quadric = mtx_product(mtx_transpose(cone.pipe.i_pos),
			mtx_product(cone.quadric, cone.pipe.i_pos));
	return (cone);
}
