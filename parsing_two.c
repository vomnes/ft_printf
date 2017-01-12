/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:03:02 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/10 17:54:32 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static void ft_put_precision(const char *s, t_args *elem, int *i, int *k)
{
	if (s[*i] == '*')
	{
		(*i)++;
		elem[*k].new_start = *i;
		elem[*k].wildcard_precision = 1;
		elem[*k].ok_precision = 1;
	}
	if ((ft_isdigit(s[*i])))
	{
		while (ft_isdigit(s[*i]))
			elem[*k].precision = elem[*k].precision * 10 + (s[(*i)++] - '0');
		elem[*k].new_start = *i;
		elem[*k].ok_precision = 1;
	}
}

int		ft_parsing_precision(const char *s, t_args *elem)
{
	int i;
	int k;

	k = 0;
	while (k < ft_nb_pct(s))
	{
		i = elem[k].new_start;
		if (elem[k].new_start == elem[k].start)
			i++;
		if ((ft_is_flag(s[i])))
			i++;
		if (s[i] == '.')
		{
			i++;
			if (s[i] == '*' || (ft_isdigit(s[i])))
				ft_put_precision(s, elem, &i, &k);
		}
		k++;
	}
	return (0);
}

static void ft_put_length(const char *s, t_args *elem, int *i, int *k)
{
	if (s[*i] == 'l' && s[(*i) + 1] == 'l')
	{
		elem[*k].length = ll;
		(*i) += 2;
	}
	else if (s[*i] == 'h' && s[(*i) + 1] == 'h')
	{
		elem[*k].length = hh;
		(*i) += 2;
	}
	else if (s[*i] == 'h' || s[*i] == 'l' || s[*i] == 'j' || s[*i] == 'z')
	{
		if (s[*i] == 'z')
			elem[*k].length = z;
		else if (s[*i] == 'l')
			elem[*k].length = l;
		else if (s[*i] == 'h')
			elem[*k].length = h;
		else if (s[*i] == 'j')
			elem[*k].length = j;
		(*i)++;
	}
}

int		ft_parsing_length(const char *s, t_args *elem)
{
	int i;
	int k;

	k = 0;
	while (k < ft_nb_pct(s))
	{
		i = elem[k].new_start;
		if (elem[k].new_start == elem[k].start)
			i++;
		ft_put_length(s, elem, &i, &k);
		k++;
	}
	return (0);
}

void	ft_parsing_type(const char *s, t_args *elem)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (k < ft_nb_pct(s))
	{
		i = elem[k].new_start;
		if (elem[k].new_start == elem[k].start)
			i++;
		if (ft_is_type(s[i]))
		{
			elem[k].end = i;
			elem[k].type = s[i];
			ft_printf_struct(elem, &k);
			k++;
			i = elem[k].start;
		}
		i++;
	}
}
