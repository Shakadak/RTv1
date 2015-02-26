#include "rtv1.h"
#include <math.h>

t_object	new_camera(t_vtx const pos, t_vtx const direction)
{
	t_object	camera;

	camera.kind = CAMERA;
	camera.shape.camera.direction = direction;
	camera.shape.camera.fov = 90 * M_PI / 180;
	camera.pos = pos;
	return (camera);
}
