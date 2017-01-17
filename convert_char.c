# include "ft_printf.h"

int		ft_print_char(int value, int *k, t_args *elem)
{
    int i;

    i = 0;
    if (elem[*k].end_space == 0 && elem[*k].ok_width == 1)
        while (i++ < elem[*k].width - 1)
            ft_putchar((elem[*k].pre_zero == 0) ? ' ' : '0');
    ft_putchar(value);
    i = 0;
    if (elem[*k].end_space == 1 && elem[*k].ok_width == 1)
        while (i++ < elem[*k].width - 1)
            ft_putchar(' ');
	return (1);
}

int		ft_print_wchar(wchar_t value, int *k, t_args *elem)
{
    int i;

    i = 0;
    if ((int)value< 0 || (((int)value > 0xD7FF && (int)value < 0xE000))
    || ((int)value > 0x10FFFF))
        return (-1);
    if (elem[*k].end_space == 0 && elem[*k].ok_width == 1)
        while (i++ < elem[*k].width - (int)ft_sizewchar(value))
            ft_putchar((elem[*k].pre_zero == 0) ? ' ' : '0');
    ft_putwchar_all(value);
    i = 0;
    if (elem[*k].end_space == 1 && elem[*k].ok_width == 1)
        while (i++ < elem[*k].width - (int)ft_sizewchar(value))
            ft_putchar(' ');
	return ((int)ft_sizewchar(value));
}
