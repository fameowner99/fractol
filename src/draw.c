#include "fractol.h"


void draw(t_union *un)
{
	int x;
	int y;

	y = 0;
	while (y < SIZE_Y)
	{
		x = 0;
		while(x < SIZE_X)
		{
			mandelbrot(x, y, un);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(un->mlx.init_ptr,
			un->mlx.window_ptr, un->img->new_image, 0, 0);
}