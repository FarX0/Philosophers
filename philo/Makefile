NAME		= philo

SRC = src/main.c \
	src/parsing.c \
	src/cleaning.c \
	src/initailize.c \
	src/utils/utils.c \

INCLUDES = ./includes

ARG = 2a 2 3 4 5

FLAGS		= -Wall -Werror -Wextra -g
# FLAGS		= -g

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