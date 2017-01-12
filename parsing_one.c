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

//"%s %20% d\n"

#include "ft_printf.h"

int		ft_parsing_start(const char *s, t_args *elem)
{
	int i;
	int k;
	int is_arg;

	i = 0;
	k = 0;
	is_arg = 0;
	while (s[i] != '\0')
	{
		if ((is_arg == 1 && s[i] == '%') || (s[i] == '%' && s[i + 1] == '%'))
			i++;
		if (is_arg == 1 && ft_is_type(s[i]) == 1)
			is_arg = 0;
		if (s[i] == '%' && s[i + 1] != '%' && is_arg == 0)
		{
			ft_init_struct(elem, &k);
			elem[k].start = i;
			is_arg = 1;
			k++;
		}
		i++;
	}
	if (k > 0)
		elem[0].nb_arg = k;
	return (0);
}

static void ft_put_flag(const char *s, t_args *elem, int *i, int *k)
{
	while (ft_is_flag(s[*i]))
	{
		if (s[*i] == '#')
			elem[*k].pre_hash = 1;
		else if (s[*i] == '0')
			elem[*k].pre_zero = 1;
		else if (s[*i] == '+')
			elem[*k].pre_sign = 1;
		else if (s[*i] == ' ')
			elem[*k].pre_blank = 1;
		else if (s[*i] == '-')
			elem[*k].end_space = 1;
		(*i)++;
	}
	if (elem[*k].end_space)
		elem[*k].pre_zero = 0;
	elem[*k].new_start = *i;
}

int		ft_parsing_flag(const char *s, t_args *elem)
{
	int i;
	int k;

	k = 0;
	while (k < elem[0].nb_arg)
	{
		i = elem[k].start;
		i++;
		if ((ft_is_flag(s[i])))
			ft_put_flag(s, elem, &i, &k);
		else
			elem[k].new_start = elem[k].start;
		k++;
	}
	return (0);
}

static void ft_put_width(const char *s, t_args *elem, int *i, int *k)
{
	if (s[*i] == '*')
	{
		i++;
		elem[*k].new_start = *i;
		elem[*k].wildcard_width = 1;
		elem[*k].ok_width = 1;
	}
	if ((ft_isdigit(s[*i])))
	{
		while (ft_isdigit(s[*i]))
			elem[*k].width = elem[*k].width * 10 + (s[(*i)++] - '0');
		elem[*k].new_start = *i;
		elem[*k].ok_width = 1;
	}
}

int		ft_parsing_width(const char *s, t_args *elem)
{
	int i;
	int k;

	k = 0;
	while (k < elem[0].nb_arg)
	{
		i = elem[k].new_start;
		if (elem[k].new_start == elem[k].start)
			i++;
		if (s[i] == '*' || (ft_isdigit(s[i])))
			ft_put_width(s, elem, &i, &k);
		k++;
	}
	return (0);
}
