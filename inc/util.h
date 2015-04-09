#ifndef UTIL_H
# define UTIL_H

# include "rtv1.h"

# define SQR(x) ((x) * (x))
# define EPSILON 0.00000001

typedef struct	s_pipe
{
	t_mtx	scale;
	t_mtx	rotateX;
	t_mtx	rotateY;
	t_mtx	rotateZ;
	t_mtx	rotate
	t_mtx	translate;
	t_mtx	i_scale;
	t_mtx	i_rotateX;
	t_mtx	i_rotateY;
	t_mtx	i_rotateZ;
	t_mtx	i_rotate;
	t_mtx	i_translate;
	t_mtx	t_pos;
	t_mtx	t_normal;
	t_mtx	i_pos;
	t_mtx	i_dir;
}				t_pipe;

double			mtx_determinant(t_mtx const mtx);
t_mtx			mtx_rotateX(double const angle);
t_mtx			mtx_rotateY(double const angle);
t_mtx			mtx_rotateZ(double const angle);
t_mtx			mtx_scale(double const x, double const y, double const z);
t_mtx			mtx_translate(t_mtx const vec);
double			solve_quadratic(double const a, double const b, double const c);
t_pipe			transform_pipeline(t_mtx const scale,
		t_mtx const rotate,
		t_mtx const translate);
t_mtx			vec_from_vtx(t_mtx const origin, t_mtx const destination);
t_mtx			vec_cross(t_mtx const lh, t_mtx const rh);
t_mtx			vec_normalize(t_mtx const vec);
double			vec_magnitude(t_mtx const vec);
t_mtx	vec_new(double const x, double const y, double const z);
t_mtx			vtx_new(double const x,
		double const y,
		double const z,
		double const w);
t_mtx			vtx_homogenize(t_mtx const vtx);

#endif
