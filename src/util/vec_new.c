#include "rtv1.h"

t_mtx	vec_new(double const x, double const y, double const z)
{
	t_mtx	vec;

	vec = mtx_new(4, 1);
	vec.mtx[0] = x;
	vec.mtx[1] = y;
	vec.mtx[2] = z;
	return (vec);
}
