NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
SRCS = ft_printf.c ft_printf_utils.c ft_printfpointer.c ft_printfhexa.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
