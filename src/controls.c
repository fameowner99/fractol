#include "fractol.h"


int		window_close()
{
	exit(0);
	return (0);
}

int			deal_key(int key)
{
	if (key == 53)
		exit(EXIT_SUCCESS);

	return (0);
} //TO DO: move to another file 

void	setup_controls(t_union *un)
{
	mlx_hook(un->mlx.window_ptr, 2, 5, deal_key, NULL);
	mlx_hook(un->mlx.window_ptr, 17, 0, window_close, NULL);
}