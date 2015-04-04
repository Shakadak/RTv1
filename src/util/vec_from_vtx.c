#include "rtv1.h"

t_mtx	vec_from_vtx(t_mtx const origin, t_mtx const destination)
{
	return (mtx_sub(destination, origin));
}
