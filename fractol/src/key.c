/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:04:41 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/09 19:33:29 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == ZOOM_IN)
	{
		fractol->re_start += (x / (double)2) / (double)WIDTH;
		fractol->re_end -= x / (double)2 / (double)WIDTH;
		fractol->img_start += y / (double)2 / (double)HEIGHT;
		fractol->img_end -= y / (double)2 / (double)HEIGHT;
	}
	if (button == ZOOM_OUT)
	{
		fractol->re_start -= (x / (double)2) / (double)WIDTH;
		fractol->re_end += x / (double)2 / (double)WIDTH;
		fractol->img_start -= y / (double)2 / (double)HEIGHT;
		fractol->img_end += y / (double)2 / (double)HEIGHT;
	}
	printf("%d|{%d|%d}\n", button,x,y);
	ft_render(fractol);
	return (0);
}

int	key_hook(int keycode, t_fractol *fractol)
{
	// printf("%d\n", keycode);
	if (keycode == ESC)
		ft_exit(fractol);
	return (0);
}
