#include "rtv1.h"

t_pipe	transform_pipeline(t_vtx const scale,
		t_rot const rotate,
		t_vec const translate)
{
	t_pipe pipe;

	pipe.transform = mtx_scale(scale.x, scale.y, scale.z);
	pipe.transform = mtx_mult(mtx_rotateX(rotate.x), pipe.transform);
	pipe.transform = mtx_mult(mtx_rotateY(rotate.y), pipe.transform);
	pipe.transform = mtx_mult(mtx_rotateZ(rotate.z), pipe.transform);
	pipe.transform = mtx_mult(mtx_translate(translate), pipe.transform);
	pipe.inverse = mtx_translate(vtx_homogenize(vec_sub(vtx_new(0, 0, 0, 1), translate)));
	pipe.inverse = mtx_mult(pipe.inverse, mtx_rotateZ(-rotate.z));
	pipe.inverse = mtx_mult(pipe.inverse, mtx_rotateY(-rotate.y));
	pipe.inverse = mtx_mult(pipe.inverse, mtx_rotateX(-rotate.x));
	pipe.inverse = mtx_mult(pipe.inverse, mtx_scale(1 /scale.x, 1 / scale.y, 1 / scale.z));
	return (pipe);
}
