#include "fractol.h"

void	fractol(t_union *un)
{
	un->mlx.init_ptr = mlx_init();
	un->mlx.window_ptr = mlx_new_window(un->mlx.init_ptr, SIZE_X, SIZE_Y, "fractol");
	un->img = ft_create_new_image(un);
	un->iterations = 10;
	un->zoom = 10;
	un->color = JUNKY;
	un->mouse.left_button = FALSE;
	un->mouse.right_button = FALSE;
	un->move.x = SIZE_X / 2;
	un->move.y = SIZE_Y / 2;
	un->redrawMouseMovement = FALSE;

	setup_controls(un);
	draw(un);
	
	mlx_loop(un->mlx.init_ptr);
}