#include "rtv1.h"
#include <stdio.h>///////////

t_pipe	transform_pipeline(t_vtx const scale,
		t_rot const rotate,
		t_vec const translate)
{
	t_pipe pipe;

	pipe.t_pos = mtx_scale(scale.x, scale.y, scale.z);
	pipe.t_pos = mtx_mult(mtx_rotateX(rotate.x), pipe.t_pos);
	pipe.t_pos = mtx_mult(mtx_rotateY(rotate.y), pipe.t_pos);
	pipe.t_pos = mtx_mult(mtx_rotateZ(rotate.z), pipe.t_pos);
	pipe.t_pos = mtx_mult(mtx_translate(translate), pipe.t_pos);
	pipe.i_pos = mtx_translate(vtx_homogenize(vec_sub(vtx_new(0, 0, 0, 1), translate)));
	pipe.i_dir = mtx_rotateZ(-rotate.z);
	pipe.i_dir = mtx_mult(pipe.i_dir, mtx_rotateY(-rotate.y));
	pipe.i_dir = mtx_mult(pipe.i_dir, mtx_rotateX(-rotate.x));
	pipe.i_dir = mtx_mult(pipe.i_dir, mtx_scale(1 /scale.x, 1 / scale.y, 1 / scale.z));
	pipe.i_pos = mtx_mult(pipe.i_dir, pipe.i_pos);
	printf("invers\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n",
			pipe.i_pos.m[0][0], pipe.i_pos.m[0][1], pipe.i_pos.m[0][2], pipe.i_pos.m[0][3],
			pipe.i_pos.m[1][0], pipe.i_pos.m[1][1], pipe.i_pos.m[1][2], pipe.i_pos.m[1][3],
			pipe.i_pos.m[2][0], pipe.i_pos.m[2][1], pipe.i_pos.m[2][2], pipe.i_pos.m[2][3],
			pipe.i_pos.m[3][0], pipe.i_pos.m[3][1], pipe.i_pos.m[3][2], pipe.i_pos.m[3][3]);
	printf("t_pos\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n",
			pipe.t_pos.m[0][0], pipe.t_pos.m[0][1], pipe.t_pos.m[0][2], pipe.t_pos.m[0][3],
			pipe.t_pos.m[1][0], pipe.t_pos.m[1][1], pipe.t_pos.m[1][2], pipe.t_pos.m[1][3],
			pipe.t_pos.m[2][0], pipe.t_pos.m[2][1], pipe.t_pos.m[2][2], pipe.t_pos.m[2][3],
			pipe.t_pos.m[3][0], pipe.t_pos.m[3][1], pipe.t_pos.m[3][2], pipe.t_pos.m[3][3]);
	return (pipe);
}
