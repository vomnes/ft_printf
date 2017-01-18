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

int     ft_adapt_x(const char *value, t_args *elem, int *k)
{
    if (elem[*k].type == 'x' || elem[*k].type == 'X')
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

void ft_hex_zero_two(const char *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].pre_zero == 1 && elem[*k].ok_precision == 1 &&
        elem[*k].ok_width == 0)
        while (i++ < elem[*k].precision - (int)ft_strlen(value))
            ft_putchar('0');
    if (elem[*k].pre_zero == 1 && elem[*k].ok_precision == 1 &&
        elem[*k].ok_width == 1)
    {
        if (elem[*k].width <= elem[*k].precision )
            while (i++ < elem[*k].precision - (int)ft_strlen(value))
                ft_putchar('0');
        else
            while (i++ < elem[*k].precision - (int)ft_strlen(value))
                ft_putchar('0');
    }
    if (elem[*k].pre_zero == 1 && elem[*k].ok_precision == 0 &&
        elem[*k].ok_width == 1)
        while (i++ < elem[*k].width - (int)ft_strlen(value) -
        ((elem[*k].pre_hash == 1 && value[0] != '0') ? 2 : 0))
            ft_putchar('0');
}

void ft_hex_end_space(const char *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].end_space == 1 && elem[*k].ok_width == 1 &&
        elem[*k].ok_precision == 0 && elem[*k].pre_zero == 0)
        while (i++ < elem[*k].width - (int)ft_strlen(value) -
        ((elem[*k].pre_hash == 1 && value[0] != '0') ? 2 : 0))
            ft_putchar(' ');
    if ((elem[*k].end_space) && (elem[*k].ok_width) && (elem[*k].ok_precision))
    {
        if (elem[*k].width > elem[*k].precision)
        {
            if (elem[*k].precision <= ft_strlen(value))
                while (i++ < elem[*k].width - elem[*k].precision -
                ((int)ft_strlen(value) - elem[*k].precision) -
                ((elem[*k].pre_hash == 1 && value[0] != '0') ? 2 : 0))
                    ft_putchar(' ');
            else
                while (i++ < elem[*k].width - elem[*k].precision -
                ((elem[*k].pre_hash == 1 && value[0] != '0') ? 2 : 0))
                    ft_putchar(' ');
        }
    }
}

int ft_manage_hex(const char *value, t_args *elem, const char *prefix, int *k)
{
	ft_adapt_x(value, elem, k);
    ft_hex_basic_one(value, elem, k);
    ft_hex_basic_two(value, elem, k);
    ft_hex_hash(value, elem, k);
	if (elem[*k].pre_hash == 1 && elem[*k].u_nb != 0)
		ft_putstr(prefix);
    ft_hex_zero_one(value, elem, k);
    ft_hex_zero_two(value, elem, k);
    if (elem[*k].ok_precision == 1 && elem[*k].precision == 0 &&
    elem[*k].ok_width == 0 && value[0] == '0')
        ;
    else if (elem[*k].ok_precision == 1 && elem[*k].precision == 0 &&
    elem[*k].ok_width == 1 && value[0] == '0')
        ft_putchar(' ');
    else if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1 &&
    value[0] == '0')
        ft_putchar('0');
    else
        ft_putstr(value);
    ft_hex_end_space(value, elem, k);
	return (0);
}

int		ft_itoa_hex(unsigned long long int nb, char A_a, int *k, t_args *elem)
{
	int			len;
    int         tmp_len;
    unsigned long long int tmp_nb;
	char		str[100];

    tmp_nb = nb;
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
			str[len--] = (nb % 16) + A_a - 10;
		nb /= 16;
	}
	ft_manage_hex(str, elem, A_a == 'a' ? "0x" : "0X", k);
	return (tmp_len - ((elem[*k].ok_width == 0 && elem[*k].ok_precision == 1
    && elem[*k].precision == 0 && tmp_nb == 0) ? 1 : 0)
    + ((tmp_nb != 0 && elem[*k].pre_hash == 1) ? 2 : 0));
}
