SRCS = ft_put.c ft_length.c ft_printf.c print_control.c ft_utils.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
HEAD = ft_printf.h

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c ${HEAD}
	cc $(CFLAGS) -c $< ${HEAD}

clean :
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
