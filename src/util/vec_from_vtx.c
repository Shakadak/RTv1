#include "rtv1.h"

t_vec	vec_from_vtx(t_vtx const origin, t_vtx const destination)
{
	t_vec	vec;

	vec.x = destination.x * origin.w - origin.x * destination.w;
	vec.y = destination.y * origin.w - origin.y * destination.w;
	vec.z = destination.z * origin.w - origin.z * destination.w;
	vec.w = destination.w * origin.w;
	return (vec);
}
