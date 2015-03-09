#include "rtv1.h"
#include <math.h>

t_camera	new_camera(t_vtx const pos, t_vtx const dir)
{
	t_camera	camera;

	camera.dir = direction;
	camera.fov = 90 * M_PI / 180;
	camera.pos = pos;
	return (camera);
}
