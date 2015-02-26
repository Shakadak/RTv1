#ifndef UTIL_H
# define UTIL_H

# include "rtv1.h"

double	solve_quadratic(double const a, double const b, double const c);
t_vtx	vtx_from_coordinates(double const x, double const y, double const z);
t_vec	vec_from_vtx(t_vtx const origin, t_vtx const destination);
t_vec	vec_sub(t_vec const lh, t_vec const rh);
double	vec_dot(t_vec const lh, t_vec const rh);
t_vec	vec_normalize(t_vec const vec);
double	vec_magnitude(t_vec const vec);

#endif
