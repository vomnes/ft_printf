NAME = libftprintf.a
SRC_PF = check_errors.c convert_binary.c convert_char.c convert_date.c \
convert_hex.c convert_octal.c convert_ptr.c convert_signed.c convert_string.c \
convert_unsigned.c convert_wstr.c ft_is.c ft_printf.c get_value.c \
manage_date.c manage_hex.c manage_octal.c manage_octal_2.c manage_signed.c \
manage_wstr.c parsing_one.c parsing_two.c useful.c wchar.c

SRC_LFT = ft_memset.c ft_bzero.c ft_isdigit.c ft_memalloc.c ft_putchar.c \
ft_putendl.c ft_putnbr.c ft_putstr.c ft_putwstr.c ft_strclr.c ft_strcpy.c \
ft_strlen.c ft_putwchar.c

OBJET_PF = $(SRC_PF:.c=.o)
OBJET_LFT = $(SRC_LFT:.c=.o)
LIBFT_PATH =  ./libft

FLAGS = -Wall -Werror -Wextra

LIB = $(addprefix $(LIBFT_PATH)/, $(OBJET_LFT))
GCC = gcc
AR = ar
ARFLAGS = rc
MAKE = make

.PHONY: clean fclean all re

all: $(NAME) compile
	@echo > /dev/null

$(NAME): $(OBJET_PF)
		@$(MAKE) -C $(LIBFT_PATH)
		@echo Compiling $(NAME)
		@$(GCC) $(FLAGS) -c $(SRC_PF)
		@$(AR) $(ARFLAGS) $(NAME) $(OBJET_PF) $(LIB)
		@ranlib $(NAME)
		@echo ======[Done]======

compile:
		@$(MAKE) -C $(LIBFT_PATH)

clean:
		@$(MAKE) clean -C $(LIBFT_PATH)
		@echo Clean objects $(NAME)
		@rm -rf $(OBJET_PF)

fclean: clean
		@$(MAKE) fclean -C $(LIBFT_PATH)
		@echo Clean $(NAME)
		@rm -rf $(NAME)
		@echo ======[Clean]======

re: fclean all
