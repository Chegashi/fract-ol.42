/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:27:56 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/10 18:31:04 by mochegri         ###   ########.fr       */
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

void	ft_clean_win(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
			my_mlx_pixl_put(data, i, j, 0x0);
	}
}

void	ft_render(t_fractol *fractol)
{
	t_point	p;
	int		n;

	p.x = -1;
	n = 0;
		// printf("{%LF|%LF}\t{%LF|%LF}\n", fractol->re_start, fractol->re_end, fractol->img_start, fractol->img_end);
	ft_clean_win(&(fractol->img));
	while (++(p.x) < WIDTH)
	{
		p.y = -1;
		while (++(p.y) < HEIGHT)
		{
			n = ft_fractol(p, *fractol);
			// color.h = n * 255 / MAX_ITER;
			// color.s = 255;
			// if (n < MAX_ITER)
			// 	color.v = 255;
			// else
			// 	color.v = 0;
			if ( n == MAX_ITER)
				my_mlx_pixl_put(&(fractol->img), p.x, p.y, 0);
			else
			my_mlx_pixl_put(&(fractol->img), p.x, p.y, create_trgb(0, n, n*4, n*9));
		}
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img, 0, 0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
