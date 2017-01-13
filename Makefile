NAME = libftprintf.a
SRC = ft_printf.c parsing_one.c parsing_two.c adapt_args.c convert_hex.c \
get_value.c manage_hex.c useful.c
OBJET = $(SRC:.c=.o)
FLAGS =

.PHONY: clean fclean all

all: $(NAME)

$(NAME):
			gcc $(FLAGS) -c $(SRC)
			ar rc $(NAME) $(OBJET) ./libft/*.o
			ranlib $(NAME)

clean:
			rm -rf $(OBJET)

fclean: clean
			rm -rf $(OBJET) $(NAME)

re: fclean all
