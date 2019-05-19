#include "fractol.h"
#include "events.h"


int		window_close()
{
	exit(0);
	return (0);
}

int			deal_key(int key, t_union *un)
{
	if (key == ESC)
		exit(EXIT_SUCCESS);
	else if (key == ITER_INC)
	{
		if (un->iterations >= 250)
			return (0);
		un->iterations += 5;
		redraw(un);
	}
	else if (key == ITER_DEC)
	{
		if (un->iterations <= 0)
			return (0);
		un->iterations -= 5;
		redraw(un);
	}
	
	return (0);
} //TO DO: move to another file 

int mouse_press(int key, int x, int y, t_union *un)
{
	if (key == ZOOM_OUT)
	{
		un->zoom *= 2;
		redraw(un);
	}
	if (key == ZOOM_IN)
	{
		un->zoom /= 2;
		redraw(un);
	}
	if (key == MOUSE_LEFT_BUT)
	{
		un->mouse.left_button = TRUE;
		un->move.pressed_x = x;
		un->move.pressed_y = y;
	}

	return (0);
}

int mouse_release(int key, int x, int y, t_union *un)
{
	if (key == MOUSE_LEFT_BUT)
	{
		un->mouse.left_button = FALSE;
	}
	return (0);
}

int mouse_move(int x, int y, t_union *un)
{
	if (un->mouse.left_button == TRUE)
	{
		un->move.x += x - un->move.pressed_x;
		un->move.y += y - un->move.pressed_y;
		un->move.pressed_x = x;
		un->move.pressed_y = y;
		redraw(un);
	}
	return (0);
}

void	setup_controls(t_union *un)
{
	mlx_hook(un->mlx.window_ptr, 2, 5, deal_key, un);
	mlx_hook(un->mlx.window_ptr, 4, 0, mouse_press, un);
	mlx_hook(un->mlx.window_ptr, 5, 0, mouse_release, un);
	mlx_hook(un->mlx.window_ptr, 6, 0, mouse_move, un);
	mlx_hook(un->mlx.window_ptr, 17, 0, window_close, NULL);
}