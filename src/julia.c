#include "fractol.h"

void		julia(int x, int y, t_union *un)
{
	float zr = ((float)x - un->move.x)/ SIZE_X * un->zoom;
	float zi = ((float)y - un->move.y)/ SIZE_Y * un->zoom;
	static float cr = 0.355;
	static float ci = 0.355;

	if (un->redrawMouseMovement)
	{
		cr = (float)un->mouse.x / SIZE_X;
		ci = (float)un->mouse.y / SIZE_Y;
	}

	int i = 0;
	while (i < un->iterations && zr * zr + zi * zi < 16)
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