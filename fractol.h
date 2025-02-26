/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:24:56 by hvahib            #+#    #+#             */
/*   Updated: 2025/02/26 23:45:07 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <unistd.h>
# include "MLX42/MLX42.h"
# include "libft/libft.h"
# include <stdbool.h>

# define MAX_LENGTH 960
# define MAX_WIDTH 960

typedef struct s_complex
{
	double	real;
	double	img;
}	t_complex;

typedef struct s_fractol
{
	double		xdelta;
	double		ydelta;
	double		x0;
	double		y0;
	int			max_iteration;
	double		zoom;
	mlx_image_t	*image;
	mlx_t		*mlx;
	char		c;
	t_complex	r_and_i;
}	t_fractol;

void	image_filling(char set, char *str1, char *str2, t_fractol *params);
void	escape_bt(mlx_key_data_t keydata, void *fractol);
double	ft_atof(char *str);
void	zooming(double xdelta, double ydelta, void *param);
int32_t	pixel_color(int32_t r, int32_t g, int32_t b, int32_t a);
void	drawing(void *fractol);
void	painting(int iter, int i, int j, t_fractol *fractol);
void	run_mandelbrot(t_fractol *fractol);
void	run_julia(t_fractol *params);

#endif