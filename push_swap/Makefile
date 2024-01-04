# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 15:58:49 by erho              #+#    #+#              #
#    Updated: 2024/01/01 19:12:10 by erho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
MANMAIN = mandatory/main.c
SRCS =  mandatory/print_utils.c mandatory/stack_utils.c \
		mandatory/length.c mandatory/push.c mandatory/swap.c mandatory/utils.c \
		mandatory/ft_sort.c mandatory/rotate.c mandatory/rotate_commands.c \
		mandatory/set_sort.c mandatory/sort_utils.c mandatory/find.c \
		mandatory/cost.c
BSRCS = bonus/checker_bonus.c
MOBJS = $(MANMAIN:.c=.o)
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS = checker
HIR = includes
LIBFT = ./libft/libft.a

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJS) $(MOBJS)
	make -C libft all
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) $(MOBJS) -o $(NAME)

$(BONUS) : $(OBJS) $(BOBJS)
	make -C libft all
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) $(BOBJS) -o $(BONUS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HIR)

clean :
	make clean -C libft
	rm -f $(OBJS)
	rm -f $(MOBJS)
	rm -f $(BOBJS)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)
	rm -f $(BONUS)

re :
	make fclean
	make all

.PHONY : all clean fclean re
