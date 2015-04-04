#include <math.h>
#include "rtv1.h"

double	vec_magnitude(t_mtx const vec)
{
	return (sqrt(SQR(vec.mtx[0]) + SQR(vec.mtx[1]) + SQR(vec.mtx[2])));
}
