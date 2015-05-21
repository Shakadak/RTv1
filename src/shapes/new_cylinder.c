#include "rtv1.h"

t_object	new_cylinder(t_pipe const pipe, t_color const color)
{
	t_object	cylinder;

	cylinder.defined = !0;
	cylinder.rgb = color;
	cylinder.pipe = pipe;
	cylinder.quadric = mtx_new(4, 4);
	cylinder.quadric.mtx[0 * 4 + 0] = 1;
	cylinder.quadric.mtx[1 * 4 + 1] = 1;
	cylinder.quadric.mtx[3 * 4 + 3] = -1;
	cylinder.quadric = mtx_product(mtx_transpose(cylinder.pipe.i_pos),
			mtx_product(cylinder.quadric, cylinder.pipe.i_pos));
	return (cylinder);
}
