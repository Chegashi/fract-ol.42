# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 15:08:16 by mochegri          #+#    #+#              #
#    Updated: 2021/09/06 15:33:35 by mochegri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

flags = -Wall -Wextra -Werror
SRCS = 	src/main.c \
		src/libft.c \
		src/win.c \
		src/key.c \
		src/render.c \

MAND = $(SRCS)

$(NAME): $(SRCS)
	@gcc $(flags) -c $(SRCS) 
	@ar -rc fractol.a *.o
	@ranlib fractol.a 
	@gcc $(flags) -I /usr/local/include fractol.a -L /usr/local/lib/ \
	-lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@rm *.o
	@rm fractol.a

# $(NAME_b): $(SRCS)
# 	gcc $(flags) -c $(SRCS) -D BONUS=1
# 	@ar -rc fractol.a *.o
# 	@ranlib fractol.a 
# 	@gcc $(flags) -I /usr/local/include fractol.a -L /usr/local/lib/ \
# 	-lmlx -framework OpenGL -framework AppKit src/libmlx.dylib -o $(NAME)
# 	@rm *.o
# 	@rm fractol.a

all : $(NAME)

clean:
	@rm -f $(SRC:.c=.o) $(MAND:.c=.o) fractol

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

Julia: re
	./fractol Julia

Mandelbrot : re
	./fractol Mandelbrot