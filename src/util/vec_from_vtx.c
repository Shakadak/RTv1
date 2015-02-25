#include "rtv1.h"

t_vec	vec_from_vtx(t_vtx const origin, t_vtx const destination)
{
	t_vec	vec;

	vec.x = destination.x - origin.x;
	vec.y = destination.y - origin.y;
	vec.z = destination.z - origin.z;
	return (vec);
}
