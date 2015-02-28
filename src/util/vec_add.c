#include "rtv1.h"

t_vec	vec_add(t_vec const lh, t_vec const rh)
{
	t_vec	sum;

	sum.x = lh.x + rh.x;
	sum.y = lh.y + rh.y;
	sum.z = lh.z + rh.z;
	return (sum);
}
