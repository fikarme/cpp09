NAME		= btc
CPP			= c++
CPPFLAGS	= -std=c++98 -Wall -Wextra -Werror
RM			= rm -rf
OBJS		= $(SRCS:.cpp=.o)
SRCS		= main.cpp BitcoinExchange.cpp

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
	@./$(NAME)

.PHONY: all clean fclean re e
