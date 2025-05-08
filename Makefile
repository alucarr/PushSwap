NAME = push_swap
CC = gcc
SRC= main.c check_arg.c data_controller.c ft_split.c utils.c utils2.c mini_sorter.c pab.c \
	psr.c radix.c utils3.c
CFLAGS =-Wall -Wextra -Werror -fsanitize=address -g 

GREEN := \033[1;32m
RED := \033[1;41m
END := \033[0;39m

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	@gcc $(SRC) -o $(NAME) $(CFLAGS)
	@echo "$(GREEN)Compile Completed!$(END)"

clean:
	@rm -rf $(OBJ)
	@echo "$(RED)Cleaning Completed!$(END)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re