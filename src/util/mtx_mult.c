#include "rtv1.h"

t_mtx	mtx_mult(t_mtx const lh, t_mtx const rh)
{
	t_mtx	product;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			product.m[i][j] = lh.m[i][0] * rh.m[0][j]
				+ lh.m[i][1] * rh.m[1][j]
				+ lh.m[i][2] * rh.m[2][j]
				+ lh.m[i][3] * rh.m[3][j];
			++j;
		}
		++i;
	}
	return (product);
}
