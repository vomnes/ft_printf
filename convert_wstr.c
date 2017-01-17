/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_wstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:35:39 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/17 18:35:40 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

void	ft_putwstr_size(const wchar_t *wc, size_t n)
{
	size_t i;

    i = 0;
	while (*wc && i < n)
    {
        if (*wc <= 0x7F)
            i++;
        else if (*wc <= 0x7FF)
            i += 2;
        else if (*wc <= 0xFFFF)
            i += 3;
        else if (*wc <= 0x10FFFF)
            i += 4;
        if (i <= n)
            ft_putwchar_all(*wc++);
    }
}

int	ft_wstrnlen(const wchar_t *wc, size_t n)
{
	size_t i;

    i = 0;
	while (*wc && i < n)
    {
        if (*wc <= 0x7F)
            i++;
        else if (*wc <= 0x7FF)
            i += 2;
        else if (*wc <= 0xFFFF)
            i += 3;
        else if (*wc <= 0x10FFFF)
            i += 4;
    }
    return (i);
}

static void ft_wstr_pre(const wchar_t *value, int *len, int *k, t_args *elem)
{
    int i;
    char space;

    i = 0;
    space = (elem[*k].pre_zero == 0) ? ' ' : '0';
    if (elem[*k].end_space == 0)
    {
        if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1)
        {
            if (value != NULL && elem[*k].precision <
                (int)ft_sizewchar(value[0]))
                while (i++ < elem[*k].width - elem[*k].precision +
                elem[*k].precision)
                    ft_putchar(space);
            else if ((elem[*k].width - elem[*k].precision) < *len)
                while (i++ < elem[*k].precision)
                    ft_putchar(space);
            else if (elem[*k].precision <= *len)
                while (i++ < elem[*k].width - elem[*k].precision)
                    ft_putchar(space);
            else
                while (i++ < elem[*k].width - *len)// + 2)
                    ft_putchar(space);
        }
        else if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1)
            while (i++ < elem[*k].width - *len)
                ft_putchar(space);
    }
}

static void ft_wstr_end_space(int *len, int *k, t_args *elem)
{
    int i;

    i = 0;
    if (elem[*k].end_space == 1)
    {
        if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1)
        {
            if (elem[*k].precision < *len)
                while (i++ < elem[*k].width - elem[*k].precision)
                    ft_putchar(' ');
            else
                while (i++ < elem[*k].width - *len)
                    ft_putchar(' ');
        }
        else if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1)
            while (i++ < elem[*k].width - *len)
                ft_putchar(' ');
    }
}

int		ft_print_wstr(const wchar_t *value, int *k, t_args *elem)
{
    int i;
    int len;

    i = 0;
    len = 0;
    if (value == NULL)
        len = 6;
    else
    {
        if (elem[*k].ok_precision == 1)
            len += (int)ft_wstrnlen(value, elem[*k].precision);
        else
            while (value[i] != L'\0')
                len += (int)ft_sizewchar(value[i++]);
    }
//    ft_putnbr(len);
//    ft_putchar('\n');
//    ft_putnbr(elem[*k].precision);
//    ft_putchar('\n');
//    ft_putnbr(elem[*k].width);
//    ft_putchar('\n');
    i = 0;
    ft_wstr_pre(value, &len, k, elem);
    i = 0;
    if (value != NULL)
    {
        i = 0;
        if (elem[*k].ok_precision == 1)
            ft_putwstr_size(value, elem[*k].precision);
        else
            ft_putwstr(value);
    }
    else
    {
        if (elem[*k].ok_precision == 1 && elem[*k].precision < len)
           write(1, "(null)", elem[*k].precision);
        else
            ft_putstr("(null)");
    }
    i = 0;
    ft_wstr_end_space(&len, k, elem);
    return (len);
}
