/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:23:04 by mochegri          #+#    #+#             */
/*   Updated: 2022/08/02 00:31:21 by mochegri         ###   ########.fr       */
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
	fractol->re_start = -2;
	fractol->re_end = 2;
	fractol->img_start = -2;
	fractol->img_end = 2;
	fractol->b = 10;
	ft_render(fractol);
}

int	ft_exit(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_ptr, fractol->img.img);
	free(fractol);
	exit(EXIT_SUCCESS);
}

t_point	mac2rod(t_point pixel, t_fractol fractol)
{
	t_point	p1;

	p1.x = fractol.re_start + pixel.x / WIDTH * fractol.len_x;
	p1.y = fractol.img_end - pixel.y / HEIGHT * fractol.len_y;
	return (p1);
}

t_point	rod2mac(t_point p1, t_fractol fractol)
{
	t_point	pixel;

	pixel.x = ((p1.x - fractol.re_start) / fractol.len_x) * WIDTH;
	pixel.y = ((p1.y - fractol.img_start) / fractol.len_y) * HEIGHT;
	return (pixel);
}
