#include "rtv1.h"

double	vec_dot(t_vec const lh, t_vec const rh)
{
	return (lh.x * rh.x + lh.y * rh.y + lh.z * rh.z);
}
