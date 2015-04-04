#include "rtv1.h"

t_mtx	vec_normalize(t_mtx const vec)
{
	t_mtx	normed;
	double	magnitude;

	magnitude = vec_magnitude(vec);
	normed = vec_new(vec.mtx[0] / magnitude,
			vec.mtx[1] / magnitude,
			vec.mtx[2] / magnitude);
	return (normed);
}
