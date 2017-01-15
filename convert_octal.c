
# include "ft_printf.h"

int     ft_adapt_octal(const char *value, t_args *elem, int *k)
{
    if (elem[*k].type == 'o' || elem[*k].type == 'O')
    {
        elem[*k].size = ft_strlen(value);
        if (elem[*k].pre_sign == 1)
            elem[*k].pre_sign = 0;
        if (elem[*k].pre_blank == 1)
            elem[*k].pre_blank = 0;
        if (elem[*k].pre_hash == 1 && value[0] != '0')
            elem[*k].size -= 2;
    }
    return (0);
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

size_t	ft_count_ho(unsigned long long int nb, int base)
{
	size_t count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		count++;
	}
	return (count);
}

int		ft_itoa_octal(unsigned long long int nb,  t_args *elem, int *k)
{
	int			len;
	char		str[100];
	int 		zero;

	zero = ((nb == 0) ? 1 : 0);
	ft_strclr((char*)str);
	len = ft_count_ho(nb, 8);
	if (len > 100)
		return (-1);
	str[len + 1] = '\0';
	if (nb == 0)
		str[len] = '0';
	while (len--)
	{
		str[len] = (nb % 8) + '0';
		nb /= 8;
	}
	if (zero == 1)
	{
		ft_bzero(str, 100);
		str[0] = '0';
	}
	ft_manage_octal(str, elem, "0", k);
	return (0);
}
