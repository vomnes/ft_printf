
# include "ft_printf.h"

void ft_hex_basic_one(const char *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1 &&
        elem[*k].end_space == 0 && elem[*k].pre_zero == 0)
	{
		if (elem[*k].pre_hash == 0 || value[0] == '0')
			while (i++ < elem[*k].width - elem[*k].size)
				ft_putchar(' ');
		else
			while (i++ < elem[*k].width - ((int)ft_strlen(value) + 2))
				ft_putchar(' ');
	}
    if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 0 &&
        elem[*k].pre_zero == 0 && elem[*k].pre_hash == 0)
        while (i++ < elem[*k].precision - elem[*k].size)
            ft_putchar('0');
}

void ft_hex_basic_two(const char *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1 &&
        elem[*k].pre_zero == 0 && elem[*k].pre_hash == 0)
    {
        if (elem[*k].width <= elem[*k].precision)
            while (i++ < elem[*k].precision - elem[*k].size)
                ft_putchar('0');
        else if (elem[*k].precision <= ft_strlen(value) &&
            elem[*k].end_space == 0)
            while (i++ < elem[*k].width - elem[*k].precision -
                (ft_strlen(value) - elem[*k].precision))
                ft_putchar(' ');
        else
        {
            if (elem[*k].end_space == 0)
                while (i++ < elem[*k].width - elem[*k].precision)
                    ft_putchar(' ');
            i = 0;
            while (i++ < elem[*k].precision - elem[*k].size)
                ft_putchar('0');
        }
    }
}

void ft_hex_hash(const char *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1 &&
    elem[*k].pre_zero == 0 && elem[*k].pre_hash == 1 && elem[*k].end_space == 1)
        if ((elem[*k].precision < elem[*k].width) && value[0] == '0')
            ft_putchar('0');
    if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1 &&
    elem[*k].pre_zero == 0 && elem[*k].pre_hash == 1 && elem[*k].end_space == 0)
    {
        if (elem[*k].precision <= ft_strlen(value))
            while (i++ < elem[*k].width - elem[*k].precision -
            (int)ft_strlen(value))
                ft_putchar(' ');
        else
        {
            while (i++ < elem[*k].width - elem[*k].precision -
            (int)ft_strlen(value))
                ft_putchar(' ');
            if (elem[*k].width >= elem[*k].precision && value[0] == '0')
                ft_putchar(' ');
            if (value[0] == '0')
                ft_putchar('0');
        }
    }
}

static void ft_hex_zero_one_bis(const char *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].width <= elem[*k].precision)
        while (i++ < elem[*k].precision - elem[*k].size - (int)ft_strlen(value) + ((elem[*k].end_space == 1 && value[0] != '0') ? 0 : 1))
            ft_putchar('0');
    else
    {
        while (i++ < elem[*k].precision - elem[*k].size -
        (int)ft_strlen(value))
            ft_putchar('0');
    }
}

void ft_hex_zero_one(const char *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 0 &&
        elem[*k].pre_zero == 0 && elem[*k].pre_hash == 1)
    {
        while (i++ < elem[*k].precision - elem[*k].size - (int)ft_strlen(value))
            ft_putchar('0');
        if (value[0] == '0' && elem[*k].precision > 0)
            ft_putchar('0');
    }
    if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1 &&
        elem[*k].pre_zero == 0 && elem[*k].pre_hash == 1)
        ft_hex_zero_one_bis(value, elem, k);
}
