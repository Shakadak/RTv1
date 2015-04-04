#include "rtv1.h"

t_mtx	mtx_translate(t_mtx const vec)
{
	t_mtx	translation;

	translation = mtx_identity(4);
	translation.mtx[3 * 4 + 0] = vec.mtx[0];
	translation.mtx[3 * 4 + 1] = vec.mtx[1];
	translation.mtx[3 * 4 + 2] = vec.mtx[2];
	return (translation);
}
