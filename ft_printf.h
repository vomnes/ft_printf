/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 15:13:19 by vomnes            #+#    #+#             */
/*   Updated: 2016/12/19 20:33:25 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <locale.h>
# include "./libft/libft.h"


typedef	struct	s_args
{
	char			prefix[3];
	int				pre_hash;
	int				pre_zero;
	int				end_space;
	int				pre_sign;
	int				pre_blank;
	int				ok_width;
	unsigned int	width;
	int				ok_precision;
	unsigned int	precision;
	enum
	{
		h,
		hh,
		l,
		ll,
		j,
		z,
		no
	}		length;
	char		type[2];
	int			size;
	int			value;
}				t_args;

int			ft_printf(const char *format, ...);

char	*ft_parsing_flag(char **s, t_args *elem);
char	*ft_parsing_width(char **s, t_args *elem, va_list *args);
char	*ft_parsing_precision(char **s, t_args *elem, va_list *args);
char	*ft_parsing_length(char **s, t_args *elem);

void ft_init_struct(t_args *elem);
void ft_printf_struct(t_args *elem);

int		ft_is_type(int c);
int		ft_nb_pct(const char *s);

#endif
