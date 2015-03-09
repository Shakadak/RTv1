#include "rtv1.h"

t_mtx	mtx_translate(t_vec const vec)
{
	t_mtx	translation;

	translation = mtx_identity();
	translation.m[0][3] = vec.x;
	translation.m[1][3] = vec.y;
	translation.m[2][3] = vec.z;
	return (translation);
}
