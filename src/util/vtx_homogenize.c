#include "rtv1.h"

t_vtx	vtx_homogenize(t_vtx const vtx)
{
	t_vtx	homogenized;

	if (vtx.w != 1)
	{
		homogenized.x = vtx.x / vtx.w;
		homogenized.y = vtx.y / vtx.w;
		homogenized.z = vtx.z / vtx.w;
		homogenized.w = vtx.w / vtx.w;
		return (homogenized);
	}
	else
		return (vtx);
}
