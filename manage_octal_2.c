# include "ft_printf.h"

static void ft_octal_zero_one_bis(const char *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].width <= elem[*k].precision)
        while (i++ < elem[*k].precision - elem[*k].size -
        ((value[0] != '0') ? 3 : 0))
            ft_putchar('0');
    else if (value[0] == '0')
        while (i++ < elem[*k].precision - 1)
            ft_putchar('0');
    else
        while (i++ < elem[*k].precision - elem[*k].size -
        (elem[*k].pre_hash ? 1 : 0) - 2)
            ft_putchar('0');
}

void ft_octal_zero_one(const char *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 0 &&
        elem[*k].pre_zero == 0 && elem[*k].pre_hash == 1)
    {
        while (i++ < elem[*k].precision - (int)ft_strlen(value) -
        ((value[0] != '0') ? 1 : 0))
            ft_putchar('0');
        if (value[0] == '0' && elem[*k].precision > 0 && value[0] != '0')
            ft_putchar('0');
    }
    if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1 &&
        elem[*k].pre_zero == 0 && elem[*k].pre_hash == 1)
            ft_octal_zero_one_bis(value, elem, k);
}


static void ft_octal_zero_two_bis(const char *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].pre_zero == 0)
    {
        while (i++ < elem[*k].width - elem[*k].precision)
            ft_putchar('0');
        while (i++ < elem[*k].precision - elem[*k].size)
            ft_putchar('0');
    }
    else
        while (i++ < elem[*k].precision - (int)ft_strlen(value) -
        ((elem[*k].pre_hash == 1 && value[0] != '0') ? 1 : 0))
            ft_putchar('0');
}

void ft_octal_zero_two(const char *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].pre_zero && elem[*k].ok_precision && !elem[*k].ok_width)
        while (i++ < elem[*k].precision - elem[*k].size)
            ft_putchar('0');
    if (elem[*k].pre_zero && elem[*k].ok_precision && elem[*k].ok_width)
    {
        if (elem[*k].width <= elem[*k].precision)
            while (i++ < elem[*k].precision - (int)ft_strlen(value) -
            ((elem[*k].pre_hash == 1) ? 1 : 0))
                ft_putchar('0');
        else
            ft_octal_zero_two_bis(value, elem, k);
    }
}

void ft_octal_end_space(const char *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].end_space == 1 && elem[*k].ok_width == 1 &&
        elem[*k].ok_precision == 0)
        while (i++ < elem[*k].width - elem[*k].size -
        ((elem[*k].pre_hash == 1 && value[0] != '0') ? 3 : 0))
            ft_putchar(' ');
    if ((elem[*k].end_space) && (elem[*k].ok_width) && (elem[*k].ok_precision))
    {
        if (elem[*k].width > elem[*k].precision)
        {
            if (elem[*k].precision <= ft_strlen(value))
                while (i++ < elem[*k].width - elem[*k].precision -
                ((int)ft_strlen(value) - elem[*k].precision) -
                ((elem[*k].pre_hash == 1 && value[0] != '0') ? 1 : 0))
                    ft_putchar(' ');
            else
                while (i++ < elem[*k].width - elem[*k].precision)
                    ft_putchar(' ');
        }
    }
}
