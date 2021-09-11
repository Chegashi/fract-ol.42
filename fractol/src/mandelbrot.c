/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:18:26 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/11 18:31:19 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(const t_point c)
{
	t_point	z;
	int		n;

	n = 0;
	z = ft_init_point(0, 0);
	while (ft_module(z) <= 2 && n < MAX_ITER)
	{
		z = ft_plus(ft_sqaure(z), c);
		n++;
	}
	if (n == MAX_ITER)
		return (n);
	return (n + 1 - log(log2(ft_module(z))));
}

int	mandelbrot_4(const t_point c)
{
	t_point	z;
	int		n;

	n = 0;
	z = ft_init_point(0, 0);
	while (ft_module(z) <= 2 && n < MAX_ITER)
	{
		z = ft_plus(ft_sqaure(ft_sqaure(z)), c);
		n++;
	}
	if (n == MAX_ITER)
		return (n);
	return (n + 1 - log(log2(ft_module(z))));
}

int	julia(t_point z)
{
	t_point	c;
	int		n;

	n = 0;
	c = ft_init_point(-0.8, 0.156);
	while (ft_module(z) <= 2 && n < MAX_ITER)
	{
		z = ft_plus(ft_sqaure(z), c);
		n++;
	}
	if (n == MAX_ITER)
		return (n);
	return (n + 1 - log(log2(ft_module(z))));
}

int	flower(const t_point c)
{
	t_point	z;
	int		n;

	n = 0;
	z = ft_init_point(0, 0);
	while (ft_module(z) <= 2 && n < MAX_ITER)
	{
		z = ft_plus(ft_cos_z(z), ft_fraction(c));
		n++;
	}
	if (n == MAX_ITER)
		return (n);
	return (n + 1 - log(log2(ft_module(z))));
}
