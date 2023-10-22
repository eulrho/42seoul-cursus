SRCS = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c ft_strlen.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c
BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
HEAD = libft.h

all : $(NAME)

bonus : $(NAME) $(BOBJS)
	ar rc $(NAME) $(BOBJS)
	touch bonus

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
# 만약 head를 의존대상에 포함하지 않는다면 head 수정 후에 link 안됨
%.o : %.c ${HEAD}
	cc $(CFLAGS) -c $< ${HEAD}

clean :
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME) bonus
# 분리 안해주면 make -j 4 re 명령어 실행 시 터짐 
re :
	make fclean
	make all

.PHONY : all clean fclean re
