#include "rtv1.h"

t_light	new_light(t_mtx const coordinate, double const intensity)
{
	t_light	new;

	new.defined = 1;
	new.pos = coordinate;
	new.intensity = intensity;
	return (new);
}
