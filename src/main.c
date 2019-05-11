#include "mlx.h"
#include "fractol.h"

int main()
{
	t_union	un;

	un.mlx.init_ptr = mlx_init();
		un.mlx.window_ptr = mlx_new_window(un.mlx.init_ptr,
				500, 500, "fractol");
		un.img = ft_create_new_image(un);

		mlx_loop(un.mlx.init_ptr);
	return (0);
}
