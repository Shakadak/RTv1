#include "rtv1.h"

t_light	new_light(t_mtx const coordinate)
{
	t_light	new;

	new.defined = 1;
	new.pos = coordinate;
	return (new);
}
