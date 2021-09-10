/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:04:41 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/10 20:04:52 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	t_point		point;
	long double	dx_step;
	long double	dy_step;

	point = mac2rod(ft_init_point(x,y), *fractol);
	dx_step = (point.x - fractol->re_start) / 10;
	dy_step = (point.y - fractol->img_end) / 10;
	point = mac2rod(ft_init_point(x, y), *fractol);
	if (button == ZOOM_IN)
	{
		fractol->re_start += dx_step;
		fractol->re_end -= dx_step;
		fractol->img_start += dy_step;
		fractol->img_end -= dy_step;
	}
	if (button == ZOOM_OUT)
	{
		fractol->re_start -= dx_step;
		fractol->re_end += dx_step;
		fractol->img_start -= dy_step;
		fractol->img_end += dy_step;
	}
	printf("{%LF|%LF} {%LF|%LF}{\n", dx_step, dy_step, point.x, point.y);
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
