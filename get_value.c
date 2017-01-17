/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:35:58 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/17 18:35:59 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static intmax_t ft_get_signed(t_args *elem, int *k, va_list *args)
{
    intmax_t nbr;

    nbr = va_arg(*args, intmax_t);
    elem[*k].i_nb = (int64_t)nbr;
    if (elem[*k].length == hh)
        return ((char)nbr);
    else if (elem[*k].length == h)
        return ((short int)nbr);
    else if (elem[*k].length == l)
        return ((long int)nbr);
    else if (elem[*k].length == ll)
        return ((long long int)nbr);
    else if (elem[*k].length == j)
        return ((intmax_t)nbr);
    else if (elem[*k].length == z)
        return ((ssize_t)nbr);
    return ((int)nbr);
}

static uintmax_t ft_get_unsigned(t_args *elem, int *k, va_list *args)
{
    uintmax_t nbr;

    nbr = va_arg(*args, uintmax_t);
    elem[*k].u_nb = nbr;
    if (elem[*k].length == hh)
        return ((unsigned char)nbr);
    else if (elem[*k].length == h)
        return ((unsigned short)nbr);
    else if (elem[*k].length == l)
        return ((unsigned long)nbr);
    else if (elem[*k].length == ll)
        return ((unsigned long long)nbr);
    else if (elem[*k].length == j)
        return ((uintmax_t)nbr);
    else if (elem[*k].length == z)
        return ((size_t)nbr);
    return ((unsigned int)nbr);
}

int ft_check_type(t_args *elem, int *k, va_list *args)
{
    int ret;

    ret = 0;
    if (elem[*k].ok_width == 1 && elem[*k].wildcard_width == 1)
        elem[*k].width = va_arg(*args, int);
    if (elem[*k].ok_precision == 1 && elem[*k].wildcard_precision == 1)
        elem[*k].precision = va_arg(*args, int);
	if (elem[*k].type == 's')
		ret = ft_print_string(va_arg(*args, char *), k, elem);
	if (elem[*k].type == 'c')
		ret = ft_print_char(va_arg(*args, int), k, elem);
    if (elem[*k].type == '%')
		ret = ft_print_char('%', k, elem);
	if (elem[*k].type == 'C')
        ret = ft_print_wchar(va_arg(*args, wchar_t), k, elem);
	if (elem[*k].type == 'S')
		ret = ft_print_wstr(va_arg(*args, wchar_t*), k, elem);
	if (ft_is_signed(elem[*k].type))
		ret = ft_itoa_signed(ft_get_signed(elem, k, args), k, elem);
	if (elem[*k].type == 'U' || elem[*k].type == 'u')
		ret = ft_itoa_unsigned(ft_get_unsigned(elem, k, args), k, elem);
	if (elem[*k].type == 'X')
		ret = ft_itoa_hex(ft_get_unsigned(elem, k, args), 'A', k, elem);
	if (elem[*k].type == 'x')
		ret = ft_itoa_hex(ft_get_unsigned(elem, k, args), 'a', k, elem);
	if (elem[*k].type == 'p')
		ret = ft_itoa_ptr(va_arg(*args, unsigned long long int), k, elem);
	if (elem[*k].type == 'o' || elem[*k].type == 'O')
		ret = ft_itoa_octal(ft_get_unsigned(elem, k, args), elem, k);
    return (ret);
}
