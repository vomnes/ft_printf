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
# include <unistd.h>
# include <stdio.h>
# include <wchar.h>
# include <locale.h>
# include "./libft/libft.h"


typedef enum			e_length
{
	no, hh, h, ll, l, j, z
}						t_length;

typedef	struct	s_args
{
	int 			start;
	int 			end;
	int 			new_start;
	char			prefix[3];
	int				pre_hash;
	int				pre_zero;
	int				end_space;
	int				pre_sign;
	int				pre_blank;
	int				ok_width;
	int				width;
	int				ok_precision;
	int				wildcard_width;
	int				precision;
	int				wildcard_precision;
	t_length		length;
	char		type;
	int			size;
	int			value;
}				t_args;

int			ft_printf(const char *format, ...);

int		ft_parsing_start(const char *s, t_args *elem);
int		ft_parsing_flag(const char *s, t_args *elem);
int		ft_parsing_width(const char *s, t_args *elem);
int		ft_parsing_precision(const char *s, t_args *elem);
int		ft_parsing_length(const char *s, t_args *elem);
void	ft_parsing_type(const char *s, t_args *elem);
int		ft_manage_parsing(const char *s, t_args *elem);


void ft_init_struct(t_args *elem, int *k);
void ft_printf_struct(t_args *elem, int *k);

int		ft_is_type(int c);
int		ft_is_flag(int c);
int		ft_nb_pct(const char *s);

#endif
