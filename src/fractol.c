#include "fractol.h"

int			deal_key(int key)
{
	if (key == 53)
		exit(EXIT_SUCCESS);

	return (0);
}

void	fractol()
{
	t_union	un;

	un.mlx.init_ptr = mlx_init();
	un.mlx.window_ptr = mlx_new_window(un.mlx.init_ptr, SIZE_X, SIZE_Y, "fractol");
	un.img = ft_create_new_image(un);
	mlx_hook(un.mlx.window_ptr, 2, 5, deal_key, NULL);

	mlx_loop(un.mlx.init_ptr);
}