#include "rtv1.h"

t_mtx	fill_transformation(char const *const *const src, int *i)
{
	if (ft_split_len(src + *i) < 4)
		ft_fatal("Error while parsing transformation.\n", 0);
	return (vtx_new(ft_atof(src[++(*i)]), ft_atof(src[++(*i)]),
	ft_atof(src[++(*i)]), 1));
}
