/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:04:55 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/11 18:59:06 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		return (0);
	fractol->name = ft_check_arg(ac, av);
	fractol->re_start = -2;
	fractol->re_end = 2;
	fractol->img_end = 2;
	fractol->img_start = -2;
	ft_init_fractal(fractol);
	mlx_hook(fractol->win_ptr, 2, 0, key_hook, fractol);
	mlx_hook(fractol->win_ptr, 4, 0, mouse_hook, fractol);
	mlx_hook(fractol->win_ptr, 17, 0, ft_exit, fractol);
	mlx_loop(fractol->mlx_ptr);
	return (0);
}

char	*ft_check_arg(int ac, char **av)
{
	if (ac == 2)
		if (ft_fractal_is_def(*(av + 1)))
			return (ft_strdup(*(av + 1)));
	ft_putstr(MSG);
	exit(1);
}

int	ft_fractol(t_point p, t_fractol fractol)
{
	if (!ft_strcmp("Mandelbrot", fractol.name))
		return (mandelbrot(mac2rod(p, fractol)));
	else if (!ft_strcmp("Mandelbrot_4", fractol.name))
		return (mandelbrot_4(mac2rod(p, fractol)));
	else if (!ft_strcmp("Flower", fractol.name))
		return (flower(mac2rod(p, fractol)));
	else
		return (julia(mac2rod(p, fractol)));
}

int	ft_fractal_is_def(char *s)
{
	return (!ft_strcmp(s, "Mandelbrot") || !ft_strcmp(s, "Julia")
		|| !ft_strcmp(s, "Mandelbrot_4") || !ft_strcmp(s, "Flower"));
}
