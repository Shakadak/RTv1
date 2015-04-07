#include <math.h>
#include "rtv1.h"

t_ray	new_ray(t_camera const camera,
		t_pos const pos)
{
	t_ray	ray;
	t_mtx	tmp;
	double	x;
	double	y;
	double	z;

	x = ((double)pos.x + 0.5) / (double)camera.screen.x;
	y = ((double)pos.y + 0.5) / (double)camera.screen.y;
	x = (2 * x - 1) * (double)camera.screen.x / (double)camera.screen.y;
	y = 1 - 2 * y;
	x *= tan(camera.fov / 2.0);
	z = -1;
	tmp = vec_new(x, y, z);
	ray.dir = vec_normalize(tmp);
	mtx_free(tmp);
	ray.pos = camera.pos;
	return (ray);
}
