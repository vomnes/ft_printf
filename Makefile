NAME = libftprintf.a
SRC = convert_unsigned.c manage_octal.c convert_wstr.c manage_octal_2.c \
ft_printf.c manage_signed.c convert_char.c parsing_one.c convert_hex.c \
get_value.c parsing_two.c convert_octal.c useful.c convert_ptr.c wchar.c \
convert_signed.c convert_string.c manage_hex.c convert_binary.c \
convert_date.c manage_date.c
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
