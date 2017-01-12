/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:11:05 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/10 17:53:52 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parsing_flag(char **s, t_args *elem)
{
	if (**s == '#' || **s == '#' || **s == '#' || **s == '#' || **s == '#')
	{
		if (**s == '#')
			elem->pre_hash = 1;
		else if (**s == '0')
			elem->pre_zero = 1;
		else if (**s == '+')
			elem->pre_sign = 1;
		else if (**s == ' ')
			elem->pre_blank = 1;
		else if (**s == '-')
			elem->end_space = 1;
		(*s)++;
	}
	if (elem->end_space)
		elem->pre_zero = 0;
	return (*s);
}

char	*ft_parsing_width(char **s, t_args *elem, va_list *args)
{
	while (**s == '*' || (ft_isdigit(**s)))
	{
		if (**s == '*')
		{
			(*s)++;
			ft_putendl("OK");
			elem->width = va_arg(*args, int);
		//	elem->width ?  elem->width : -elem->width;
			elem->ok_width = 1;
		}
		if ((ft_isdigit(**s)))
		{
				elem->ok_width = 1;
				while (ft_isdigit(**s))
					elem->width = elem->width * 10 + (*(*s)++ - '0');
		}
	}
	return (*s);
}

char	*ft_parsing_precision(char **s, t_args *elem, va_list *args)
{
	if (**s == '.')
	{
		(*s)++;
		if (**s == '*')
		{
			elem->ok_precision = 1;
			elem->width = va_arg(*args, int);
			(*s)++;
		}
		else if (ft_isdigit(**s))
		{
			elem->ok_precision = 1;
			while (ft_isdigit(**s))
				elem->precision = elem->precision * 10 + (*(*s)++ - '0');
		}
		else
		{
			elem->ok_precision = 1;
			elem->precision = 0;
			(*s)++;
		}
	}
	return (*s);
}


char	*ft_parsing_length(char **s, t_args *elem)
{
	if (**s == 'h' && *(*s + 1) == 'h')
	{
		elem->length = hh;
		return (*s += 2);
	}
	else if (**s == 'l' && *(*s + 1) == 'l')
	{
		elem->length = ll;
		return (*s += 2);
	}
	else if (**s == 'h' || **s == 'l' || **s == 'j' || **s == 'z')
	{
		if (**s == 'h')
			elem->length = h;
		else if (**s == 'l')
			elem->length = l;
		else if (**s == 'j')
			elem->length = j;
		else if (**s == 'z')
			elem->length = z;
		(*s)++;
	}
	return (*s);
}
