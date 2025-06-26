NAME		= PmergeMe
CPP			= c++
CPPFLAGS	= -std=c++98 -Wall -Wextra -Werror
RM			= rm -rf
OBJ			= $(SRCS:.cpp=.o)
SRCS		= main.cpp PmergeMe.cpp

all: $(NAME)

$(NAME): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

e: fclean all
	./$(NAME) 1 2 3 4 5
	./$(NAME) 3 5 9 7 4
	./$(NAME) `shuf -i 1-42 -n 31 | tr "\n" " "`

.PHONY: all clean fclean re e
