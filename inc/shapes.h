#ifndef SHAPES_H
# define SHAPES_H

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
}					t_vtx;

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
	int				cc;
}					t_cylinder;

typedef union		u_shape
{
	t_camera		camera;
	t_sphere		sphere;
	t_plane			plane;
	t_cone			cone;
	t_cylinder		cylinder;
}					t_shape;

typedef struct		s_object
{
	t_kind			kind;
	t_shape			shape;
	t_vtx			pos;
	t_color			rgb;
}					t_object;

t_object			new_sphere(
		t_vtx const pos,
		double const radius,
		t_color const color);
t_vtx				new_vtx(
		double const x,
		double const y,
		double const z);
t_object			new_camera(
		t_vtx const pos,
		t_vtx const direction);

#endif
