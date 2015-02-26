#include <math.h>
#include "rtv1.h"

double	vec_magnitude(t_vec const vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}
