
# include "ft_printf.h"

size_t	ft_count_ho(long long int nb, int base)
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

int		ft_itoa_octal(long long int nb)
{
	long long	int n;
	int			len;
	char		str[100];

	ft_bzero(str, 100);
	n = nb;
	len = ft_count_ho(nb, 8);
	if (len > 100)
		return (-1);
	str[len + 1] = '\0';
	if (nb == 0)
		str[len] = '0';
	while (len--)
	{
		str[len] = (n % 8) + '0';
		n /= 8;
	}
	ft_putstr(str);
	return (0);
}
