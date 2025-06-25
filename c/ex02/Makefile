NAME = PmergeMe
FLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++
RM = rm -rf

SRCS = main.cpp PmergeMe.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@$(CPP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	@$(RM) $(NAME)

fclean:clean

re: clean all

e: fclean all
	./$(NAME) 3 5 9 7 4
	
.PHONY:all re clean fclean
