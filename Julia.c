#include "fractol.h"

double	is_inside_julia(int i, int j, t_fractol *params)
{
	double	temp;
	int		iter;

	params->y0 = -(params->y0);
	iter = 0;
	while ((params->x0 * params->x0) + (params->y0 * params->y0) <= 4 && \
	        iter < params->max_iteration) // CANT UNDERSTAND
	{
		temp = params->x0 * params->x0 - params->y0 * params->y0;
		params->y0 = 2 * params->x0 * params->y0 + params->r_and_i.imag;
		params->x0 = temp + params->r_and_i.real;
		iter++;
	}
	if (iter == params->max_iteration)
		return (1);
	else
		inside_painting(iter, i, j, params);
	return (0);
}

void	run_julia(t_fractol *params)
{
	double		res;
	int			i;
	int			j;

	i = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 1080)
		{
			params->x0 = ((double)i / 1080.0 * 4.0 - 2.0) * params->zoom;
			params->y0 = ((double)j / 1080.0 * 4.0 - 2.0) * params->zoom;
			res = is_inside_julia(i, j, params);
			if (res != 0)
				inside_painting(res, i, j, params);
			j++;
		}
		i++;
	}
}