/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:21:59 by hvahib            #+#    #+#             */
/*   Updated: 2025/02/26 23:41:39 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_window(char set, char *str1, char *str2, t_fractol *fractol)
{
	if (!fractol->mlx)
		return (1);
	mlx_key_hook(fractol->mlx, escape_bt, fractol->mlx);
	mlx_loop_hook(fractol->mlx, drawing, fractol);
	image_filling(set, str1, str2, fractol);
	mlx_scroll_hook(fractol->mlx, zooming, fractol);
	mlx_loop(fractol->mlx);
	mlx_terminate(fractol->mlx);
	return (0);
}

int	init_error_handling(void)
{
	write(1, "Something went wrong.\n", 23);
	write(1, "Do you wanna try it again?\n", 28);
	write(1, "Valid arguments:'Mandelbrot' OR 'Julia (num1) (num2)'\n", 55);
	return (1);
}

int	nbr_validation(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == '.')
		{
			j++;
			i++;
		}
		else
			return (1);
	}
	if (j < 2 && ft_strlen(str) < 64)
		return (0);
	write(1, "Choose Something Reasonable and Correct like 0.5 or 3.\n", 56);
	return (1);
}

int	init_fractol(t_fractol *fractol)
{
	fractol->xdelta = 0;
	fractol->ydelta = 0;
	fractol->x0 = 0;
	fractol->y0 = 0;
	fractol->zoom = 1.00;
	fractol->max_iteration = 512;
	fractol->mlx = mlx_init(MAX_LENGTH, MAX_WIDTH, "Fractal", false);
	if (!(fractol->mlx))
		return (mlx_close_window(fractol->mlx), 1);
	fractol->image = mlx_new_image(fractol->mlx, MAX_LENGTH, MAX_WIDTH);
	if (!(fractol->image) || \
			(mlx_image_to_window(fractol->mlx, fractol->image, 0, 0) == -1))
		return (mlx_close_window(fractol->mlx), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	int			res;
	t_fractol	fractol;

	if (init_fractol(&fractol) != 0 || (argc < 2 || argc > 4 || argc == 3))
		return (init_error_handling(), 0);
	else if (argc == 2)
	{
		res = ft_strncmp(argv[1], "Mandelbrot", 11);
		if (res != 0)
			res = ft_strncmp(argv[1], "Julia", 6);
		if (res == 0 && create_window(argv[1][0], NULL, NULL, &fractol) == 0)
			return (0);
	}
	else if (argc == 4)
	{
		res = ft_strncmp(argv[1], "Julia", 6);
		res += nbr_validation(argv[2]) + nbr_validation(argv[3]);
		if (res == 0 && \
			create_window(argv[1][0], argv[2], argv[3], &fractol) == 0)
			return (0);
	}
}
