/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:04:41 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/11 18:58:05 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	t_steps	s;

	s.point = mac2rod(ft_init_point(x, y), *fractol);
	s.dx_step = (s.point.x - fractol->re_start) / 10.0;
	s.dxx_step = (fractol->re_end - s.point.x) / 10.0;
	s.dy_step = (fractol->img_end - s.point.y) / 10.0;
	s.dyy_step = (s.point.y - fractol->img_start) / 10.0;
	if (button == ZOOM_IN)
	{
		fractol->re_start += s.dx_step;
		fractol->re_end -= s.dxx_step;
		fractol->img_start += s.dyy_step;
		fractol->img_end -= s.dy_step;
	}
	else if (button == ZOOM_OUT)
	{
		fractol->re_start -= s.dx_step;
		fractol->re_end += s.dxx_step;
		fractol->img_start -= s.dyy_step;
		fractol->img_end += s.dy_step;
	}
	ft_render(fractol);
	return (0);
}

int	key_hook(int keycode, t_fractol *fractol)
{
	ft_color_key(keycode, fractol);
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
	ft_render(fractol);
	return (0);
}

void	ft_color_key(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_PLUS)
		fractol->b += 25;
	else if (keycode == KEY_MOIS)
		fractol->b -= 25;
}
