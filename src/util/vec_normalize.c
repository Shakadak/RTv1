#include "rtv1.h"

t_vec	vec_normalize(t_vec const vec)
{
	t_vec	normed;
	double	magnitude;

	magnitude = vec_magnitude(vec);
	normed.x = vec.x / magnitude;
	normed.y = vec.y / magnitude;
	normed.z = vec.z / magnitude;
	return (normed);
}
