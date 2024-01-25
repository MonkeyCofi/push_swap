NAME = push_swap

SRCS = push_swap.c parse_args.c stack_functions.c stack_functions2.c moves.c sort.c

LIBFT = ./libft/libft.a

LIBFT_DIR = ./libft/

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	cc $(CFLAGS) $(LIBFT) $^ -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f *.o

fclean: clean
	rm -f libft/libft.a
	rm -f push_swap

re: fclean all