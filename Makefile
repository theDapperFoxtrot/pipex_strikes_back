NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = main_pipex.c pipex.c ft_init_pipex.c ft_parse_commands.c ft_parse_commands_helpers.c ft_validate_path.c ft_error.c ft_cleanup.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all
