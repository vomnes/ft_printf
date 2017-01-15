# include "ft_printf.h"

int     ft_adapt_signed(const char *value, t_args *elem, int *k)
{
    if (ft_is_signed(elem[*k].type))
    {
        //elem[*k].size = ft_strlen(value);
        if (elem[*k].pre_hash == 1)
            elem[*k].pre_hash = 0;
//        if (value[0] == '-')
//            elem[*k].size--;
    }
    return (0);
}


void ft_signed_end_space(char const *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].precision <=  (int)ft_strlen(value))
    {
        while (i++ < elem[*k].width - (int)ft_strlen(value) -
        ((elem[*k].i_nb < 0) ? 1 : 0) - (elem[*k].i_nb >= 0 &&
        (elem[*k].pre_blank == 1 || elem[*k].pre_sign == 1)) ? 1 : 0)
            ft_putchar(' ');
    }
    else
    {
        while (i++ < elem[*k].width - elem[*k].precision -
        ((elem[*k].i_nb < 0) ? 1 : 0) - (elem[*k].i_nb >= 0 &&
        (elem[*k].pre_blank == 1 || elem[*k].pre_sign == 1)) ? 1 : 0)
            ft_putchar(' ');
    }
}

void ft_put_signed_zeroes(char const *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].ok_precision == 1)
    {
        if (elem[*k].ok_width == 1)
        {
            if (elem[*k].width <= elem[*k].precision)
                while (i++ < elem[*k].precision - (int)ft_strlen(value))
                    ft_putchar('0');
            else if (elem[*k].width > elem[*k].precision)
                while (i++ < elem[*k].precision - (int)ft_strlen(value))
                    ft_putchar('0');
        }
        else
            while (i++ < elem[*k].precision - (int)ft_strlen(value))
                ft_putchar('0');
    }
}

void ft_put_signed_space_bis(char const *value, int *k, t_args *elem)
{
    int i;

    i = 0;
    if (elem[*k].width <= elem[*k].precision)
        while (i++ < elem[*k].width - elem[*k].precision)
            ft_putchar(' ');
    else if (elem[*k].width > elem[*k].precision)
    {
        if (elem[*k].precision <= (int)ft_strlen(value))
            while (i++ < elem[*k].width - (int)ft_strlen(value) -
            ((elem[*k].i_nb < 0) ? 1 : 0) - (elem[*k].i_nb >= 0 &&
            elem[*k].pre_blank == 1) ? 1 : 0)
                ft_putchar(' ');
        else
            while (i++ < elem[*k].width - elem[*k].precision -
            ((elem[*k].i_nb < 0) ? 1 : 0) - (elem[*k].i_nb >= 0 &&
            elem[*k].pre_blank == 1) ? 1 : 0)
                ft_putchar(' ');
    }
}

void ft_put_signed_space(char const *value, int *k, t_args *elem)
{
    int i;

    i = 0;
    if (elem[*k].end_space == 0)
    {
        if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1)
            ft_put_signed_space_bis(value, k, elem);
        else if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1)
            while (i++ < elem[*k].width - (int)ft_strlen(value) -
            ((elem[*k].i_nb < 0) ? 1 : 0) - (elem[*k].i_nb >= 0 &&
            elem[*k].pre_blank == 1) ? 1 : 0)
                ft_putchar(' ');
    }
}

void ft_put_signed_end_space(char const *value, int *k, t_args *elem)
{
    int i;

    i = 0;
    if (elem[*k].end_space == 1)
    {
        if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1)
            ft_signed_end_space(value, elem, k);
        else if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1)
        {
            while (i++ < elem[*k].width - (int)ft_strlen(value) -
            ((elem[*k].i_nb < 0) ? 1 : 0) - (elem[*k].i_nb >= 0 &&
            (elem[*k].pre_blank == 1 || elem[*k].pre_sign == 1)) ? 1 : 0)
                ft_putchar(' ');
        }
    }
}

int ft_manage_signed(const char *value, t_args *elem, int *k)
{
    ft_put_signed_space(value, k, elem);
    if (elem[*k].i_nb < 0)
        ft_putchar('-');
    else if (elem[*k].i_nb >= 0 && elem[*k].pre_sign == 1)
        ft_putchar('+');
    else if (elem[*k].i_nb >= 0 && elem[*k].pre_blank == 1)
        ft_putchar(' ');
    ft_put_signed_zeroes(value, elem, k);
    if (elem[*k].ok_precision == 1 && !(elem[*k].precision) && value[0] == '0')
    {
        if (elem[*k].ok_width == 1)
            ft_putchar(' ');
        else
            ;
    }
    else
        ft_putstr(value);
    ft_put_signed_end_space(value, k, elem);
	return (0);
}

size_t	ft_count(long long int nb)
{
	size_t count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

void ft_get_min(long long int nb, char const *str)
{
    if (nb == (-9223372036854775807 - 1))
    {
        ft_strclr((char*)str);
        ft_strcpy((char*)str, "-9223372036854775808");
    }
}

int		ft_itoa_signed(long long int nb, int *k, t_args *elem)
{
    long long int n;
	int			len;
	char		str[100];

    n = nb;
	ft_bzero(str, 100);
	len = ft_count(nb) + ((nb < 0) ? 1 : 0);
    if (len > 100)
        return (-1);
    if (nb < 0)
    {
        n = -nb;
        len--;
//        str[0] = '-';
    }
	len--;
	if (nb == 0)
		str[len] = '0';
	while (n)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
    ft_get_min(nb, str);
	ft_manage_signed(str, elem, k);
	return (0);
}
