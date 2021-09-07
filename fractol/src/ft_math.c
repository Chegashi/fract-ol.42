/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:21:10 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/07 19:24:23 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_module(t_point z)
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

t_point	ft_init_point(const double x, const double y)
{
	t_point	z;

	z.x = x;
	z.y = y;
	return (z);
}
