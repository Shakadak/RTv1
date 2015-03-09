#include "rtv1.h"

t_pipe	transform_pipeline(t_ctx const scale,
		t_rot const rotate,
		t_vec const translate)
{
	t_pipe pipe;

	mtx_scale(scale.x, scale.y, scale.z);
	mtx_rotateX(rotate.x);
	mtx_rotateY(rotate.y);
	mtx_rotateZ(rotate.z);
	mtx_translate(translate);
	mtx_translate(vec_sub(new_vec(0, 0, 0), translate));
	mtx_rotateZ(-rotate.z);
	mtx_rotateY(-rotate.y);
	mtx_rotateX(-rotate.x);
	mtx_scale(1 /scale.x, 1 / scale.y, 1 / scale.z);
}
