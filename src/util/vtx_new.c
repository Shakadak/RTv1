#include "rtv1.h"

t_vtx	vtx_new(double const x, double const y, double const z, double const w)
{
	t_vtx	vtx;

	vtx.x = x;
	vtx.y = y;
	vtx.z = z;
	vtx.w = w;
	return (vtx);
}
