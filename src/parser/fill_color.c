#include "rtv1.h"

t_color	fill_color(char const *const *const src, int *i)
{
	if (ft_split_len(src + *i) < 4)
		ft_fatal("Error while parsing color.\n", 0);
	return (new_color(ft_atof(src[++(*i)]), ft_atof(src[++(*i)]),
	ft_atof(src[++(*i)]), 0x00));
}
