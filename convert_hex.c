/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:03:21 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/10 18:03:25 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_count_ho(long long int nb, int base)
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

int		ft_itoa_hex(long long int nb, char letter_a)
{
	long long	int n;
	int			len;
	char		str[100];

	n = nb;
	ft_bzero(str, 100);
	len = ft_count_ho(nb, 16);
	if (len > 100)
		return (-1);
	len--;
	if (nb == 0)
		str[len] = '0';
	while (n)
	{
		if (n % 16 <= 9)
			str[len--] = (n % 16) + '0';
		else
			str[len--] = (n % 16) + letter_a - 10;
		n /= 16;
	}
	ft_putstr(str);
	return (0);
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
