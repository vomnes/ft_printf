# include "ft_printf.h"

int		ft_print_wstr(const wchar_t *value, int *k, t_args *elem)
{
    int i;
    int len;

    i = 0;
    len = 0;
    if (value == NULL)
        len = 6;
    else
        while (value[i] != L'\0')
            len += ft_sizewchar(value[i++]);
    i = 0;
    if (elem[*k].end_space == 0 && elem[*k].ok_width == 1)
        while (i++ < elem[*k].width - len)
            ft_putchar((elem[*k].pre_zero == 0) ? ' ' : '0');
    i = 0;
    if (value != NULL)
        while (i < elem[*k].precision && (value[i] != L'\0'))
    		ft_putwchar_all(value[i++]);
    else
        ft_putstr("(null)");
    i = 0;
    if (elem[*k].end_space == 1 && elem[*k].ok_width == 1)
        while (i++ < elem[*k].width - len)
            ft_putchar(' ');
    return (len);
}
