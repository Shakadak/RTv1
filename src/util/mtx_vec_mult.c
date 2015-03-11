#include "rtv1.h"

t_vec	mtx_vec_mult(t_vec const lh, t_mtx const rh)
{
	t_vec	new;

	new.x = lh.x * rh.m[0][0] + lh.y * rh.m[0][1] + lh.z * rh.m[0][2];
	new.y = lh.x * rh.m[1][0] + lh.y * rh.m[1][1] + lh.z * rh.m[1][2];
	new.z = lh.x * rh.m[2][0] + lh.y * rh.m[2][1] + lh.z * rh.m[2][2];
	new.w = lh.x * rh.m[3][0] + lh.y * rh.m[3][1] + lh.z * rh.m[3][2];
	return (new);
}
