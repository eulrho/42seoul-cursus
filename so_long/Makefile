# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 13:38:40 by erho              #+#    #+#              #
#    Updated: 2023/12/17 13:39:40 by erho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SRCS = srcs/main.c srcs/length.c srcs/utils.c srcs/draw.c \
		srcs/draw_utils.c srcs/hook.c srcs/check_map.c srcs/check_file.c \
		srcs/print_error.c srcs/check_path.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
HIR = includes
CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit
LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft all
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) $(CLIB) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@ -I$(HIR)

clean :
	make clean -C libft
	rm -f $(OBJS)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
