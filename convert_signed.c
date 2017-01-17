# include "ft_printf.h"

int ft_manage_signed(const char *value, t_args *elem, int *k)
{
    ft_put_signed_space(value, k, elem);
    if (elem[*k].neg == -1)
        ft_putchar('-');
    else if (elem[*k].neg != -1)
    {
        if (elem[*k].pre_sign == 1)
            ft_putchar('+');
        else if (elem[*k].pre_blank == 1)
            ft_putchar(' ');
    }
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

static void ft_get_min(long long int nb, char const *str)
{
    if (nb == (-9223372036854775807 - 1))
    {
        ft_strclr((char*)str);
        ft_strcpy((char*)str, "9223372036854775808");
    }
}

static int ft_get_neg_len(long long int *nb, t_args *el, int *k)
{
    if (*nb < 0)
        el[*k].neg = -1;
    return (ft_count(*nb) + ((*nb < 0) ? 1 : 0));
}

int		ft_itoa_signed(long long int nb, int *k, t_args *elem)
{
    long long int n;
	int			len;
	char		str[100];

    n = nb;
	ft_bzero(str, 100);
    len = ft_get_neg_len(&nb, elem, k);
    if (len > 100)
        return (-1);
    if (nb < 0)
    {
        n = -nb;
        len--;
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
	return (ft_count(nb) + ((nb < 0) ? 1 : 0) +
    ((elem[*k].pre_sign || elem[*k].pre_blank) ? 1 : 0));
}
