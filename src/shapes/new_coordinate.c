#include "rtv1.h"

t_coordinate	new_coordinate(double const x, double const y, double const z)
{
	t_coordinate	pos;

	pos.x = x;
	pos.y = y;
	pos.z = z;
	return (pos);
}
