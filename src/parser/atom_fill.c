#include "rtv1.h"

static t_atom	(*get_fill(char const *const src))(t_atom, char const *const *const, int *)
{
	(void)src;
	return (fill_type);
}

t_atom	atom_fill(char const *const *const array)
{
	int		i;
	t_atom	atom;
	t_atom	(*fill)(t_atom, char const *const *const, int *);

	i = 0;
	atom = atom_new();
	while (array[i] != NULL)
	{
		if ((fill = get_fill(array[i])) != NULL)
			atom = fill(atom, array, &i);
		else
			ft_fatal("Error while parsing", 0);
	}
	return (atom);
}
