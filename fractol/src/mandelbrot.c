/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:18:26 by mochegri          #+#    #+#             */
/*   Updated: 2022/08/01 23:34:33 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_point c)
{
	t_point	z;
	int		n;

	n = -1;
	z = ft_init_point(0, 0);
	while (ft_module(z) <= 2 && ++n < MAX_ITER)
		z = ft_plus(ft_sqaure(z), c);
	return (n);
}

int	mandelbrot_4(t_point c)
{
	t_point	z;
	int		n;

	n = -1;
	z = ft_init_point(0, 0);
	while (ft_module(z) <= 2 && ++n < MAX_ITER)
		z = ft_plus(ft_sqaure(ft_sqaure(z)), c);
	return (n);
}

int	julia(t_point z, t_point c)
{
	int		n;

	n = -1;
	while (ft_module(z) <= 2 && ++n < MAX_ITER)
		z = ft_plus(ft_sqaure(z), c);
	return (n);
}

int	flower(t_point z)
{
	t_point	c;
	int		n;

	n = -1;
	c = ft_init_point(0, 0);
	while (ft_module(z) <= 2 && n < MAX_ITER)
		z = ft_plus(ft_cos_z(z), ft_fraction(c));
	return (n);
}
