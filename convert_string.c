# include "ft_printf.h"

static void ft_string_pre(int *len, int *k, t_args *elem)
{
    int i;
    char space;

    i = 0;
    space = (elem[*k].pre_zero == 0) ? ' ' : '0';
    if (elem[*k].end_space == 0)
    {
        if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1)
        {
            if (elem[*k].precision < *len)
                while (i++ < elem[*k].width - elem[*k].precision)
                    ft_putchar(space);
            else
                while (i++ < elem[*k].width - *len)
                    ft_putchar(space);
        }
        else if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1)
            while (i++ < elem[*k].width - *len)
                ft_putchar(space);
    }
}

static void ft_string_end_space(int *len, int *k, t_args *elem)
{
    int i;

    i = 0;
    if (elem[*k].end_space == 1)
    {
        if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1)
        {
            if (elem[*k].precision < *len)
                while (i++ < elem[*k].width - elem[*k].precision)
                    ft_putchar(' ');
            else
                while (i++ < elem[*k].width - *len)
                    ft_putchar(' ');
        }
        else if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1)
            while (i++ < elem[*k].width - *len)
                ft_putchar(' ');
    }
}

int		ft_print_string(char *value, int *k, t_args *elem)
{
    int i;
    int len;

    i = 0;
    len = 0;
    if (value == NULL)
        len = 6;
    else
        len = (int)ft_strlen(value);
    ft_string_pre(&len, k, elem);
    if (value != NULL)
    {
        if (elem[*k].ok_precision == 1 && elem[*k].precision < (int)ft_strlen(value))
           write(1, value, elem[*k].precision);
        else
            ft_putstr(value);
    }
    else
    {
        if (elem[*k].ok_precision == 1 && elem[*k].precision < 6)
           write(1, "(null)", elem[*k].precision);
        else
            ft_putstr("(null)");
    }
    ft_string_end_space(&len, k, elem);
	return (len);
}
