#include "rtv1.h"

t_mtx	mtx_translate(t_mtx const vec)
{
	t_mtx	translation;

	translation = mtx_identity(4);
	translation.mtx[0 * 4 + 3] = vec.mtx[0];
	translation.mtx[1 * 4 + 3] = vec.mtx[1];
	translation.mtx[2 * 4 + 3] = vec.mtx[2];
	return (translation);
}
