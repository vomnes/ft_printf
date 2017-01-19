/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:34:05 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/17 18:34:09 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_manage_parsing(const char *s, t_args *elem)
{
	ft_parsing_start(s, elem);
	ft_parsing_flag(s, elem);
	ft_parsing_width(s, elem);
	ft_parsing_precision(s, elem);
	ft_parsing_length(s, elem);
	ft_parsing_type(s, elem);
	return (0);
}

void ft_printf_area(char const *format, int *i, int *y)
{
	while (*i < *y && format[*i] != '\0')
		ft_putchar(format[(*i)++]);
}

int ft_printf_run(char const *format, t_args *elem, va_list *args, int *len)
{
    int i;
	int k;
	int ret;

    i = 0;
	k = 0;
	ret = 0;

	ft_manage_parsing(format, elem);
    while (format[i] != '\0')
    {
		if (format[i] == '%' && format[i + 1] == '%')
			i++;
        if (i == elem[k].start && elem[k].ok_start == 1)
        {
			ret = ft_check_type(elem, &k, args);
			if (ret == -1)
				return (-1);
			*len += ret;
			i = elem[k].end;
			ft_init_struct(elem, &k);
			k++;
        }
		else
		{
			ft_putchar(format[i]);
			*len += 1;
		}
        i++;
    }
    return (*len);
}

int			ft_printf(const char *format, ...)
{
    va_list args;
    t_args *elem;
    int len;

	if (format == NULL)
		return (0);
	if (*format == '\0')
		return (0);
    if (!(elem = ft_memalloc(sizeof(t_args) * ft_nb_pct(format))))
	   return (-1);
	len = 0;
    va_start(args, format);
    if (ft_printf_run(format, elem, &args, &len) == -1)
	{
		free(elem);
		return (-1);
		exit (-1);
	}
    va_end(args);
	free(elem);
    return (len);
}
