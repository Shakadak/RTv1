#include <math.h>
#include "rtv1.h"

t_ray	new_ray(t_camera const camera,
		t_pos const pos,
		t_pos const dim)
{
	t_ray			ray;
	t_vtx	on_projection;

	on_projection.x = ((double)pos.x + 0.5) / (double)dim.x;
	on_projection.y = ((double)pos.y + 0.5) / (double)dim.y;
	on_projection.x = (2 * on_projection.x - 1) * (double)dim.x / (double)dim.y;
	on_projection.y = 1 - 2 * on_projection.y;
	on_projection.x *= tan(camera.fov / 2.0);
	on_projection.z = -1;
	ray.direction = vec_from_vtx(vtx_from_coordinates(0, 0, 0), on_projection);
	return (ray);
}
