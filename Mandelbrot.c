#include "fractol.h"

static int	is_inside_mandelbrot(int i, int j, t_fractol *fractol)
{
	t_complex	zi;
	double		temp;
	int			iter;

	zi.real = 0;
	zi.imag = 0;
	iter = 0;
	while ((zi.real * zi.real) + (zi.imag * zi.imag) <= 2 * 2 && \
			iter < fractol->max_iteration) // CANT UNDERSTAND !!!!
	{
		temp = (zi.real * zi.real) - (zi.imag * zi.imag) + fractol->x0;
		zi.imag = 2 * zi.real * zi.imag + fractol->y0;
		zi.real = temp;
		iter++;
	}
	if (iter == fractol->max_iteration)
		return (1);
	else
		outside_painting(iter, i, j, fractol);
	return (0);
}

void	run_mandelbrot(t_fractol *fractol)
{
	int		res;
	int		i;
	int		j;

	i = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 1080)
		{
			fractol->x0 = ((double)i / 1080.0 * 4.0 - 2.0) * fractol->zoom; //creating the range from -2 to 2
			fractol->y0 = ((double)j / 1080.0 * 4.0 - 2.0) * fractol->zoom;
		res = is_inside_mandelbrot(i, j, fractol);
			if (res == 1)
				mlx_put_pixel(fractol->image, i, j, \
				pixel_color(254, 175, 160, 200));
			j++;
		}
		i++;
	}
}