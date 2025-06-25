NAME		= RPN
CPP			= c++
CPPFLAGS	= -std=c++98 -Wall -Wextra -Werror
RM			= rm -rf
OBJS		= $(SRCS:.cpp=.o)
SRCS		= main.cpp RPN.cpp

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

e: fclean all
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	./$(NAME) "7 7 * 7 -"
	./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	./$(NAME) "(1 + 1)"

.PHONY: all clean fclean re e
