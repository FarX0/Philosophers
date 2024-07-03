NAME		= philo

SRC = src/main.c \

INCLUDES = ./includes

ARG = 1 3 2

FLAGS		= -Wall -Werror -Wextra -g

OBJS		= $(SRC:%.c=%.o)

# -s : for valgrind
$(NAME): $(OBJS)
	@cc $(OBJS) $(FLAGS) -I $(INCLUDES) -o $(NAME) -s
	@echo "$(GREEN)[PHILO]:\t PROJECT COMPILED$(RESET)"

all:$(NAME)

%.o: %.c
	@cc -c $< -o $@ $(FLAGS) -I $(INCLUDES)

clean:
	@rm -fr $(OBJS)
	@echo "$(RED)[PHILO]:\t CLEAN$(RESET)"

fclean: clean
	@rm -f *.a
	@rm -f *.out
	@rm -f *.gch
	@rm -f $(NAME)
	@echo "$(RED)[PHILO]:\t FCLEAN$(RESET)"

re: fclean all

test: all
	 ./$(NAME) $(ARG)

val: all
	 valgrind --leak-check=full --track-origins=yes -s --show-leak-kinds=all ./$(NAME) $(ARG)

#COLORS

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
RESET=\033[0m