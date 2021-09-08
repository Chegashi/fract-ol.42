/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:15:04 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/08 17:46:04 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hcv2rgb(t_hsv c)
{
	t_rgb2hsv	color;

	// c.s /= 255;
	// c.v /= 255;
	// if (c.h > 360 || c.h < 0 || c.s > 100 || c.s < 0 || c.v > 100 || c.v < 0)
	// {
	// 	printf("%d\n", c.s > 100 );
	// 	return (0);
	// }
	color.c = (c.v / 255) * (c.s / 255);
	color.x = color.c * (1 - fabs(fmod(c.h / 60.0, 2) - 1));
	color.m = c.v / 255 - color.c;
	if (0 <= c.h && c.h < 60)
		hcv2rgb_h0(&color);
	else if (60 <= c.h && c.h < 120)
		hcv2rgb_h60(&color);
	else if (120 <= c.h && c.h < 180)
		hcv2rgb_h120(&color);
	else if (180 <= c.h && c.h < 240)
		hcv2rgb_h180(&color);
	else if (240 <= c.h && c.h < 300)
		hcv2rgb_h240(&color);
	else if (300 <= c.h && c.h < 360)
		hcv2rgb_h300(&color);
	color.R = (int)((color.r + color.m) * 255);
	color.G = (int)((color.g + color.m) * 255);
	color.B = (int)((color.B + color.m) * 255);
	return (0 << 24 | color.B << 16 | color.G << 8 | color.B);
}

void	hcv2rgb_h0(t_rgb2hsv *color)
{
	color->r = color->c;
	color->g = color->x;
	color->b = 0;
}

void	hcv2rgb_h60(t_rgb2hsv *color)
{
	color->r = color->x;
	color->g = color->c;
	color->b = 0;
}

void	hcv2rgb_h120(t_rgb2hsv *color)
{
	color->r = 0;
	color->g = color->c;
	color->b = color->x;
}

void	hcv2rgb_h180(t_rgb2hsv *color)
{
	color->r = 0;
	color->g = color->x;
	color->b = color->c;
}
