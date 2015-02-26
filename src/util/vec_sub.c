#include "rtv1.h"

t_vec	vec_sub(t_vec const lh, t_vec const rh)
{
	t_vec	diff;

	diff.x = lh.x - rh.x;
	diff.y = lh.y - rh.y;
	diff.z = lh.z - rh.z;
	return (diff);
}
