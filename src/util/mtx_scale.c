#include "rtv1.h"

t_mtx	mtx_scale(double const x, double const y, double const z)
{
	t_mtx	scale;

	scale = mtx_identity();
	scale.m[0][0] = x;
	scale.m[1][1] = y;
	scale.m[2][2] = z;
	return (scale);
}
