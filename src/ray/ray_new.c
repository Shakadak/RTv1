#include <math.h>
#include "rtv1.h"

t_ray	ray_new(t_camera const camera,
		t_pos const pos)
{
	t_ray	ray;
	double	x;
	double	y;
	double	z;

	x = ((double)pos.x + 0.5) / (double)camera.screen.x;
	y = ((double)pos.y + 0.5) / (double)camera.screen.y;
	x = (2 * x - 1) * (double)camera.screen.x / (double)camera.screen.y;
	y = 1 - 2 * y;
	x *= tan(camera.fov / 2.0);
	z = -1;
	ray.dir = vec_normalize(vec_new(x, y, z));
	ray.pos = vtx_new(0, 0, 0 ,1);
	ray = ray_transform(ray, camera.transform);
	return (ray);
}
