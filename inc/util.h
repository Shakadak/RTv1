#ifndef UTIL_H
# define UTIL_H

# include "rtv1.h"

#define SQR(x) ((x) * (x))

typedef struct		s_vtx
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vtx;

typedef t_vtx		t_vec;
typedef t_vec		t_rot;

typedef struct	s_mtx
{
	double	m[4][4];
}				t_mtx;

typedef struct	s_pipe
{
	t_mtx	t_pos;
	t_mtx	i_pos;
	t_mtx	i_dir;
}				t_pipe;

double			mtx_determinant(t_mtx const mtx);
t_mtx			mtx_identity(void);
t_mtx			mtx_mult(t_mtx const lh, t_mtx const rh);
t_mtx			mtx_rotateX(double const angle);
t_mtx			mtx_rotateY(double const angle);
t_mtx			mtx_rotateZ(double const angle);
t_mtx			mtx_scale(double const x, double const y, double const z);
t_mtx			mtx_translate(t_vec const vec);
t_mtx			mtx_transpose(t_mtx const mtx);
t_vec			mtx_vec_mult(t_vec const lh, t_mtx const rh);
t_vtx			mtx_vtx_mult(t_vtx const lh, t_mtx const rh);
double			solve_quadratic(double const a, double const b, double const c);
t_pipe			transform_pipeline(t_vtx const scale,
		t_rot const rotate,
		t_vec const translate);
t_vec			vec_from_vtx(t_vtx const origin, t_vtx const destination);
t_vec			vec_sub(t_vec const lh, t_vec const rh);
t_vec			vec_add(t_vec const lh, t_vec const rh);
double			vec_dot(t_vec const lh, t_vec const rh);
t_vec			vec_cross(t_vec const lh, t_vec const rh);
t_vec			vec_normalize(t_vec const vec);
double			vec_magnitude(t_vec const vec);
t_vtx			vtx_new(double const x,
		double const y,
		double const z,
		double const w);
t_vtx			vtx_homogenize(t_vtx const vtx);

#endif
