/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:20:27 by mochegri          #+#    #+#             */
/*   Updated: 2021/09/07 19:35:12 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include <math.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# define MSG "usage : fractol [fractals]\nfractals \
	:\n--> Mandelbrot\n--> Julia\n"
# define WIDTH 600
# define HEIGHT 600
# define ESC 53 
# define ZOOM_IN 5
# define ZOOM_OUT 4
# define MAX_ITER 80
# define RE_START -2
# define RE_END 1
# define IMG_START -1
# define IMG_END 1

typedef struct s_point
{
	double			x;
	double			y;
}	t_point;

typedef struct s_data
{
	int				bpp;
	int				l_len;
	int				endian;
	char			*addr;
	void			*img;
}	t_data;

typedef struct s_fractol
{
	int				width;
	int				hight;
	void			*win_ptr;
	void			*mlx_ptr;
	char			*name;
	t_data			img;
}	t_fractol;

char	*ft_strdup(const char *src);
char	*ft_check_arg(int ac, char **av);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(const char *str);
int		key_hook(int keycode, t_fractol *fractol);
void	ft_putstr(char *str);
void	ft_init_fractal(t_fractol *fractol);
void	ft_clean_win(t_fractol *fractol);
int		ft_exit(t_fractol *fractol);
int		mouse_hook(int button, int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_mlx_pixl_put(t_data *data, int x, int y, int color);
void	ft_render(t_fractol *fractol);
double	ft_module(t_point z);
t_point	ft_plus(t_point z1, t_point z2);
t_point	ft_sqaure(t_point z);
t_point	ft_init_point(const double x, const double y);
int		mandelbrot(t_point c);
int	create_trgb(int t, int r, int g, int b);
#endif