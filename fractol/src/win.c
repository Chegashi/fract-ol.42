/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:23:04 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/07 19:33:03 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_fractal(t_fractol *fractol)
{
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr,
			WIDTH, HEIGHT, fractol->name);
	fractol->img.img = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&(fractol->img.bpp), &(fractol->img.l_len), &(fractol->img.endian));
	ft_clean_win(fractol);
	ft_render(fractol);
	// mlx_key_hook(fractol->win_ptr, key_hook, fractol);
	// mlx_hook(fractol->win_ptr, 2, 0, key_hook, fractol);
	// mlx_hook(fractol->win_ptr, 4, 0, mouse_hook, fractol);
	// mlx_hook(fractol->win_ptr, 17, 0, ft_exit, fractol);
	mlx_loop(fractol->mlx_ptr);
}

int	ft_exit(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_ptr, fractol->img.img);
	free(fractol);
	exit(EXIT_SUCCESS);
}
