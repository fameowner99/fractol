#include "fractol.h"

void	fractol()
{
	t_union	un;

	un.mlx.init_ptr = mlx_init();
	un.mlx.window_ptr = mlx_new_window(un.mlx.init_ptr, SIZE_X, SIZE_Y, "fractol");
	un.img = ft_create_new_image(&un);

	draw(&un);
	setup_controls(&un);
	
	mlx_loop(un.mlx.init_ptr);
}