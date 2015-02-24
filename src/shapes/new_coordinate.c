#include "rtv1.h"

t_vtx	new_vtx(double const x, double const y, double const z)
{
	t_vtx	pos;

	pos.x = x;
	pos.y = y;
	pos.z = z;
	return (pos);
}
