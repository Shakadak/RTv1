#include "rtv1.h"

t_mtx	mtx_scale(double const x, double const y, double const z)
{
	t_mtx	scale;

	scale = mtx_identity();
	scale[0][0] = x;
	scale[1][1] = y;
	scale[2][2] = z;
	return (scale);
}
