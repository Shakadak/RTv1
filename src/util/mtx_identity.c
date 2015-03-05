#include "rtv1.h"

t_mtx	mtx_identity(void)
{
	t_mtx	id;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
			{
				id[i][j] = 1;
			}
			else
			{
				id[i][j] = 0;
			}
		}
	}
	return [id];
}
