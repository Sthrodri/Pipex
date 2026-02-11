NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = src/pipex.c\
       src/pipex_utils.c\
	   libft/libft.a\

$(NAME):
		make all -C libft
		cc $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
		$(RM) $(NAME)
		make clean -C libft

fclean: clean
		$(RM) $(NAME)
		make fclean -C libft

re: fclean all
