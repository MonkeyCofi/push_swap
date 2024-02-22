NAME = push_swap

SRCS = push_swap.c parse_args.c stack_functions.c stack_functions2.c moves.c sort.c check_stacks.c \
		median.c moves2.c sort_utils.c

SRCS_BONUS = checker.c

LIBFT_DIR = ./libft/

LIBFT = $(LIBFT_DIR)libft.a

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

bonus: $(SRCS_BONUS) $(LIBFT)
	cc checker.c $(OBJS) $(LIBFT) -o checker

#$(NAME): $(OBJS) $(LIBFT)
#	cc $(CFLAGS) $(LIBFT) $^ -o $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	cc $(CFLAGS) $(LIBFT) $^ -o $(NAME)
	make clean

clean:
	make -C $(LIBFT_DIR) clean
	rm -f *.o

fclean: clean
	rm -f libft/libft.a
	rm -f push_swap

re: fclean all