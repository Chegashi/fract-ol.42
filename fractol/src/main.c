/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:04:55 by mochegri          #+#    #+#             */
/*   Updated: 2022/08/02 00:11:45 by mochegri         ###   ########.fr       */
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
	else if (!ft_strcmp("Julia_1", fractol.name))
		return (julia(mac2rod(p, fractol), ft_init_point(-0.4, 0.6)));
	else if (!ft_strcmp("Julia_2", fractol.name))
		return (julia(mac2rod(p, fractol), ft_init_point(0.285, 0.01)));
	else if (!ft_strcmp("Julia_3", fractol.name))
		return (julia(mac2rod(p, fractol), ft_init_point(0.45, 0.1428)));
	else if (!ft_strcmp("Julia_4", fractol.name))
		return (julia(mac2rod(p, fractol), ft_init_point(-0.70176, -0.3842)));
	else if (!ft_strcmp("Julia_5", fractol.name))
		return (julia(mac2rod(p, fractol), ft_init_point(-0.835, -0.3842)));
	else if (!ft_strcmp("Julia_6", fractol.name))
		return (julia(mac2rod(p, fractol), ft_init_point(-0.8, 0.156)));
	else if (!ft_strcmp("Julia_7", fractol.name))
		return (julia(mac2rod(p, fractol), ft_init_point(-0.8, 0.1889)));
	else if (!ft_strcmp("Julia_8", fractol.name))
		return (julia(mac2rod(p, fractol), ft_init_point(-0.7269, 0.1889)));
	else
		return (julia(mac2rod(p, fractol), ft_init_point(0, -0.8)));
}

int	ft_fractal_is_def(char *s)
{
	char	*fractals[] = {"Mandelbrot", "Mandelbrot_4", "Flower", "Julia_1",
		"Julia_2", "Julia_3", "Julia_4", "Julia_5", "Julia_6", "Julia_7",
		"Julia_8", "Julia_9" , ""};
	int i;
	i = -1;
	while (ft_strcmp((char*)fractals[++i], ""))
		if (!ft_strcmp(fractals[i], s))
			return (1);
	i = -1;
	while (ft_strcmp((char*)fractals[++i], ""))
	{
		ft_putstr("\n--> ");
		ft_putstr(fractals[i]);
	}
	ft_putstr("\n");
	return (0);
}
