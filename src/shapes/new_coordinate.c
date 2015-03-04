#include "rtv1.h"

t_vtx	new_vtx(double const x, double const y, double const z)
{
	t_vtx	vtx;

	vtx.x = x;
	vtx.y = y;
	vtx.z = z;
	return (vtx);
}
