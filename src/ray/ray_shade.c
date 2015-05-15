#include "rtv1.h"
#include "stdio.h"//////////////

static int	obstructed(t_object const *olist, t_ray const ray)
{
	double		d;

	while (olist->defined)
	{
		d = intersec_quadric(*olist, ray);
//		printf("d = %.19f, ray.magnitude = %f\n", d, vec_magnitude(ray.dir));
		if (0.0 < d && d <= vec_magnitude(ray.dir))
		{
//			ft_putendl_fd("obstructed", 2);
			return (1);
		}
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

	(void)normal;
	(void)l_ray;
	(void)dot;
	(void)ray;
	(void)dist;
	(void)olist;
	(void)lights;
	expo = 0.8;
	normal = ray_normal(obj, ray, dist);
	while (lights->defined)
	{/*
		printf("normal.pos [%f,%f,%f] : light.pos [%f,%f,%f]\n", normal.pos.mtx[0],
				normal.pos.mtx[1],
				normal.pos.mtx[2],
				lights->pos.mtx[0],
				lights->pos.mtx[1],
				lights->pos.mtx[2]);*/
		l_ray.dir = mtx_sub(lights->pos, normal.pos);
		dot = vec_dot(normal.dir, vec_normalize(l_ray.dir));/*
		printf("normal.dir [%f,%.19f,%f] : light.dir [%f,%f,%f]\n", normal.dir.mtx[0],
				normal.dir.mtx[1],
				normal.dir.mtx[2],
				l_ray.dir.mtx[0],
				l_ray.dir.mtx[1],
				l_ray.dir.mtx[2]);
			printf("dot = %f\n", dot);*/
		if (!(0.0 < dot && dot <= 1.0))
		{
//			ft_putendl_fd("antidot", 2);
			++lights;
			continue;
		}
		l_ray.pos = normal.pos;
		if (!obstructed(olist, l_ray))
		{
			expo *= 1 - dot;
//			ft_putendl_fd("not obstructed", 2);
		}
		++lights;
	}
	expo = 1 - expo;
//	printf("\tExposition:\t%f\n", expo);
	obj.rgb.rgb[0] = expo * obj.rgb.rgb[0] > 0xFF ? 255 : expo * obj.rgb.rgb[0];
	obj.rgb.rgb[1] = expo * obj.rgb.rgb[1] > 0xFF ? 255 : expo * obj.rgb.rgb[1];
	obj.rgb.rgb[2] = expo * obj.rgb.rgb[2] > 0xFF ? 255 : expo * obj.rgb.rgb[2];
	return (obj.rgb);
}
