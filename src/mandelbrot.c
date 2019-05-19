#include "fractol.h"

void	mandelbrot(int x, int y, t_union *un)
{
	float cr = ((float)x - un->move.x)/ SIZE_X * un->zoom + -1.6;
	float ci = ((float)y - un->move.y)/ SIZE_Y * un->zoom + -0.5;
	float zr = 0;
	float zi = 0;


	int i = 0;
	while (i < un->iterations && zr * zr + zi * zi < 4)
	{
		float tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;

		++i;
	}
	if (i < un->iterations)
		ft_putpixel(un->img, x, y, 0xCC0000 * i / (un->iterations - 1)) ;
	else
		ft_putpixel(un->img, x, y, 0x000000);
 } 
