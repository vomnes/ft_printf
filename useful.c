# include "ft_printf.h"

int		ft_nb_pct(const char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '%')
				i++;
			else
				count++;
		}
		i++;
	}
	return (count);
}

void ft_init_struct(t_args *elem)
{
    ft_bzero(elem->prefix, 3);
    elem->pre_hash = 0;
    elem->pre_zero = 0;
    elem->end_space = 0;
    elem->pre_sign = 0;
    elem->pre_blank = 0;
    elem->ok_width = 0;
    elem->width = 0;
    elem->ok_precision = 0;
    elem->precision = 0;
}

int		ft_is_type(int c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C');
}

void ft_printf_struct(t_args *elem)
{
    ft_putchar('\n');
    ft_putstr("elem->prefix:  ");
    ft_putendl(elem->prefix);
    ft_putstr("elem->pre_hash:  ");
    ft_putnbr(elem->pre_hash);
    ft_putchar('\n');
    ft_putstr("elem->pre_zero:  ");
    ft_putnbr(elem->pre_zero);
    ft_putchar('\n');
    ft_putstr("elem->end_space:  ");
    ft_putnbr(elem->end_space);
    ft_putchar('\n');
    ft_putstr("elem->pre_sign:  ");
    ft_putnbr(elem->pre_sign);
    ft_putchar('\n');
    ft_putstr("elem->pre_blank:  ");
    ft_putnbr(elem->pre_blank);
    ft_putchar('\n');
    ft_putstr("elem->ok_width:  ");
    ft_putnbr(elem->ok_width);
    ft_putchar('\n');
    ft_putstr("elem->width:  ");
    ft_putnbr(elem->width);
    ft_putchar('\n');
    ft_putstr("elem->ok_precision:  ");
    ft_putnbr(elem->ok_precision);
    ft_putchar('\n');
    ft_putstr("elem->precision:  ");
    ft_putnbr(elem->precision);
}
