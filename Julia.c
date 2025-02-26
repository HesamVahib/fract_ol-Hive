/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:21:33 by hvahib            #+#    #+#             */
/*   Updated: 2025/02/26 23:41:20 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	is_inside_julia(int i, int j, t_fractol *fractol)
{
	double	temp;
	double	zx;
	double	zy;
	int		iter;

	zx = fractol->x0;
	zy = -fractol->y0;
	iter = 0;
	while ((zx * zx) + (zy * zy) <= 4 && \
			iter < fractol->max_iteration)
	{
		temp = (zx * zx) - (zy * zy);
		zy = (2 * zx * zy) + fractol->r_and_i.img;
		zx = temp + fractol->r_and_i.real;
		iter++;
	}
	if (iter == fractol->max_iteration)
		return (0);
	else
		painting(iter, i, j, fractol);
	return (iter);
}

void	run_julia(t_fractol *fractol)
{
	double		res;
	int			i;
	int			j;

	i = 0;
	while (i < MAX_LENGTH)
	{
		j = 0;
		while (j < MAX_WIDTH)
		{
			fractol->x0 = ((double)i / MAX_LENGTH * 4.0 - 2.0) * fractol->zoom;
			fractol->y0 = ((double)j / MAX_WIDTH * 4.0 - 2.0) * fractol->zoom;
			res = is_inside_julia(i, j, fractol);
			if (res != 0)
				painting(res, i, j, fractol);
			j++;
		}
		i++;
	}
}
