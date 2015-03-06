#include "rtv1.h"

t_mtx	mtx_translate(t_vec const vec)
{
	t_mtx	translation;

	transation = mtx_identity();
	translation[0][3] = vec.x;
	translation[1][3] = vec.y;
	translation[2][3] = vec.z;
	return (translation);
}
