/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:27:56 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/06 17:46:49 by mochegri         ###   ########.fr       */
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
	
}

t_point	Mandelbrot()
{
	
}
