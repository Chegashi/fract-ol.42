/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:48:33 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/10 14:38:20 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!p)
		return (NULL);
	while (i < ft_strlen(src))
	{
		p[i] = src[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_strlen(char *str)
{
	char	*end;

	end = str;
	while (*end)
		end++;
	return (end - str);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
	}
}
