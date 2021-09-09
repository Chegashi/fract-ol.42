/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:04:55 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/09 19:59:35 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Your software should offer the Julia set and the Mandelbrot set.
**	The mouse wheel zooms in and out, almost infinitely (within the limits of
**	the computer). This is the very principle of fractals.
**	You must use at least a few colors to show the depth of each fractal.
**	You It’s even better if you hack away on psychedelic effects.
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
	fractol->re_start = -2;
	fractol->re_end = 2 ;
	fractol->img_end = -2;
	fractol->img_start = -2;
	ft_init_fractal(fractol);
	mlx_key_hook(fractol->win_ptr, key_hook, fractol);
	mlx_hook(fractol->win_ptr, 2, 0, key_hook, fractol);
	mlx_hook(fractol->win_ptr, 4, 0, mouse_hook, fractol);
	mlx_hook(fractol->win_ptr, 17, 0, ft_exit, fractol);
	mlx_loop(fractol->mlx_ptr);
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

int	ft_fractol(t_point p, t_fractol fractol)
{
	// if (ft_strcmp(fractol.name, "Mandelbrot"))
	return (mandelbrot(ft_transposer(p,fractol)));
	// else if (ft_strcmp(fractol.name, "Julia"))
	// 	return (julia(z));
	// else
	// 	return (cosin(z));
}
