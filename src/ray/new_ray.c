#include <math.h>
#include <stdio.h>/////////////
#include "rtv1.h"

t_ray	new_ray(t_camera const camera,
		t_pos const pos)
{
	t_ray	ray;
	t_vtx	on_projection;

	on_projection.x = ((double)pos.x + 0.5) / (double)camera.screen.x;
	on_projection.y = ((double)pos.y + 0.5) / (double)camera.screen.y;
	on_projection.x = (2 * on_projection.x - 1) * (double)camera.screen.x / (double)camera.screen.y;
	on_projection.y = 1 - 2 * on_projection.y;
	on_projection.x *= tan(camera.fov / 2.0);
	on_projection.z = -1;
	on_projection.w = 1;
	ray.dir = vec_from_vtx(vtx_new(0, 0, 0, 1), on_projection);
	ray.dir = vec_normalize(ray.dir);
	ray.pos = camera.pos;
	return (ray);
}
