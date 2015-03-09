#include "rtv1.h"

double	mtx_determinant(t_mtx const mtx)
{
	return ((mtx.m[0][0] * mtx.m[1][1] * mtx.m[2][2] * mtx.m[3][3]
				+ mtx.m[0][1] * mtx.m[1][2] * mtx.m[2][3] * mtx.m[3][0]
				+ mtx.m[0][2] * mtx.m[1][3] * mtx.m[2][0] * mtx.m[3][1]
				+ mtx.m[0][3] * mtx.m[1][0] * mtx.m[2][1] * mtx.m[3][2])
			- (mtx.m[0][3] * mtx.m[1][2] * mtx.m[2][1] * mtx.m[3][0]
				+ mtx.m[0][0] * mtx.m[1][3] * mtx.m[2][2] * mtx.m[3][1]
				+ mtx.m[0][1] * mtx.m[1][0] * mtx.m[2][3] * mtx.m[3][2]
				+ mtx.m[0][2] * mtx.m[1][1] * mtx.m[2][0] * mtx.m[3][3]));
}
