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

typedef enum		e_length
{
	no,
	hh,
	h,
	ll,
	l,
	j,
	z
}					t_length;

typedef	struct		s_args
{
	int 			start;
	int 			end;
	int 			new_start;
	int				nb_arg;
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
	char			type;
	int				size;
	uintmax_t		u_nb;
	intmax_t		i_nb;
}					t_args;

int			ft_printf(const char *format, ...);

int		ft_parsing_start(const char *s, t_args *elem);
int		ft_parsing_flag(const char *s, t_args *elem);
int		ft_parsing_width(const char *s, t_args *elem);
int		ft_parsing_precision(const char *s, t_args *elem);
int		ft_parsing_length(const char *s, t_args *elem);
void	ft_parsing_type(const char *s, t_args *elem);
int		ft_manage_parsing(const char *s, t_args *elem);

void 	ft_hex_basic_one(const char *value, t_args *elem, int *k);
void 	ft_hex_basic_two(const char *value, t_args *elem, int *k);
void 	ft_hex_hash(const char *value, t_args *elem, int *k);
void 	ft_hex_zero_one(const char *value, t_args *elem, int *k);
size_t	ft_count_ho(unsigned long long int nb, int base);
int		ft_itoa_hex(unsigned long long int nb, char letter_a, int *k, t_args *elem);
int 	ft_manage_octal(const char *value, t_args *elem, const char *prefix, int *k);
int     ft_adapt_octal(const char *value, t_args *elem, int *k);
int		ft_itoa_octal(unsigned long long int nb,  t_args *elem, int *k);

int 	ft_manage_hex(const char *value, t_args *elem, const char *prefix, int *k);


void ft_check_type(t_args *elem, int *k, va_list *args);

void ft_init_struct(t_args *elem, int *k);
void ft_printf_struct(t_args *elem, int *k);

int		ft_is_type(int c);
int		ft_is_flag(int c);
int		ft_is_signed(int c);
int		ft_is_length(int c);

#endif
