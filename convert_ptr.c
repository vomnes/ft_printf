#include "ft_printf.h"

int ft_manage_ptr(const char *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].ok_width == 1 && elem[*k].end_space == 0 &&
        elem[*k].pre_zero == 0)
        if (elem[*k].width >= (int)ft_strlen(value) - 2)
            while (i++ < elem[*k].width - (int)ft_strlen(value) - 2)
                ft_putchar(' ');
    ft_putstr("0x");
    i = 0;
    if (elem[*k].ok_width == 1 && elem[*k].pre_zero == 1)
        if (elem[*k].width >= (int)ft_strlen(value) - 2)
            while (i++ < elem[*k].width - (int)ft_strlen(value) - 2)
                ft_putchar('0');
    ft_putstr(value);
    if (elem[*k].ok_width == 1 && elem[*k].end_space == 1)
        if (elem[*k].width >= (int)ft_strlen(value) - 2)
            while (i++ < elem[*k].width - (int)ft_strlen(value) - 2)
                ft_putchar(' ');
	return (0);
}

int		ft_itoa_ptr(unsigned long long int nb, int *k, t_args *elem)
{
	int			len;
    int         tmp_len;
	char		str[100];

	ft_bzero(str, 100);
	len = ft_count_ho(nb, 16);
    tmp_len = len;
	if (len > 100)
		return (-1);
	len--;
	if (nb == 0)
		str[len] = '0';
	while (nb)
	{
		if (nb % 16 <= 9)
			str[len--] = (nb % 16) + '0';
		else
			str[len--] = (nb % 16) + 'a' - 10;
		nb /= 16;
	}
	ft_manage_ptr(str, elem, k);
	return (tmp_len + 2);
}
