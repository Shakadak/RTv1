#include "rtv1.h"

t_vtx	vtx_transform(t_vtx const lh, t_mtx const rh)
{
	t_vtx	new;

	new.x = vtx.x * rh[0][0] + vtx.y * rh[0][1] + vtx.z * rh[0][2] + rh[0][3];
	new.y = vtx.x * rh[1][0] + vtx.y * rh[1][1] + vtx.z * rh[1][2] + rh[1][3];
	new.z = vtx.x * rh[2][0] + vtx.y * rh[2][1] + vtx.z * rh[2][2] + rh[2][3];
	new.w = vtx.x * rh[3][0] + vtx.y * rh[3][1] + vtx.z * rh[3][2] + rh[3][3];
	return (vtx_homogenize(new));
}
