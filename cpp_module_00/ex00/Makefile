NAME		= megaphone
CXX			= c++
RM			= rm -f
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS		= megaphone.cpp
OBJS		= $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY : all clean fclean re