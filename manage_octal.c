# include "ft_printf.h"

void ft_octal_basic_one(const char *value, t_args *elem, int *k)
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
			while (i++ < elem[*k].width - ((int)ft_strlen(value) + 2) + 1)
				ft_putchar(' ');
	}
    if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 0 &&
        elem[*k].pre_zero == 0 && elem[*k].pre_hash == 0)
        while (i++ < elem[*k].precision - elem[*k].size)
            ft_putchar('0');
}

void ft_octal_basic_two(const char *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1
        && elem[*k].pre_zero == 0 && elem[*k].pre_hash == 0)
    {
        if (elem[*k].width <= elem[*k].precision)
            while (i++ < elem[*k].precision - elem[*k].size)
                ft_putchar('0');
        else if (elem[*k].precision <= ft_strlen(value) &&
            elem[*k].end_space == 0)
            while (i++ < elem[*k].width - elem[*k].precision -
            ((int)ft_strlen(value) - elem[*k].precision))
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

void ft_octal_hash(const char *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1 &&
    elem[*k].pre_zero == 0 && elem[*k].pre_hash == 1 && elem[*k].end_space == 0)
    {
        if (elem[*k].precision <= (int)ft_strlen(value))
            while (i++ < elem[*k].width - (int)ft_strlen(value) - (value[0] != '0') ? 1 : 0)
                ft_putchar(' ');
        else if (elem[*k].width > elem[*k].precision)
            while (i++ < elem[*k].width - elem[*k].precision)
                ft_putchar(' ');
        else
        {
            while (i++ < elem[*k].width - elem[*k].precision - (int)ft_strlen(value))
                ft_putchar(' ');
            if (elem[*k].width >= elem[*k].precision && value[0] == '0')
                ft_putchar(' ');
        }
    }
}

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

void ft_octal_zero_two(const char *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].pre_zero == 1 && elem[*k].ok_precision == 1 &&
        elem[*k].ok_width == 0)
        while (i++ < elem[*k].precision - elem[*k].size)
            ft_putchar('0');
    if (elem[*k].pre_zero == 1 && elem[*k].ok_precision == 1 &&
        elem[*k].ok_width == 1)
    {
        if (elem[*k].width <= elem[*k].precision)
            while (i++ < elem[*k].precision - elem[*k].size)
                ft_putchar('0');
        else
        {
            while (i++ < elem[*k].width - elem[*k].precision)
                ft_putchar('0');
            while (i++ < elem[*k].precision - elem[*k].size)
                ft_putchar('0');
        }
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

int ft_manage_octal(const char *value, t_args *elem, const char *prefix, int *k)
{
	ft_adapt_octal(value, elem, k);
    ft_octal_basic_one(value, elem, k);
    ft_octal_basic_two(value, elem, k);
    ft_octal_hash(value, elem, k);
	if (elem[*k].pre_hash == 1 && elem[*k].u_nb != 0)
		ft_putstr(prefix);
    ft_octal_zero_one(value, elem, k);
    ft_octal_zero_two(value, elem, k);
    if (elem[*k].ok_precision == 1 && elem[*k].precision == 0
    && value[0] == '0')
    {
        if (elem[*k].pre_hash == 1 && elem[*k].ok_width == 0)
            ft_putchar('0');
        else if (elem[*k].ok_width == 0)
            ;
        else if (elem[*k].ok_width == 1 && elem[*k].pre_hash == 1)
            ft_putchar('0');
        else if (elem[*k].ok_width == 1)
            ft_putchar(' ');
    }
    else
        ft_putstr(value);
    ft_octal_end_space(value, elem, k);
	return (0);
}
