#include "fractol.h"


void set_pixel_color(int x, int y, int curr_iteration, t_union *un, float length)
{
	int in_set;
	int not_in_set;

	in_set = 0x000000;
	if (un->color == JUNKY)
		not_in_set = 0xCC0000 * curr_iteration / (un->iterations - 1);
	else if (un->color == BLACKWHITE)
	{
		in_set = 0xFFFFFF;
		not_in_set = 0x000000;
	}
	else if (un->color == COLOR)
		not_in_set = (0xCC0000) * (sqrt(length) / 2);

	if (curr_iteration < un->iterations)
		ft_putpixel(un->img, x, y, not_in_set);
	else
		ft_putpixel(un->img, x, y, in_set);
}

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
			un->fractal(x, y, un);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(un->mlx.init_ptr,
			un->mlx.window_ptr, un->img->new_image, 0, 0);
}