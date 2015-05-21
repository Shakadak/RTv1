#include "rtv1.h"

static t_atom	get_fill(t_atom atom, char const *const *const src, int *i)
{
	if (!ft_strcmp(src[*i], "CAMERA"))
		atom.type = CAMERA;
	else if (!ft_strcmp(src[*i], "LIGHT"))
		atom.type = LIGHT;
	else if (!ft_strcmp(src[*i], "CYLINDER"))
		atom.type = CYLINDRE;
	else if (!ft_strcmp(src[*i], "CONE"))
		atom.type = CONE;
	else if (!ft_strcmp(src[*i], "PLANE"))
		atom.type = PLANE;
	else if (!ft_strcmp(src[*i], "SPHERE"))
		atom.type = SPHERE;
	else if (!ft_strcmp(src[*i], "SCALE"))
		atom.scale = fill_scale(src, i);
	else if (!ft_strcmp(src[*i], "ROTATION"))
		atom.rotation = fill_rotation(src, i);
	else if (!ft_strcmp(src[*i], "TRANSLATION"))
		atom.translation = fill_translation(src, i);
	else if (!ft_strcmp(src[*i], "COLOR"))
		atom.translation = fill_color(src, i);
	else
		ft_fatal("Error while parsing file.\n", 0);
	++(*i);
	return (atom);
}

t_atom			atom_fill(char const *const *const array)
{
	int		i;
	t_atom	atom;

	i = 0;
	atom = atom_new();
	while (array[i] != NULL)
	{
		atom = get_fill(atom, array, &i);
	}
	return (atom);
}
