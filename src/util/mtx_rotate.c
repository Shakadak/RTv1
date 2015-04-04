#include <math.h>
#include "rtv1.h"

t_mtx	mtx_rotateX(double const angle)
{
	t_mtx	rotation;

	rotation = mtx_identity(4);
	rotation.mtx[1 * 4 + 1] = cos(angle);
	rotation.mtx[1 * 4 + 2] = -sin(angle);
	rotation.mtx[2 * 4 + 1] = sin(angle);
	rotation.mtx[2 * 4 + 2] = cos(angle);
	return (rotation);
}

t_mtx	mtx_rotateY(double const angle)
{
	t_mtx	rotation;

	rotation = mtx_identity(4);
	rotation.mtx[0 * 4 + 0] = cos(angle);
	rotation.mtx[0 * 4 + 2] = sin(angle);
	rotation.mtx[2 * 4 + 0] = -sin(angle);
	rotation.mtx[2 * 4 + 2] = cos(angle);
	return (rotation);
}

t_mtx	mtx_rotateZ(double const angle)
{
	t_mtx	rotation;

	rotation = mtx_identity(4);
	rotation.mtx[0 * 4 + 0] = cos(angle);
	rotation.mtx[0 * 4 + 1] = -sin(angle);
	rotation.mtx[1 * 4 + 0] = sin(angle);
	rotation.mtx[1 * 4 + 1] = cos(angle);
	return (rotation);
}
