/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:04:46 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/11 17:56:27 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point	ft_cos_z(t_point z)
{
	return (ft_init_point(cos(z.x) * coshl(z.y), -1 * sin(z.x) * sinhl(z.y)));
}

t_point	ft_fraction(t_point z1)
{
	return (ft_init_point(z1.x / (z1.x * z1.x + z1.y * z1.y),
			(-1 * z1.y) / (z1.x * z1.x + z1.y * z1.y)));
}
