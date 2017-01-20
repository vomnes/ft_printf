/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:36:53 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/17 18:36:54 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

void ft_init_struct(t_args *elem, int *k)
{
	elem[*k].start = 0;
    elem[*k].ok_start = 0;
	elem[*k].end = 0;
	elem[*k].new_start = 0;
	elem[*k].nb_arg = 0;
    elem[*k].pre_hash = 0;
    elem[*k].pre_zero = 0;
    elem[*k].end_space = 0;
    elem[*k].pre_sign = 0;
    elem[*k].pre_blank = 0;
    elem[*k].ok_width = 0;
    elem[*k].width = 0;
	elem[*k].wildcard_width = 0;
    elem[*k].ok_precision = 0;
    elem[*k].precision = 0;
	elem[*k].wildcard_precision = 0;
	elem[*k].type = 0;
    elem[*k].size = 0;
	elem[*k].i_nb = 0;
    elem[*k].neg = 0;
	elem[*k].arg_len = 0;
}

void ft_putchar_len(char c, int *up)
{
	write(1, &c, 1);
	(*up)++;
}

void ft_putstr_len(const char *value, int *up)
{
	ft_putstr(value);
	*up += (int)ft_strlen(value);
}

int	ft_nb_pct(const char *s)
{
	int i;
	int count;
	int is_arg;

	i = 0;
	count = 0;
	is_arg = 0;
	while (s[i] != '\0')
	{
		if (is_arg == 1 && ft_is_type(s[i]))
            is_arg = 0;
		else if (s[i] == '%')
		{
			is_arg = 1;
            count++;
        }
		i++;
	}
	return (count);
}

int		ft_is_type(int c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%' ||
			c == 'b' || c == 'k');
}

int		ft_is_type_less_pct(int c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C');
}

int		ft_is_flag(int c)
{
	return (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ');
}

int		ft_is_signed(int c)
{
	return (c == 'D' || c == 'd' || c == 'i');
}

int		ft_is_length(int c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'z');
}

void ft_printf_struct(t_args *elem, int *k)
{
    ft_putstr("#:  ");
    ft_putnbr(elem[*k].pre_hash);
    ft_putchar('\n');
    ft_putstr("0:  ");
    ft_putnbr(elem[*k].pre_zero);
    ft_putchar('\n');
    ft_putstr("-:  ");
    ft_putnbr(elem[*k].end_space);
    ft_putchar('\n');
    ft_putstr("+:  ");
    ft_putnbr(elem[*k].pre_sign);
    ft_putchar('\n');
    ft_putstr(" :  ");
    ft_putnbr(elem[*k].pre_blank);
    ft_putchar('\n');
    ft_putstr("ok_width:  ");
    ft_putnbr(elem[*k].ok_width);
    ft_putchar('\n');
    ft_putstr("width:  ");
    ft_putnbr(elem[*k].width);
    ft_putchar('\n');
	ft_putstr("wildcard_width:  ");
	ft_putnbr(elem[*k].wildcard_width);
	ft_putchar('\n');
    ft_putstr("ok_precision:  ");
    ft_putnbr(elem[*k].ok_precision);
    ft_putchar('\n');
    ft_putstr("precision:  ");
    ft_putnbr(elem[*k].precision);
	ft_putchar('\n');
	ft_putstr("wildcard_precision:  ");
	ft_putnbr(elem[*k].wildcard_precision);
	ft_putchar('\n');
	ft_putstr("-->start:  ");
	ft_putnbr(elem[*k].start);
	//ft_putchar('\n');
	ft_putstr(" end:  ");
	ft_putnbr(elem[*k].end);
	//ft_putchar('\n');
	ft_putstr(" --->type:  ");
	ft_putchar(elem[*k].type);
	ft_putchar('\n');
	//ft_putstr("length:  ");
	//ft_putnbr(elem[*k].length);
	//ft_putchar('\n');
}
