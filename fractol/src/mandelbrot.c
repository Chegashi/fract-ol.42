/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:18:26 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/09 20:00:17 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
** mandekbrot
** julia
*/

int	mandelbrot(t_point c)
{
	t_point	z;
	int		n;

	n = 0;
	z.x = 0;
	z.y = 0;
	while (ft_module(z) <= 2 && n < MAX_ITER)
	{
		z = ft_plus(ft_sqaure(z), c);
		n++;
	}
	if (n == MAX_ITER)
		return (n);
	return (n + 1 - log(log2(ft_module(z))));
}
