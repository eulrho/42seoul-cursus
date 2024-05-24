# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 21:37:54 by erho              #+#    #+#              #
#    Updated: 2024/03/05 21:34:05 by erho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SRCS = main.c philo_atoi.c set.c philo_isnum.c run.c routine.c monitoring.c eat.c \
		ft_free.c ft_usleep.c set_helper.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
#CFLAGS += -g -fsanitize=thread
NAME = philo
HIR = includes
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HIR)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
