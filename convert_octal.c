
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
	ft_bzero(str, 100);
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
