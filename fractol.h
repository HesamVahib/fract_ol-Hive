#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <unistd.h>
# include <MLX42/MLX42.h>
# include "libft/libft.h"


typedef struct s_complex // this is the imaginary and the real part  of the number for C
{
	double	real;
	double	imag;
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

// //utils.c
void	escape_bt(void *fractol);
double	ft_atof(char *str);
void	zooming(double xdelta, double ydelta, void *param);
// int		check_number(const char *s1);
// //colouring.c
int32_t	pixel_color(int32_t r, int32_t g, int32_t b, int32_t a);
void	outside_painting(int iter, int i, int j, t_fractol *fractol);
void	inside_painting(double iter, int i, int j, t_fractol *fractol);

void	run_mandelbrot(t_fractol *fractol);
void	run_julia(t_fractol *params);

#endif