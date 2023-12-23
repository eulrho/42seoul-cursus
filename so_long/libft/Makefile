# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 13:38:20 by erho              #+#    #+#              #
#    Updated: 2023/12/17 13:39:38 by erho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_put.c ../srcs/length.c ft_printf.c format.c ft_printf_utils.c \
		get_next_line.c get_next_line_utils.c ft_calloc.c ft_split.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
HDIR = includes

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c
	cc $(CFLAGS) -c $< -o $@ -I${HDIR}

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
