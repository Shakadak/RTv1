#include "rtv1.h"

t_ray	new_ray(t_camera const camera)
{
	t_ray	ray;

	ray.origin = camera.origin;
	return (ray);
}
