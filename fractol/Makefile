# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 15:08:16 by mochegri          #+#    #+#              #
#    Updated: 2022/08/02 00:32:41 by mochegri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

flags = -Wall -Wextra -Werror -g
SRCS = 	src/main.c \
		src/libft.c \
		src/win.c \
		src/key.c \
		src/render.c \
		src/ft_math.c \
		src/mandelbrot.c \
		src/ft_math2.c \

MAND = $(SRCS)

$(NAME): $(SRCS)
	@gcc $(flags) -c $(SRCS) 
	@ar -rc fractol.a *.o
	@ranlib fractol.a 
	@gcc $(flags) -I /usr/local/include fractol.a -L /usr/local/lib/ \
	-lmlx -framework OpenGL -framework AppKit -o $(NAME) -I0g -Ofast
	@rm *.o
	@rm fractol.a


all : $(NAME)

clean:
	@rm -f $(SRC:.c=.o) $(MAND:.c=.o) fractol

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

Julia: re
	./fractol Julia

Julia_1: re
	./fractol Julia_1

Julia_2: re
	./fractol Julia_2

Julia_3: re
	./fractol Julia_3

Julia_4: re
	./fractol Julia_4

Julia_5: re
	./fractol Julia_5

Julia_6: re
	./fractol Julia_6

Julia_7: re
	./fractol Julia_7

Julia_8: re
	./fractol Julia_8

Julia_9: re
	./fractol Julia_9

Mandelbrot : re
	./fractol Mandelbrot

Mandelbrot_4 : re
	./fractol Mandelbrot_4

Flower: re
	./fractol Flower