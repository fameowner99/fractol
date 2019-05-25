/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 19:02:28 by vmiachko          #+#    #+#             */
/*   Updated: 2019/05/18 13:54:24 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			help(void)
{
	ft_printf("Usage: ./fractol [arg_name]\n \
arg_name:\n \
	julia 			Opens julia fractal\n \
	mandelbrot 		Opens mandelbrot fractal\n");
}

static t_fractal  	getFractal(char **argv)
{
	if (!ft_strcmp(argv[1], "julia"))
		return (JULIA);
	else if (!ft_strcmp(argv[1], "mandelbrot"))
		return (MANDELBROT);
	
	return (WRONGFRACTAL);
}

static int			setFractal(t_union *un, char **argv)
{
	t_fractal fractal = getFractal(argv);
	if (fractal == WRONGFRACTAL)
		return (FALSE);

	if (fractal == JULIA)
		un->fractal = &julia;
	else if (fractal == MANDELBROT)
		un->fractal = &mandelbrot;
	return (TRUE);
}

int					main(int argc, char **argv)
{
	t_union	un;

	if (argc != 2 || !setFractal(&un, argv))
		help();
	else
		fractol(&un);
	return (0);
}
