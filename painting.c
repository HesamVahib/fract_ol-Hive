#include "fractol.h"

int32_t	pixel_color(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	outside_painting(int iter, int i, int j, t_fractol *fractol)
{
	if (iter < 3)
		mlx_put_pixel(fractol->image, i, j, pixel_color(38, 115, 157, 200)); // I gotta change these colors
	else if (iter < 5)
		mlx_put_pixel(fractol->image, i, j, pixel_color(252, 98, 111, 200));
	else if (iter < 10)
		mlx_put_pixel(fractol->image, i, j, pixel_color(255, 210, 73, 200));
	else
		mlx_put_pixel(fractol->image, i, j, pixel_color(36, 17, 12, 200));
}

void	inside_painting(double iter, int i, int j, t_fractol *fractol)
{
	if (iter < 10)
		mlx_put_pixel(fractol->image, i, j, pixel_color(221, 97, 55, 200));
	else if (iter < 25)
		mlx_put_pixel(fractol->image, i, j, pixel_color(239, 171, 104, 200));
	else if (iter < 30)
		mlx_put_pixel(fractol->image, i, j, pixel_color(253, 251, 118, 200));
	else if (iter < 50)
		mlx_put_pixel(fractol->image, i, j, pixel_color(227, 169, 96, 200));
	else if (iter < 70)
		mlx_put_pixel(fractol->image, i, j, pixel_color(82, 148, 107, 200));
	else if (iter < 90)
		mlx_put_pixel(fractol->image, i, j, pixel_color(79, 133, 154, 200));
	else if (iter < 100)
		mlx_put_pixel(fractol->image, i, j, pixel_color(108, 182, 177, 200));
	else if (iter < 200)
		mlx_put_pixel(fractol->image, i, j, pixel_color(255, 144, 31, 200));
	else if (iter < 400)
		mlx_put_pixel(fractol->image, i, j, pixel_color(255, 41, 117, 200));
	else if (iter < 600)
		mlx_put_pixel(fractol->image, i, j, pixel_color(199, 0, 181, 200));
	else if (iter < 800)
		mlx_put_pixel(fractol->image, i, j, pixel_color(176, 0, 255, 200));
	else
		mlx_put_pixel(fractol->image, i, j, pixel_color(0, 219, 150, 200));
}