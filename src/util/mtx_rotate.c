#include <math.h>
#include "rtv1.h"

t_mtx	mtx_rotateX(double const angle)
{
	t_mtx	rotation;

	rotation = mtx_identity();
	rotation[1][1] = cos(angle);
	rotation[1][2] = -sin(angle);
	rotation[2][1] = sin(angle);
	rotation[2][2] = cos(angle);
	return (rotation);
}

t_mtx	mtx_rotateY(double const angle)
{
	t_mtx	rotation;

	rotation = mtx_identity();
	rotation[0][0] = cos(angle);
	rotation[0][2] = sin(angle);
	rotation[2][0] = -sin(angle);
	rotation[2][2] = cos(angle);
	return (rotation);
}

t_mtx	mtx_rotateZ(double const angle)
{
	t_mtx	rotation;

	rotation = mtx_identity();
	rotation[0][0] = cos(angle);
	rotation[0][1] = -sin(angle);
	rotation[1][0] = sin(angle);
	rotation[1][1] = cos(angle);
	return (rotation);
}
