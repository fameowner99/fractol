#include "fractol.h"

void burningship(int x, int y, t_union *un)
{
	float cr = ((float)x - un->move.x)/ SIZE_X * un->zoom + -0.666;
	float ci = ((float)y - un->move.y)/ SIZE_Y * un->zoom + -0.5;
	float zr = 0;
	float zi = 0;
	

	int i = 0;
	while (i < un->iterations && zr * zr + zi * zi < 4)
	{
		float tmp = zr * zr - zi * zi + cr;
		zi = 2 * ABS(zr) * ABS(zi) + ci;
		zr = tmp;

		++i;
	}
	set_pixel_color(x, y, i, un, zr * zr + zi * zi);
}