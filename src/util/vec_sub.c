#include "rtv1.h"

t_vec	vec_sub(t_vec const lh, t_vec const rh)
{
	t_vec	diff;

	diff.x = lh.x * rh.w - rh.x * lh.x;
	diff.y = lh.y * rh.w - rh.y * lh.w;
	diff.z = lh.z * rh.w - rh.z * lh.w;
	diff.w = lh.w * rh.w;
	return (diff);
}
