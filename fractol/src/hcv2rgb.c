/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hcv2rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:00:27 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/08 16:52:07 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hcv2rgb_h240(t_rgb2hsv *color)
{
	color->r = color->x;
	color->g = 0;
	color->b = color->c;
}

void	hcv2rgb_h300(t_rgb2hsv *color)
{
	color->r = color->c;
	color->g = 0;
	color->b = color->x;
}
