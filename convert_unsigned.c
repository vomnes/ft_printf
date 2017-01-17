# include "ft_printf.h"

int     ft_adapt_unsigned(const char *value, t_args *elem, int *k)
{
    if (elem[*k].type == 'u' || elem[*k].type == 'U')
    {
        elem[*k].size = ft_strlen(value);
        if (elem[*k].pre_sign == 1)
            elem[*k].pre_sign = 0;
        if (elem[*k].pre_blank == 1)
            elem[*k].pre_blank = 0;
        if (elem[*k].pre_hash == 1)
            elem[*k].pre_hash = 0;
    }
    return (0);
}

void ft_u_width_precision(char const *value, int *k, t_args *elem)
{
    int i;

    i = 0;
    if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1)
    {
        if (elem[*k].width <= elem[*k].precision)
            while (i++ < elem[*k].precision - (int)ft_strlen(value))
                ft_putchar('0');
        else
        {
            if ((elem[*k].precision <= (int)ft_strlen(value)) && elem[*k].end_space == 0)
                while (i++ < elem[*k].width - (int)ft_strlen(value))
                    ft_putchar(' ');
            else if ((elem[*k].precision > (int)ft_strlen(value)) && elem[*k].end_space == 0)
                while (i++ < elem[*k].width - elem[*k].precision)
                    ft_putchar(' ');
            i = 0;
            while (i++ < elem[*k].precision - (int)ft_strlen(value))
                ft_putchar('0');
        }
    }
}

void ft_u_end_space(char const *value, int *k, t_args *elem)
{
    int i;

    i = 0;
    if (elem[*k].end_space == 1)
    {
        if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1)
        {
            if (elem[*k].precision <= (int)ft_strlen(value))
                while (i++ < elem[*k].width - (int)ft_strlen(value))
                    ft_putchar(' ');
            else if (elem[*k].width > elem[*k].precision)
                while (i++ < elem[*k].width - elem[*k].precision)
                    ft_putchar(' ');
        }
        else if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1)
            while (i++ < elem[*k].width - (int)ft_strlen(value))
                ft_putchar(' ');
    }
}

int ft_manage_unsigned(const char *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    ft_u_width_precision(value, k, elem);
    if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1)
        if ((elem[*k].precision <= (int)ft_strlen(value)) &&
        elem[*k].end_space == 0)
            while (i++ < elem[*k].width - (int)ft_strlen(value))
                ft_putchar((elem[*k].pre_zero == 0) ? ' ' : '0');
    if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 0)
        if (elem[*k].precision > (int)ft_strlen(value))
            while (i++ < elem[*k].precision - (int)ft_strlen(value))
                ft_putchar('0');
    if (elem[*k].ok_precision == 1 && elem[*k].precision == 0 &&
    value[0] == '0')
    {
        if (elem[*k].ok_width == 1)
            ft_putchar(' ');
        else
            ;
    }
    else
        ft_putstr(value);
    ft_u_end_space(value, k, elem);
	return (0);
}

int		ft_itoa_unsigned(unsigned long long int nb, int *k, t_args *elem)
{
	int			len;
    int         tmp_len;
	char		str[100];

	ft_bzero(str, 100);
	len = ft_count_ho(nb, 10);
    tmp_len = len;
	if (len > 100)
		return (-1);
	len--;
	if (nb == 0)
		str[len] = '0';
	while (nb)
	{
		str[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	ft_manage_unsigned(str, elem, k);
	return (tmp_len);
}
