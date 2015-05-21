#include "rtv1.h"

t_atom	atom_new(void)
{
	t_atom	new;

	ft_bzero(&new, sizeof(new));
	new.scale = vtx_new(1, 1, 1, 1);
	new.rotation = vtx_new(0, 0, 0, 1);
	new.translation = vtx_new(0, 0, 0, 1);
	new.intensity = 1;
	return (new);
}
