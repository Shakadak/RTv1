#include "rtv1.h"

t_vtx	vtx_transform(t_vtx const lh, t_mtx const rh)
{
	t_vtx	new;

	new.x = lh.x * rh.m[0][0] + lh.y * rh.m[0][1] + lh.z * rh.m[0][2] + rh.m[0][3];
	new.y = lh.x * rh.m[1][0] + lh.y * rh.m[1][1] + lh.z * rh.m[1][2] + rh.m[1][3];
	new.z = lh.x * rh.m[2][0] + lh.y * rh.m[2][1] + lh.z * rh.m[2][2] + rh.m[2][3];
	new.w = lh.x * rh.m[3][0] + lh.y * rh.m[3][1] + lh.z * rh.m[3][2] + rh.m[3][3];
	return (vtx_homogenize(new));
}
