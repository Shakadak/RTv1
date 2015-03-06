#include "rtv1.h"

t_vec	vec_homogenize(t_vec const vec)
{
	t_vec	homogenized;

	homogenized.x = vec.x / vec.w;
	homogenized.y = vec.y / vec.w;
	homogenized.z = vec.z / vec.w;
	homogenized.w = vec.w / vec.w;
	return (homogenized);
}
