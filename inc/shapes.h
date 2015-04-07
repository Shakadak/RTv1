#ifndef SHAPES_H
# define SHAPES_H

# include "rtv1.h"

typedef struct	s_camera
{
	double		fov;
	t_pos		screen;
	t_mtx		dir;
	t_mtx		pos;
}				t_camera;

typedef struct	s_ray
{
	t_mtx		pos;
	t_mtx		dir;
}				t_ray;

typedef t_ray	t_light;

typedef struct	s_object
{
	int			defined;
	t_mtx		quadric;
	t_color		rgb;
	t_pipe		pipe;
}				t_object;

t_object		new_cone(
		t_mtx const scale,
		t_mtx const rotate,
		t_mtx const translate,
		t_color const color);
t_object		new_cylinder(t_mtx const scale,
		t_mtx const rotate,
		t_mtx const translate,
		t_color const color);
t_object		new_sphere(
		t_mtx const scale,
		t_mtx const rotate,
		t_mtx const translate,
		t_color const color);
t_object		new_plane(
		t_mtx const scale,
		t_mtx const rotate,
		t_mtx const translate,
		t_color const color);
t_camera		new_camera(
		t_mtx const pos,
		t_mtx const direction,
		t_pos const screen);
t_ray			new_ray(t_camera const camera,
		t_pos const pos);
t_color	ray_cast(t_pos const pos,
		t_camera const camera,
		t_object const * objects,
		t_light const * lights);
double			intersec_quadric(t_object const object, t_ray const ray);
t_ray			ray_transform(t_ray const ray, t_pipe const pipe);

#endif
