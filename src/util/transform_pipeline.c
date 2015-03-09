#include "rtv1.h"
#include <stdio.h>///////////

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
	printf("\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n",
			pipe.inverse.m[0][0], pipe.inverse.m[0][1], pipe.inverse.m[0][2], pipe.inverse.m[0][3],
			pipe.inverse.m[1][0], pipe.inverse.m[1][1], pipe.inverse.m[1][2], pipe.inverse.m[1][3],
			pipe.inverse.m[2][0], pipe.inverse.m[2][1], pipe.inverse.m[2][2], pipe.inverse.m[2][3],
			pipe.inverse.m[3][0], pipe.inverse.m[3][1], pipe.inverse.m[3][2], pipe.inverse.m[3][3]);
	pipe.inverse = mtx_mult(pipe.inverse, mtx_rotateZ(-rotate.z));
	printf("\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n",
			pipe.inverse.m[0][0], pipe.inverse.m[0][1], pipe.inverse.m[0][2], pipe.inverse.m[0][3],
			pipe.inverse.m[1][0], pipe.inverse.m[1][1], pipe.inverse.m[1][2], pipe.inverse.m[1][3],
			pipe.inverse.m[2][0], pipe.inverse.m[2][1], pipe.inverse.m[2][2], pipe.inverse.m[2][3],
			pipe.inverse.m[3][0], pipe.inverse.m[3][1], pipe.inverse.m[3][2], pipe.inverse.m[3][3]);
	pipe.inverse = mtx_mult(pipe.inverse, mtx_rotateY(-rotate.y));
	printf("\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n",
			pipe.inverse.m[0][0], pipe.inverse.m[0][1], pipe.inverse.m[0][2], pipe.inverse.m[0][3],
			pipe.inverse.m[1][0], pipe.inverse.m[1][1], pipe.inverse.m[1][2], pipe.inverse.m[1][3],
			pipe.inverse.m[2][0], pipe.inverse.m[2][1], pipe.inverse.m[2][2], pipe.inverse.m[2][3],
			pipe.inverse.m[3][0], pipe.inverse.m[3][1], pipe.inverse.m[3][2], pipe.inverse.m[3][3]);
	pipe.inverse = mtx_mult(pipe.inverse, mtx_rotateX(-rotate.x));
	printf("\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n",
			pipe.inverse.m[0][0], pipe.inverse.m[0][1], pipe.inverse.m[0][2], pipe.inverse.m[0][3],
			pipe.inverse.m[1][0], pipe.inverse.m[1][1], pipe.inverse.m[1][2], pipe.inverse.m[1][3],
			pipe.inverse.m[2][0], pipe.inverse.m[2][1], pipe.inverse.m[2][2], pipe.inverse.m[2][3],
			pipe.inverse.m[3][0], pipe.inverse.m[3][1], pipe.inverse.m[3][2], pipe.inverse.m[3][3]);
	pipe.inverse = mtx_mult(pipe.inverse, mtx_scale(1 /scale.x, 1 / scale.y, 1 / scale.z));
	printf("\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n",
			pipe.inverse.m[0][0], pipe.inverse.m[0][1], pipe.inverse.m[0][2], pipe.inverse.m[0][3],
			pipe.inverse.m[1][0], pipe.inverse.m[1][1], pipe.inverse.m[1][2], pipe.inverse.m[1][3],
			pipe.inverse.m[2][0], pipe.inverse.m[2][1], pipe.inverse.m[2][2], pipe.inverse.m[2][3],
			pipe.inverse.m[3][0], pipe.inverse.m[3][1], pipe.inverse.m[3][2], pipe.inverse.m[3][3]);
	return (pipe);
}
