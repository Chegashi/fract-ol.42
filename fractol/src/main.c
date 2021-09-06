/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:04:55 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/06 17:32:06 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Your software should offer the Julia set and the Mandelbrot set.
**	The mouse wheel zooms in and out, almost infinitely (within the limits of
**	the computer). This is the very principle of fractals.
**	You must use at least a few colors to show the depth of each fractal.
**	You It’s even better if you hack away on psychedelic effects.
**	A parameter is passed on the command line to define what type of fractal
**	You will be viewed. If no parameter is provided, or if the parameter
**	Youis invalid, the program displays a list of available parameters and
**	You exits properly.
**	More parameters must be used for fractal parameters or ignored.
**	You must be able to create different Julia set with the parameters of 
**	the program.
*/

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		return (0);
	fractol->name = ft_check_arg(ac, av);
	ft_init_fractal(fractol);
	ft_render(fractol);
	return (0);
}

char	*ft_check_arg(int ac, char **av)
{	
	if (ac == 2)
	{
		if (!ft_strcmp(*(av + 1), "Mandelbrot"))
			return (ft_strdup("Mandelbrot"));
		else if (!ft_strcmp(*(av + 1), "Julia"))
			return (ft_strdup("Julia"));
	}
	ft_putstr(MSG);
	exit(1);
}
