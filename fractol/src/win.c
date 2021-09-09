/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:23:04 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/09 17:02:59 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_fractal(t_fractol *fractol)
{
	int	start;
	int	end;
	int	i;

	i = -1;
	start = 0x0009ff;
	end = 0x330e10;
	while (++i < MAX_ITER)
		fractol->color[i] = ((end - start) / MAX_ITER) * i;
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr,
			WIDTH, HEIGHT, fractol->name);
	fractol->img.img = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&(fractol->img.bpp), &(fractol->img.l_len), &(fractol->img.endian));
	fractol->re_start = -2;
	fractol->re_end = 1;
	fractol->img_start = -1;
	fractol->img_end = 1;
	ft_clean_win(fractol);
	ft_render(fractol);
}

int	ft_exit(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_ptr, fractol->img.img);
	free(fractol);
	exit(EXIT_SUCCESS);
}
