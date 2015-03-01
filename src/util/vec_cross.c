#include "rtv1.h"

t_vec	vec_cross(t_vec const lh, t_vec const rh)
{
	t_vec	prod;

	prod.x = lh.y * rh.z - lh.z * rh.y;
	prod.y = lh.z * rh.x - lh.x * rh.z;
	prod.z = lh.x * rh.y - lh.y * rh.x;
	return (prod);
}
