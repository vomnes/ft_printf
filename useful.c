# include "ft_printf.h"

void ft_init_struct(t_args *elem, int *k)
{
    ft_bzero(elem[*k].prefix, 3);
	elem[*k].start = 0;
    elem[*k].ok_start = 0;
	elem[*k].end = 0;
	elem[*k].new_start = 0;
	elem[*k].nb_arg = 0;
    elem[*k].pre_hash = 0;
    elem[*k].pre_zero = 0;
    elem[*k].end_space = 0;
    elem[*k].pre_sign = 0;
    elem[*k].pre_blank = 0;
    elem[*k].ok_width = 0;
    elem[*k].width = 0;
	elem[*k].wildcard_width = 0;
    elem[*k].ok_precision = 0;
    elem[*k].precision = 0;
	elem[*k].wildcard_precision = 0;
	elem[*k].type = 0;
	elem[*k].i_nb = 0;
	elem[*k].u_nb = 1;
}

size_t	ft_nb_pct(const char *s)
{
	int i;
	int count;
	int is_arg;

	i = 0;
	is_arg = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] == '%')
			i++;
        if (is_arg == 1 && s[i] == '%')
            i += 2;
		if (is_arg == 1 && ft_is_type(s[i]) == 1)
            is_arg = 0;
		if (s[i - 1] != '%' && s[i] == '%' && s[i + 1] != '%' && is_arg == 0)
        {
            count++;
            is_arg = 1;
        }
		i++;
	}
	return (count);
}

int		ft_is_type(int c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%');
}

int		ft_is_type_less_pct(int c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C');
}

int		ft_is_flag(int c)
{
	return (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ');
}

int		ft_is_signed(int c)
{
	return (c == 'D' || c == 'd' || c == 'i');
}

int		ft_is_length(int c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'z');
}

void ft_printf_struct(t_args *elem, int *k)
{
    ft_putchar('\n');
    //ft_putstr("elem->prefix:  ");
    ft_putendl(elem[*k].prefix);
    ft_putstr("#:  ");
    ft_putnbr(elem[*k].pre_hash);
    ft_putchar('\n');
    ft_putstr("0:  ");
    ft_putnbr(elem[*k].pre_zero);
    ft_putchar('\n');
    ft_putstr("-:  ");
    ft_putnbr(elem[*k].end_space);
    ft_putchar('\n');
    ft_putstr("+:  ");
    ft_putnbr(elem[*k].pre_sign);
    ft_putchar('\n');
    ft_putstr(" :  ");
    ft_putnbr(elem[*k].pre_blank);
    ft_putchar('\n');
    ft_putstr("ok_width:  ");
    ft_putnbr(elem[*k].ok_width);
    ft_putchar('\n');
    ft_putstr("width:  ");
    ft_putnbr(elem[*k].width);
    ft_putchar('\n');
	ft_putstr("wildcard_width:  ");
	ft_putnbr(elem[*k].wildcard_width);
	ft_putchar('\n');
    ft_putstr("ok_precision:  ");
    ft_putnbr(elem[*k].ok_precision);
    ft_putchar('\n');
    ft_putstr("precision:  ");
    ft_putnbr(elem[*k].precision);
	ft_putchar('\n');
	ft_putstr("wildcard_precision:  ");
	ft_putnbr(elem[*k].wildcard_precision);
	ft_putchar('\n');
	ft_putstr("-->start:  ");
	ft_putnbr(elem[*k].start);
	//ft_putchar('\n');
	ft_putstr(" end:  ");
	ft_putnbr(elem[*k].end);
	//ft_putchar('\n');
	ft_putstr(" --->type:  ");
	ft_putchar(elem[*k].type);
	ft_putchar('\n');
	//ft_putstr("length:  ");
	//ft_putnbr(elem[*k].length);
	//ft_putchar('\n');
}
