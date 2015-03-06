#include "rtv1.h"

t_vec	vec_add(t_vec const lh, t_vec const rh)
{
	t_vec	sum;

	sum.x = lh.x * rh.w + rh.x * lh.w;
	sum.y = lh.y * rh.w + rh.y * lh.w;
	sum.z = lh.z * rh.w + rh.z * lh.w;
	sum.w = lh.w * rh.w;
	return (sum);
}
