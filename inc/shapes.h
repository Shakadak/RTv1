#ifndef SHAPES_H
# define SHAPES_H

# include "rtv1.h"

typedef enum	e_kind
{
	CAMERA,
	SPHERE,
	PLANE,
	CONE,
	CYLINDER,
	TOTAL
}				t_kind;

typedef struct	s_camera
{
	double		fov;
	t_pos		screen;
	t_vtx		dir;
	t_vtx		pos;
}				t_camera;

typedef struct	s_ray
{
	t_vtx		pos;
	t_vtx		dir;
}				t_ray;

typedef t_ray	t_light;

typedef struct	s_object
{
	int			defined;
	t_kind		kind;
	t_color		rgb;
	t_pipe		pipe;
	double		(*intersec)(t_ray const ray);
}				t_object;

t_object		new_cone(
		t_vtx const scale,
		t_rot const rotate,
		t_vec const translate,
		t_color const color);
t_object		new_cylinder(t_vtx const scale,
		t_rot const rotate,
		t_vec const translate,
		t_color const color);
t_object		new_sphere(
		t_vtx const scale,
		t_rot const rotate,
		t_vec const translate,
		t_color const color);
t_object		new_plane(
		t_vtx const scale,
		t_rot const rotate,
		t_vec const translate,
		t_color const color);
t_camera		new_camera(
		t_vtx const pos,
		t_vtx const direction,
		t_pos const screen);
t_ray			new_ray(t_camera const camera,
		t_pos const pos);
t_color	ray_cast(t_pos const pos,
		t_camera const camera,
		t_object const * objects,
		t_light const * lights);
double			intersec_cone(t_ray const ray);
double			intersec_cylinder(t_ray const ray);
double			intersec_sphere(t_ray const ray);
double			intersec_plane(t_ray const ray);
t_ray			ray_transform(t_ray const ray, t_pipe const pipe);

#endif
