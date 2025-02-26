/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_filling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:21:36 by hvahib            #+#    #+#             */
/*   Updated: 2025/02/26 15:25:52 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_filling(char set, char *str1, char *str2, t_fractol *fractol)
{
	fractol->c = set;
	if (!str1)
	{
		fractol->r_and_i.real = 0;
		fractol->r_and_i.img = 0;
	}
	else
	{
		fractol->r_and_i.real = ft_atof(str1);
		fractol->r_and_i.img = ft_atof(str2);
	}
	if (set == 'M')
		run_mandelbrot(fractol);
	else if (set == 'J')
		run_julia(fractol);
}
