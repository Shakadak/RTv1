#ifndef SHAPES_H
# define SHAPES_H

# include "rtv1.h"

typedef enum		e_kind
{
	CAMERA,
	SPHERE,
	PLANE,
	CONE,
	CYLINDER,
	TOTAL
}					t_kind;

typedef struct		s_vtx
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vtx;

typedef t_vtx		t_vec;
typedef t_vec		t_rot;

typedef struct		s_sphere
{
	double			radius;
}					t_sphere;

typedef struct		s_plane
{
	int				cc;
}					t_plane;

typedef struct		s_camera
{
	double			fov;
	t_vtx			direction;
	t_vtx			origin;
}					t_camera;

typedef struct		s_cone
{
	int				cc;
}					t_cone;

typedef struct		s_cylinder
{
	double			radius;
	t_vec			dir;
}					t_cylinder;

typedef union		u_shape
{
	t_camera		camera;
	t_sphere		sphere;
	t_plane			plane;
	t_cone			cone;
	t_cylinder		cylinder;
}					t_shape;

typedef struct		s_ray
{
	t_vtx			pos;
	t_vtx			dir;
}					t_ray;

typedef struct		s_object
{
	t_kind			kind;
	t_shape			shape;
	t_vtx			pos;
	t_color			rgb;
	double			(*intersec)(t_ray const ray);
}					t_object;

t_object			new_sphere(
		t_vtx const pos,
		t_color const color,
		double const radius);
t_object	new_cylinder(t_vtx const pos,
		t_color const color,
		t_vec const dir,
		double radius);
t_vtx				new_vtx(
		double const x,
		double const y,
		double const z);
t_object			new_camera(
		t_vtx const pos,
		t_vtx const direction);
double	intersec_sphere(t_ray const ray);
double	intersec_cylinder(t_ray const ray);
t_ray	new_ray(t_camera const camera,
		t_pos const pos,
		t_pos const dim);

#endif
