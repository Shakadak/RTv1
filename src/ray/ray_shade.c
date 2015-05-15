#include "rtv1.h"
#include "stdio.h"//////////////

static int	obstructed(t_object const *olist, t_ray const ray)
{
	double		d;

	while (olist->defined)
	{
		d = intersec_quadric(*olist, ray);
		if (0.0 < d && d <= 1)
			return (1);
		++olist;
	}
	return (0);
}

t_color	ray_shade(t_object obj,
		t_ray const ray,
		double const dist,
		t_object const *olist,
		t_light const *lights)
{
	t_ray		normal;
	t_ray		l_ray;
	double		dot;
	double		expo;

	expo = 0.9;
	normal = ray_normal(obj, ray, dist);
	while (lights->defined)
	{
		l_ray.dir = mtx_sub(lights->pos, normal.pos);
		dot = vec_dot(normal.dir, vec_normalize(l_ray.dir));
		if (!(0.0 < dot && dot <= 1.0))
		{
			++lights;
			continue;
		}
		l_ray.pos = normal.pos;
		if (!obstructed(olist, l_ray))
		{
			expo *= (1 - dot);
		}
		++lights;
	}
	expo = 1 - expo;
	/*printf("\tExposition:\t%f\n", expo);*/
	obj.rgb.rgb[0] = expo * obj.rgb.rgb[0] > 0xFF ? 255 : expo * obj.rgb.rgb[0];
	obj.rgb.rgb[1] = expo * obj.rgb.rgb[1] > 0xFF ? 255 : expo * obj.rgb.rgb[1];
	obj.rgb.rgb[2] = expo * obj.rgb.rgb[2] > 0xFF ? 255 : expo * obj.rgb.rgb[2];
	return (obj.rgb);
}
