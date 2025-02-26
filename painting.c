/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:22:05 by hvahib            #+#    #+#             */
/*   Updated: 2025/02/26 23:49:30 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	pixel_color(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	painting(int iter, int i, int j, t_fractol *fractol)
{
	double	ratio;
	int		r;
	int		g;
	int		b;

	ratio = (double)iter / fractol->max_iteration;
	r = (int)(9 * (1 - ratio) * ratio * ratio * ratio * 255);
	g = (int)(15 * (1 - ratio) * (1 - ratio) * ratio * ratio * 255);
	b = (int)(8.5 * (1 - ratio) * (1 - ratio) * (1 - ratio) * ratio * 255);
	mlx_put_pixel(fractol->image, i, j, pixel_color(r, g, b, 255));
}

void	drawing(void *fractol)
{
	t_fractol	*temp;

	temp = (t_fractol *)fractol;
	if (temp->c == 'M')
		run_mandelbrot(temp);
	else
		run_julia(temp);
}
