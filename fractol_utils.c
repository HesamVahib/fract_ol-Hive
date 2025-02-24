#include "fractol.h"

void	zooming(double xdelta, double ydelta, void *params)
{
	(void)xdelta;
	t_fractol	*fractol;

	fractol = (t_fractol *)params;
	ydelta *= 5; // here by changing this number smething happens
	if (ydelta < 0)
	{
		fractol->zoom = fractol->zoom / 1.05;
		if (fractol->max_iteration > 50 && fractol->c == 'M')
			fractol->max_iteration = fractol->max_iteration - 50;
	}
	else if (ydelta > 0)
		fractol->zoom = fractol->zoom * 1.05;
	if (fractol->c == 'M')
		run_mandelbrot(fractol);
	else
		run_julia(fractol);
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

void	escape_bt(void *fractol)
{
	mlx_t	*mlx;

	mlx = fractol;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}