# include "ft_printf.h"

int		ft_print_char(int value, int *k, t_args *elem)
{
    int i;

    i = 0;
    if (elem[*k].end_space == 0)
        while (i++ < elem[*k].width - 1)
            ft_putchar((elem[*k].pre_zero == 0) ? ' ' : '0');
    ft_putchar(value);
    i = 0;
    if (elem[*k].end_space == 1)
        while (i++ < elem[*k].width - 1)
            ft_putchar(' ');
	return (0);
}
