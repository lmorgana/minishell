CC = gcc

NAME = minishell

CFLAGS = -Wall -Wextra -Werror

HEADERS = header.h parser/parser.h signal/signal.h gnl/get_next_line.h

SRC = main.c \
	bins/ft_check_for_bin.c bins/utils.c bins/ft_pids.c \
	bins/ft_mk_execve.c bins/ft_wait_for_all_pids.c\
	our_func/ft_mk_our_func.c utils/ft_print_error.c \
	our_func/ft_our_export.c env/ft_get_our_env.c \
	env/env_utils.c env/env_utils2.c env/env_utils3.c parser/convertTokenInExc.c \
	parser/elementInQuote.c parser/outputError.c parser/parser.c \
	parser/parser_utils.c parser/preparser.c  parser/parser_utils2.c\
	parser/token.c parser/convertTokenInExc_utils1.c parser/convertTokenInExc_utils2.c\
	signal/hook.c gnl/get_next_line.c gnl/get_next_line_utils.c parser/doubleRed.c \
	our_func/ft_our_unset.c our_func/ft_our_cd.c env/env_utils4.c our_func/ft_our_echo.c \
	our_func/ft_our_exit.c

OBJECTS = $(patsubst %.c, %.o, $(SRC))

LIBFT_LIB = libft/libft.a

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -lreadline -L/Users/$(USER)/.brew/Cellar/readline/8.1/lib/ -I/Users/$(USER)/.brew/Cellar/readline/8.1/include $(OBJECTS) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C libft bonus

clean:
	 $(MAKE) -C libft clean
	-rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C libft fclean
	-rm -f $(OBJECTS) $(OBJECTS_BONUS)
	-rm -f $(NAME)

re: fclean all

.PHONY: all