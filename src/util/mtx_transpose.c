#include "rtv1.h"

t_mtx	mtx_transpose(t_mtx const mtx)
{
	t_mtx	transposed;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			transposed.m[j][i] = mtx.m[i][j];
			++j;
		}
		++i;
	}
	return (transposed);
}
