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
		while (j < 0)
		{
			product[i][j] = lh[i][0] * rh[0][j]
				+ lh[i][1] * rh[1][j]
				+ lh[i][2] * rh[2][j]
				+ lh[i][3] * rh[3][j];
			++j;
		}
		++i;
	}
	return (product);
}
