#include "rtv1.h"
#include "stdio.h"

t_color	ray_shade(t_object const obj,
		t_ray const ray,
		double const dist,
		t_object *objects,
		t_light const *lights)
{
	t_ray		normal;
	t_ray		l_ray;
	t_object	*t_obj;
	double		d;
	double		dot;

	normal = ray_normal(obj, ray, dist);
	while (lights->defined)
	{
		l_ray.dir = mtx_sub(lights->pos, normal.pos);
		printf("normal\t[%f, %f, %f, %f]\nlight\t[%f, %f, %f, %f]\n", normal.pos.mtx[0], normal.pos.mtx[1], normal.pos.mtx[2], normal.pos.mtx[3], l_ray.dir.mtx[0], l_ray.dir.mtx[1], l_ray.dir.mtx[2], l_ray.dir.mtx[3]);
		dot = vec_dot(normal.dir, l_ray.dir) / (vec_magnitude(normal.dir) * vec_magnitude(l_ray.dir));
		printf("%f, dis is sum num\n", dot);
		if (dot >= 1 || dot < 0)
		{
			ft_putstr_fd("out of bound ?\n", 2);
			++lights;
			continue;
		}
		t_obj = objects;
		l_ray.pos = normal.pos;
			ft_putstr_fd("ongoibg;\n", 2);
			printf("%d t_obj->defined\n", t_obj->defined);
		while (t_obj->defined)
		{
			ft_putstr_fd("t_obj ongoibg;\n", 2);
			d = intersec_quadric(*t_obj, l_ray);
			if (0 - EPSILON < d|| d < 1 + EPSILON)
			{
				ft_putstr_fd("shadow t_obj;\n", 2);
				break;
			}
			ft_putstr_fd("++t_obj;\n", 2);
			++t_obj;
		}
		++lights;
	}
	return (obj.rgb);
}
