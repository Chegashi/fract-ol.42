/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:04:41 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/06 15:31:16 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y)
{
	printf("{%d}{%d,%d}\n", button, x, y);
	return (0);
}

int	key_hook(int keycode, t_fractol *fractol)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
		ft_exit(fractol);
	return (0);
}
