/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:20:27 by mochegri          #+#    #+#             */
/*   Updated: 2022/08/02 00:36:33 by mochegri         ###   ########.fr       */
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
# define MSG "usage : fractol [fractals]\nfractals:"

# define WIDTH 1000
# define HEIGHT 1000
# define ESC 53
# define ZOOM_IN 5
# define ZOOM_OUT 4
# define MAX_ITER 255
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEEFT 124
# define KEY_RIGHT 123
# define KEY_PLUS 69
# define KEY_MOIS 79

typedef struct s_point
{
	long double			x;
	long double			y;
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
	long double		re_start;
	long double		re_end;
	long double		img_start;
	long double		img_end;
	long double		len_x;
	long double		len_y;
	void			*win_ptr;
	void			*mlx_ptr;
	char			*name;
	t_data			img;
	int				b;
}	t_fractol;

typedef struct s_steps
{
	t_point		point;
	long double	dx_step;
	long double	dy_step;
	long double	dxx_step;
	long double	dyy_step;
}	t_steps;

char		*ft_strdup(char *src);
char		*ft_check_arg(int ac, char **av);
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(char *str);
int			key_hook(int keycode, t_fractol *fractol);
void		ft_putstr(char *str);
void		ft_init_fractal(t_fractol *fractol);
void		ft_clean_win(t_data *data);
int			ft_exit(t_fractol *fractol);
int			mouse_hook(int button, int x, int y, t_fractol *fractol);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		my_mlx_pixl_put(t_data *data, int x, int y, int color);
void		ft_render(t_fractol *fractol);
long double	ft_module(const t_point z);
t_point		ft_plus(t_point z1, const t_point z2);
t_point		ft_sqaure(const t_point z);
t_point		ft_init_point(const long double x, const long double y);
int			mandelbrot(t_point c);
int			create_trgb(int t, int r, int g, int b);
int			ft_fractol(t_point p, t_fractol fractol);
t_point		ft_transposer(const t_point z, t_fractol fractol);
t_point		mac2rod(t_point pixel, t_fractol fractol);
t_point		rod2mac(t_point p1, t_fractol fractol);
int			ft_fractal_is_def(char *s);
int			mandelbrot_4(t_point c);
int			julia(t_point z, t_point c);
t_point		ft_fraction(t_point z1);
t_point		ft_cos_z(t_point z);
int			flower(t_point c);
void		ft_color_key(int keycode, t_fractol *fractol);
#endif
