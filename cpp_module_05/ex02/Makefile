CXX			= c++
NAME		= ex02
HEADER_DIR	= .
CPP_FLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f
SRCSNAME	= main Bureaucrat AForm PresidentialPardonForm RobotomyRequestForm ShrubberyCreationForm
SRCS		= $(addsuffix .cpp, $(SRCSNAME))
OBJS		= $(addsuffix .o, $(SRCSNAME))
DEPS		= $(addsuffix .d, $(SRCSNAME))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) -I $(HEADER_DIR) $(CPP_FLAGS) -o $(NAME) $(OBJS)

-include $(DEPS)

%.o : %.cpp
	$(CXX) -I $(HEADER_DIR) $(CPP_FLAGS) -c $< -o $@ -MMD

clean:
	$(RM) $(OBJS)
	$(RM) $(DEPS)

fclean : clean
	$(RM) $(NAME)

re : fclean all