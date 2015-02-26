#include <math.h>

double	solve_quadratic(double const a, double const b, double const c)
{
	double	delta;
	double	x0;
	double	x1;
	double	q;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (-1);
	else if (delta == 0)
	{
		x0 = -0.5 * b / a;
		x1 = x0;
	}
	else
	{
		q = (b > 0) ? -0.5 * (b + sqrt(delta)) : -0.5 * (b - sqrt(delta));
		x0 = q / a;
		x1 = c / q;
	}
	if (x0 < x1 && x0 > 0.0)
		return (x0);
	else if (x1 < x0 && x1 > 0.0)
		return (x1);
	return (-1);
}
