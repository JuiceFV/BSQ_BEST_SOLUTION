NAME = bsq
FILES = bsq.c ft_bitset.c ft_iostream.c funcs.c bitset_func.c

.PHONY: all clean fclean re

all:
	@gcc -Wall -Wextra -Werror -o $(NAME) $(FILES)

clean:
	@rm -f *.o

fclean: clean
	@rm bsq

re: fclean all
