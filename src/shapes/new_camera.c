#include "rtv1.h"

t_object	new_camera(t_vtx const pos, t_vtx const direction)
{
	t_object	camera;

	camera.kind = CAMERA;
	camera.shape.camera.direction = direction;
	camera.pos = pos;
	return (camera);
}
