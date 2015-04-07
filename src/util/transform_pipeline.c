#include "rtv1.h"
#include <stdio.h>///////////

t_pipe	transform_pipeline(t_mtx const scale,
		t_mtx const rotate,
		t_mtx const translate)
{
	t_pipe pipe;

	pipe.t_pos = mtx_scale(scale.mtx[0], scale.mtx[1], scale.mtx[2]);
	pipe.t_pos = mtx_product(mtx_rotateX(rotate.mtx[0]), pipe.t_pos);
	pipe.t_pos = mtx_product(mtx_rotateY(rotate.mtx[1]), pipe.t_pos);
	pipe.t_pos = mtx_product(mtx_rotateZ(rotate.mtx[2]), pipe.t_pos);
	pipe.t_pos = mtx_product(mtx_translate(translate), pipe.t_pos);
	pipe.i_pos = mtx_translate(mtx_scalar_mult(-1, translate));
	pipe.i_dir = mtx_rotateZ(-rotate.mtx[2]);
	pipe.i_dir = mtx_product(pipe.i_dir, mtx_rotateY(-rotate.mtx[1]));
	pipe.i_dir = mtx_product(pipe.i_dir, mtx_rotateX(-rotate.mtx[0]));
	pipe.i_dir = mtx_product(pipe.i_dir, mtx_scale(1 /scale.mtx[0], 1 / scale.mtx[1], 1 / scale.mtx[2]));
	pipe.i_pos = mtx_product(pipe.i_dir, pipe.i_pos);
	printf("i_pos\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n",
			pipe.i_pos.mtx[0 * 4 + 0], pipe.i_pos.mtx[0 * 4 + 1], pipe.i_pos.mtx[0 * 4 + 2], pipe.i_pos.mtx[0 * 4 + 3],
			pipe.i_pos.mtx[1 * 4 + 0], pipe.i_pos.mtx[1 * 4 + 1], pipe.i_pos.mtx[1 * 4 + 2], pipe.i_pos.mtx[1 * 4 + 3],
			pipe.i_pos.mtx[2 * 4 + 0], pipe.i_pos.mtx[2 * 4 + 1], pipe.i_pos.mtx[2 * 4 + 2], pipe.i_pos.mtx[2 * 4 + 3],
			pipe.i_pos.mtx[3 * 4 + 0], pipe.i_pos.mtx[3 * 4 + 1], pipe.i_pos.mtx[3 * 4 + 2], pipe.i_pos.mtx[3 * 4 + 3]);
	printf("i_dir\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n",
			pipe.i_dir.mtx[0 * 4 + 0], pipe.i_dir.mtx[0 * 4 + 1], pipe.i_dir.mtx[0 * 4 + 2], pipe.i_dir.mtx[0 * 4 + 3],
			pipe.i_dir.mtx[1 * 4 + 0], pipe.i_dir.mtx[1 * 4 + 1], pipe.i_dir.mtx[1 * 4 + 2], pipe.i_dir.mtx[1 * 4 + 3],
			pipe.i_dir.mtx[2 * 4 + 0], pipe.i_dir.mtx[2 * 4 + 1], pipe.i_dir.mtx[2 * 4 + 2], pipe.i_dir.mtx[2 * 4 + 3],
			pipe.i_dir.mtx[3 * 4 + 0], pipe.i_dir.mtx[3 * 4 + 1], pipe.i_dir.mtx[3 * 4 + 2], pipe.i_dir.mtx[3 * 4 + 3]);
	printf("t_pos\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n",
			pipe.t_pos.mtx[0 * 4 + 0], pipe.t_pos.mtx[0 * 4 + 1], pipe.t_pos.mtx[0 * 4 + 2], pipe.t_pos.mtx[0 * 4 + 3],
			pipe.t_pos.mtx[1 * 4 + 0], pipe.t_pos.mtx[1 * 4 + 1], pipe.t_pos.mtx[1 * 4 + 2], pipe.t_pos.mtx[1 * 4 + 3],
			pipe.t_pos.mtx[2 * 4 + 0], pipe.t_pos.mtx[2 * 4 + 1], pipe.t_pos.mtx[2 * 4 + 2], pipe.t_pos.mtx[2 * 4 + 3],
			pipe.t_pos.mtx[3 * 4 + 0], pipe.t_pos.mtx[3 * 4 + 1], pipe.t_pos.mtx[3 * 4 + 2], pipe.t_pos.mtx[3 * 4 + 3]);
	return (pipe);
}
