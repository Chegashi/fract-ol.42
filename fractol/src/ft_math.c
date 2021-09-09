/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:21:10 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/09 19:59:00 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	ft_module(t_point z)
{
	return (sqrt((z.x * z.x) + (z.y * z.y)));
}

t_point	ft_plus(t_point z1, t_point z2)
{
	return (ft_init_point(z1.x + z2.x, z1.y + z2.y));
}

t_point	ft_sqaure(t_point z)
{
	return (ft_init_point((z.x * z.x) - (z.y * z.y), (z.x * z.y) + (z.x * z.y)));
}

t_point	ft_init_point(const long double x, const long double y)
{
	t_point	z;

	z.x = x;
	z.y = y;
	return (z);
}

t_point	ft_transposer(t_point z, t_fractol fractol)
{
	t_point p;

	p.x = fractol.re_start + z.x / WIDTH * (fractol.re_end - fractol.re_start);
	p.y = fractol.img_start + z.y / HEIGHT * (fractol.img_end - fractol.img_start);
	return (p);
}