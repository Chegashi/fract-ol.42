/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:27:56 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/08 17:57:10 by mochegri         ###   ########.fr       */
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

void	ft_clean_win(t_fractol *fractol)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fractol->width)
	{
		j = -1;
		while (++j < fractol->hight)
			my_mlx_pixl_put(&(fractol->img), i, j, 0x0);
	}
}

void	ft_render(t_fractol *fractol)
{
	t_point	p;
	int		n;
	t_hsv	color;

	p.x = -1;
	n = 0;
	while (++(p.x) < WIDTH)
	{
		p.y = -1;
		while (++(p.y) < HEIGHT)
		{
			n = mandelbrot(ft_init_point(RE_START + p.x / WIDTH * (RE_END 
					- RE_START), IMG_START + p.y / HEIGHT * (IMG_END
					- IMG_START)));
			color.h = 255 - (n * 255 / MAX_ITER);
			color.s = 50;
			if (n < MAX_ITER)
				color.v = 255;
			else
				color.v = 0;
			my_mlx_pixl_put(&(fractol->img), p.x, p.y, hcv2rgb(color));
		}
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img, 0, 0);
}

int	mandelbrot(t_point c)
{
	t_point	z;
	int		n;

	n = 0;
	z.x = 0;
	z.y = 0;
	while (ft_module(z) <= 2 && n < MAX_ITER)
	{
		z = ft_plus(ft_sqaure(z), c);
		n++;
	}
	return (n);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
