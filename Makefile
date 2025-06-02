CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRCS = ft_printf.c ft_putnbr_fd.c ft_strlen.c ft_printoth.c ft_printstr.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
