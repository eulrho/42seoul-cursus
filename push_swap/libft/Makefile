# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 15:59:02 by erho              #+#    #+#              #
#    Updated: 2023/12/26 17:02:08 by erho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = format.c ft_printf_utils.c \
		ft_printf.c ft_put.c ft_putchar.c ft_putstr.c ft_split.c \
		ft_strlcat.c ft_strlen.c get_next_line.c get_next_line_utils.c \
		ft_putstr_fd.c
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
