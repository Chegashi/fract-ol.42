/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:04:41 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/11 14:02:18 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	t_point		point;
	long double	dx_step;
	long double	dy_step;
	long double	dxx_step;
	long double	dyy_step;

	point = mac2rod(ft_init_point(x,y), *fractol);
	dx_step = fabsl((point.x - fractol->re_start) / 10);
	dxx_step = fabsl((point.x - fractol->re_end) / 10);
	dy_step = fabsl((point.y - fractol->img_end) / 10);
	dyy_step = fabsl((point.y - fractol->img_start) / 10);
	point = mac2rod(ft_init_point(x, y), *fractol);
	if (button == ZOOM_IN)
	{
		fractol->re_start += dx_step;
		fractol->re_end -= dxx_step;
		fractol->img_start += dyy_step;
		fractol->img_end -= dy_step;
	}
	if (button == ZOOM_OUT)
	{
		fractol->re_start -= dx_step;
		fractol->re_end += dxx_step;
		fractol->img_start -= dyy_step;
		fractol->img_end += dy_step;
	}
	fractol->len_x = fractol->re_end - fractol->re_start;
	fractol->len_y = fractol->img_end - fractol->img_start;
	ft_render(fractol);
	return (0);
}

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == ESC)
		ft_exit(fractol);
	else if (keycode == KEY_UP)
	{
		fractol->img_start += fractol->len_y / 10.0;
		fractol->img_end += fractol->len_y / 10.0;
	}
	else if (keycode == KEY_DOWN)
	{
		fractol->img_start -= fractol->len_y / 10.0;
		fractol->img_end -= fractol->len_y / 10.0;
	}
	else if (keycode == KEY_LEEFT)
	{
		fractol->re_start += fractol->len_x / 10.0;
		fractol->re_end += fractol->len_x / 10.0;
	}
	else if (keycode == KEY_RIGHT)
	{
		fractol->re_start -= fractol->len_x / 10.0;
		fractol->re_end -= fractol->len_x / 10.0;
	}
	fractol->len_x = fabsl(fractol->re_end - fractol->re_start);
	fractol->len_y = fabsl(fractol->img_end - fractol->img_start);
	ft_render(fractol);
	return (0);
}
