#include "rtv1.h"
#include <math.h>

t_camera	new_camera(t_mtx const pos, t_mtx const dir, t_pos const dim)
{
	t_camera	camera;

	camera.dir = mtx_dup(dir);
	camera.fov = 90 * M_PI / 180;
	camera.pos = mtx_dup(pos);
	camera.screen = dim;
	return (camera);
}
