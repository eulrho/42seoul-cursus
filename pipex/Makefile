# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 15:58:49 by erho              #+#    #+#              #
#    Updated: 2024/01/24 21:50:29 by erho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SRCS = mandatory/main.c mandatory/run.c mandatory/utils.c \
		mandatory/error_handling.c mandatory/set.c \
		mandatory/parse.c mandatory/parse_utils.c
BSRCS = bonus/main_bonus.c bonus/run_bonus.c bonus/utils_bonus.c \
		bonus/error_handling_bonus.c \
		bonus/parse_bonus.c bonus/parse_utils_bonus.c \
		bonus/run_utils_bonus.c bonus/set_bonus.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
HIR = includes
LIBFT = ./libft/libft.a
RM = rm -f

ifdef WITH_BONUS
	OBJ_SWITCH = $(BOBJS)
	REMOVE = $(OBJS)
else
	OBJ_SWITCH = $(OBJS)
	REMOVE = $(BOBJS)
endif

all : $(NAME)

$(NAME) : $(OBJ_SWITCH) $(LIBFT)
	$(RM) $(REMOVE)
	$(CC) $(LIBFT) $(OBJ_SWITCH) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HIR)

$(LIBFT) :
	make -C libft all

bonus :
	make WITH_BONUS=1 all

clean :
	make clean -C libft
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	make fclean -C libft
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus
