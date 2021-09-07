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
# define WIDTH 500
# define HEIGHT 500
# define ESC 53 
# define ZOOM_IN 5
# define ZOOM_OUT 4
# define MAX_ITER 100
# define RE_START -2
# define RE_END 1
# define IMG_START -1
# define IMG_END 1

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;
	x = -1;
	y = -1;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			// c = ft_init_point(RE_START + x / WIDTH * (RE_END - RE_START),
			// 		IMG_START + x / HEIGHT * (IMG_END - IMG_START));
			// n = mandelbrot(c);
			// // color = 255 - (int)(n * 255 / MAX_ITER);
			// color = 564;
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			// printf("{%d|%d}\n", x,y);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return 0;
}
