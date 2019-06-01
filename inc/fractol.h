
#ifndef FRACTOL_H

# define FRACTOL_H

#include "mlx.h"
#include "libft.h"
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <OpenCL/opencl.h>

# define SIZE_X 1000
# define SIZE_Y 1000
# define FALSE 0
# define TRUE 1

typedef enum 			s_color
{
	JUNKY = 0,
	BLACKWHITE,
	COLOR
}						t_color;

typedef enum 			s_fractal
{
	MANDELBROT = 0,
	JULIA,
	BURNINGSHIP,
	WRONGFRACTAL
}						t_fractal;

typedef struct			s_img
{
	void				*new_image;
	void				*image_ptr;
	int					bpp;
	int					size_line;
	int					endian;
}						t_img;

typedef struct			s_mlx
{
	void				*init_ptr;
	void				*window_ptr;
}						t_mlx;

typedef struct			s_point
{
	float				x;
	float				y;
}						t_point;

typedef struct 			s_move
{
	int 				x;
	int 				y;
	int 				pressed_x;
	int 				pressed_y;
}						t_move;

typedef struct 			s_mouse_movement
{
	int 				x;
	int 				y;
	int 				left_button;
	int 				right_button;

}						t_mouse_movement;

typedef struct			s_opencl
{
	cl_platform_id		platform_id;
	cl_uint				ret_num_platforms;
	cl_device_id		device_id;
	cl_uint				num_devices;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_program			program;
	cl_kernel			kernel;
	cl_int				ret;

}						t_opencl;

typedef struct			s_union
{
	t_img				*img;
	t_mlx				mlx;
	t_point				point;
	t_move 				move;
	t_mouse_movement 	mouse;
	float				zoom;
	int 				iterations;
	t_color 			color;
	int 				redrawMouseMovement;
	void				(*fractal)(int x, int y, struct s_union *un);
}						t_union;

//start opencl
void				initialize_opencl(t_opencl *cl);

void				getPlatrofrmsId(t_opencl *cl);
void				getDeviceId(t_opencl *cl);
void				createContex(t_opencl *cl);
void				createCommandQueue(t_opencl *cl);

void    			build_cl(t_opencl *cl);
//end opencl

void		redraw(t_union *un);
t_img		*ft_create_new_image(t_union *un);
void		ft_putpixel(t_img *img, int x, int y, int color);
void		fractol(t_union *un);
void		setup_controls(t_union *un);
void 		set_pixel_color(int x, int y, int curr_iteration, t_union *un, float length);
void		draw(t_union *un);
void		mandelbrot(int x, int y, t_union *un);
void		julia(int x, int y, t_union *un);
void 		burningship(int x, int y, t_union *un);

#endif