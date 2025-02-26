/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:22:02 by hvahib            #+#    #+#             */
/*   Updated: 2025/02/26 23:41:20 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_inside_mandelbrot(int i, int j, t_fractol *fractol)
{
	t_complex	zi;
	double		temp;
	int			iter;

	zi.real = 0;
	zi.img = 0;
	iter = 0;
	while ((zi.real * zi.real) + (zi.img * zi.img) <= 2 * 2 && \
			iter < fractol->max_iteration)
	{
		temp = (zi.real * zi.real) - (zi.img * zi.img) + fractol->x0;
		zi.img = (2 * zi.real * zi.img) + fractol->y0;
		zi.real = temp;
		iter++;
	}
	if (iter == fractol->max_iteration)
		return (1);
	else
		painting(iter, i, j, fractol);
	return (0);
}

void	run_mandelbrot(t_fractol *fractol)
{
	int		res;
	int		i;
	int		j;

	i = 0;
	while (i < MAX_LENGTH)
	{
		j = 0;
		while (j < MAX_WIDTH)
		{
			fractol->x0 = ((double)i / MAX_LENGTH * 4.0 - 2.0) * fractol->zoom;
			fractol->y0 = ((double)j / MAX_WIDTH * 4.0 - 2.0) * fractol->zoom;
			res = is_inside_mandelbrot(i, j, fractol);
			if (res == 1)
				mlx_put_pixel(fractol->image, i, j, \
				pixel_color(79, 133, 154, 200));
			j++;
		}
		i++;
	}
}
