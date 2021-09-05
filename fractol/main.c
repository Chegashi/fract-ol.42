/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:04:55 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/05 19:33:57 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Your software should offer the Julia set and the Mandelbrot set.
**	The mouse wheel zooms in and out, almost infinitely (within the limits of the computer). This is the very principle of fractals.
**	You must use at least a few colors to show the depth of each fractal. It’s even better if you hack away on psychedelic effects.
**	A parameter is passed on the command line to define what type of fractal will be viewed. If no parameter is provided, or if the parameter is invalid, the program displays a list of available parameters and exits properly.
**	More parameters must be used for fractal parameters or ignored.
**	You must be able to create different Julia set with the parameters of the program.
*/

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	*fractol;

	fractol = (t_fractol*)malloc(sizeof(t_fractol));
	if (!fractol)
		return (0);
	fractol->name = ft_check_arg(ac, av);
	ft_init_fractal(fractol);
	//ft_render(&fractol);
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

void	ft_init_fractal(t_fractol *fractol)
{
	int x,y;
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr,
							WIDTH, HEIGHT, fractol->name);
	fractol->img.img = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
	&(fractol->img.bpp), &(fractol->img.l_len), &(fractol->img.endian));
	ft_clean_win(fractol);
	mlx_key_hook(fractol->win_ptr, key_hook, fractol);
	mlx_hook(fractol->win_ptr, 2, 0, key_hook, fractol);
	mlx_hook(fractol->win_ptr, 4, 0, mouse_hook, fractol);
	mlx_hook(fractol->win_ptr, 17, 0, ft_exit, fractol);
	// mlx_mouse_get_pos(fractol->win_ptr, &x, &y);
	// mouse_hook(0,  x,  y);
	mlx_loop(fractol->mlx_ptr);
}

void			ft_clean_win(t_fractol *fractol)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fractol->width)
	{
		j = -1;
		while (++j < fractol->hight)
			my_mlx_pixl_put(&(fractol->img), i, j, 0x0, fractol);
	}
}

int		ft_exit(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_ptr, fractol->img.img);
	free(fractol);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_fractol * fractol)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
		ft_exit(fractol);
	return (0);
}

int				mouse_hook(int button, int x, int y)
{
	printf("{%d,%d}\n", x,y);
	return (0);
}

void		my_mlx_pixl_put(t_data *data, int x, int y, int color, t_fractol *fractol)
{
	char	*dst;

	if (x <= 0 || y <= 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->l_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}