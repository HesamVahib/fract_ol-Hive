/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:21:40 by hvahib            #+#    #+#             */
/*   Updated: 2025/02/26 23:39:42 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zooming(double xdelta, double ydelta, void *params)
{
	t_fractol	*fractol;

	(void)xdelta;
	fractol = (t_fractol *)params;
	ydelta *= 10;
	if (ydelta < 0)
	{
		fractol->zoom *= 1.25;
		if (fractol->max_iteration < 512 && fractol->c == 'M')
			fractol->max_iteration += 50;
	}
	else if (ydelta > 0)
	{
		fractol->zoom /= 1.25;
		if (fractol->max_iteration > 10 && fractol->c == 'M')
			fractol->max_iteration -= 10;
	}
}

int	sign_check(char c)
{
	if (c == '+' || c == '-')
	{
		if (c != '-')
			return (1);
		return (-1);
	}
	else
		return (0);
}

double	ft_atof(char *str)
{
	int		i;
	int		j;
	double	nbr;
	double	nbr_dot;

	i = 0;
	j = 0;
	nbr = 0.00;
	nbr_dot = 0.00;
	if (sign_check(str[i]) != 0)
		i++;
	while (str[i + j] != '\0')
	{
		if (j == 0 && str[i] != '.')
			nbr = nbr * 10.00 + (str[i++] - '0');
		else if (str[i + j] != '.')
			nbr_dot = nbr_dot + (str[i + j] - '0') * pow(0.1, j);
		if (str[i + j] == '.' || j != 0)
			j++;
	}
	if (sign_check(str[0]) == -1 && (nbr + nbr_dot) != 0.00)
		return ((nbr + nbr_dot) * -1.00);
	return (nbr + nbr_dot);
}

void	escape_bt(mlx_key_data_t keydata, void *fractol)
{
	mlx_t	*mlx;

	mlx = fractol;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(mlx);
}
