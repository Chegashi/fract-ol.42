/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:27:56 by mochegri          #+#    #+#             */
/*   Updated: 2022/08/02 00:36:14 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixl_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x <= 0 || y <= 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->l_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_render(t_fractol *fractol)
{
	t_point	p;
	int		n;

	fractol->len_x = fractol->re_end - fractol->re_start;
	fractol->len_y = fractol->img_end - fractol->img_start;
	mlx_clear_window(fractol->mlx_ptr, fractol->win_ptr);
	p.x = -1;
	while (++(p.x) < WIDTH)
	{
		p.y = -1;
		while (++(p.y) < HEIGHT)
		{
			n = ft_fractol(p, *fractol);
			if (n == MAX_ITER)
				my_mlx_pixl_put(&(fractol->img), p.x, p.y, 0);
			else
				my_mlx_pixl_put(&(fractol->img), p.x, p.y, create_trgb(n +
				fractol->b, (n * 3) % 255, (n * 10) % 255, fractol->b * n % 255));
		}
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img, 0, 0);
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, 10, 10, 0xFFFFFF,
		fractol->name);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
