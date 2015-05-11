#include "rtv1.h"
#include "stdio.h"//////////////

static int	obstructed(t_object const *olist, t_ray const ray)
{
	double		d;

	while (olist->defined)
	{
		d = intersec_quadric(*olist, ray_transform(ray, olist->pipe));
		printf("d = %f, ray.magnitude = %f\n", d, vec_magnitude(ray.dir));
		if (0 + EPSILON < d && d < vec_magnitude(ray.dir) - EPSILON)
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

	normal = ray_normal(obj, ray, dist);
	while (lights->defined)
	{
		printf("normal.pos [%f,%f,%f] : light.pos [%f,%f,%f]\n", normal.pos.mtx[0],
				normal.pos.mtx[1],
				normal.pos.mtx[2],
				l_ray.pos.mtx[0],
				l_ray.pos.mtx[1],
				l_ray.pos.mtx[2]);
		l_ray.dir = mtx_sub(lights->pos, normal.pos);
		dot = vec_dot(normal.dir, vec_normalize(l_ray.dir))/* / (vec_magnitude(normal.dir) * vec_magnitude(l_ray.dir))*/;
		printf("normal.dir [%f,%.19f,%f] : light.dir [%f,%f,%f]\n", normal.dir.mtx[0],
				normal.dir.mtx[1],
				normal.dir.mtx[2],
				l_ray.dir.mtx[0],
				l_ray.dir.mtx[1],
				l_ray.dir.mtx[2]);
		if (!(dot <= 1 + EPSILON && dot >= 0 - EPSILON))
		{
			printf("dot = %f\n", dot);
			ft_putendl_fd("antidot", 2);
			++lights;
			obj.rgb.rgb[0] /= 9;
			obj.rgb.rgb[1] /= 9;
			obj.rgb.rgb[2] /= 9;
			obj.rgb.rgb[3] /= 9;
			continue;
		}
		obj.rgb.rgb[0] *= dot;
		obj.rgb.rgb[1] *= dot;
		obj.rgb.rgb[2] *= dot;
		obj.rgb.rgb[3] *= dot;
		l_ray.pos = normal.pos;
		if (obstructed(olist, l_ray))
		{
			ft_putendl_fd("obstructed", 2);
			obj.rgb.rgb[0] /= 2;
			obj.rgb.rgb[1] /= 2;
			obj.rgb.rgb[2] /= 2;
			obj.rgb.rgb[3] /= 2;
		}
		++lights;
	}
	return (obj.rgb);
}
