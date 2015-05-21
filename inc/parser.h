#ifndef PARSER_H
# define PARSER_H

# include "libmtx.h"
# include "libumlx.h"

typedef enum	e_type
{
	UNKNOWN,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CONE,
	CYLINDER,
	QUADRIC,
	TOTAL
}				t_type;

typedef struct	s_atom
{
	t_type		type;
	t_mtx		scale;
	t_mtx		rotation;
	t_mtx		translation;
	t_color		color;
}				t_atom;

t_atom	atom_new(void);
t_atom			fill_type(t_atom atom, char const * const * const array, int *i);

#endif
