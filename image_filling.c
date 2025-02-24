#include "fractol.h"

void	image_filling(char set, char *str1, char *str2, t_fractol *fractol) // M or J and str
{
	fractol->c = set; // which is M or J
	if (!str1) // it mean if it is Mandelbrot or JULIA without any number
	{
		fractol->r_and_i.real = 0;
		fractol->r_and_i.imag = 0;
	}
	else
	{
		fractol->r_and_i.real = ft_atof(str1);
		fractol->r_and_i.imag = ft_atof(str2);
	}
	if (set == 'M')
		run_mandelbrot(fractol);
	else if (set == 'J')
		run_julia(fractol);
}