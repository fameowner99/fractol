
#ifndef FRACTOL_H

# define FRACTOL_H

#include "mlx.h"
#include "libft.h"
#include <unistd.h>

# define SIZE_X 1500
# define SIZE_Y 1500

typedef struct		s_img
{
	void			*new_image;
	void			*image_ptr;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*init_ptr;
	void			*window_ptr;
}					t_mlx;

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;


typedef struct		s_union
{
	t_img			*img;
	t_mlx			mlx;
	t_point			*point;
}					t_union;

t_img		*ft_create_new_image(t_union *un);
void		ft_putpixel(t_img *img, int x, int y, int color);
void		fractol();
void		setup_controls(t_union *un);
void		draw(t_union *un);
void		mandelbrot(int x, int y, t_union *un);

#endif