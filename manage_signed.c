/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_signed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:36:36 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/17 18:36:39 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

void ft_signed_end_space(char const *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].precision <=  (int)ft_strlen(value))
    {
        while (i++ < elem[*k].width - (int)ft_strlen(value) -
        ((elem[*k].neg == -1) ? 1 : 0) - (elem[*k].neg != -1 &&
        (elem[*k].pre_blank == 1 || elem[*k].pre_sign == 1)) ? 1 : 0)
            ft_putchar(' ');
    }
    else
    {
        while (i++ < elem[*k].width - elem[*k].precision -
        ((elem[*k].neg == -1) ? 1 : 0) - (elem[*k].neg != -1 &&
        (elem[*k].pre_blank == 1 || elem[*k].pre_sign == 1)) ? 1 : 0)
            ft_putchar(' ');
    }
}

void ft_put_signed_zeroes(char const *value, t_args *elem, int *k)
{
    int i;

    i = 0;
    if (elem[*k].ok_precision == 1)
    {
        if (elem[*k].ok_width == 1)
        {
            if (elem[*k].width <= elem[*k].precision)
                while (i++ < elem[*k].precision - (int)ft_strlen(value))
                    ft_putchar('0');
            else if (elem[*k].width > elem[*k].precision)
                while (i++ < elem[*k].precision - (int)ft_strlen(value))
                    ft_putchar('0');
        }
        else
            while (i++ < elem[*k].precision - (int)ft_strlen(value))
                ft_putchar('0');
    }
    else
    {
        if (elem[*k].ok_width == 1 && (elem[*k].neg == -1 ||
            (elem[*k].pre_blank == 1 || elem[*k].pre_sign == 1)) && elem[*k].pre_zero == 1)
            while (i++ < elem[*k].width - (int)ft_strlen(value) - 1)
                ft_putchar('0');
    }
}

static void ft_put_signed_space_bis(char const *value, int *k, t_args *elem)
{
    int i;

    i = 0;
    if (elem[*k].width <= elem[*k].precision)
        while (i++ < elem[*k].width - elem[*k].precision)
            ft_putchar(' ');
    else if (elem[*k].width > elem[*k].precision)
    {
        if (elem[*k].precision <= (int)ft_strlen(value))
            while (i++ < elem[*k].width - (int)ft_strlen(value) -
            ((elem[*k].neg == -1) ? 1 : 0) - (elem[*k].neg != -1 &&
            (elem[*k].pre_blank == 1 || elem[*k].pre_sign == 1)) ? 1 : 0)
                ft_putchar(' ');
        else
            while (i++ < elem[*k].width - elem[*k].precision -
            ((elem[*k].neg == -1) ? 1 : 0) - (elem[*k].neg != -1 &&
            (elem[*k].pre_blank == 1 || elem[*k].pre_sign == 1)) ? 1 : 0)
                ft_putchar(' ');
    }
}

void ft_put_signed_space(char const *value, int *k, t_args *elem)
{
    int i;

    i = 0;
    if (elem[*k].end_space == 0)
    {
        if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1)
            ft_put_signed_space_bis(value, k, elem);
        else if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1)
        {
            if (elem[*k].neg != -1 && elem[*k].pre_sign == 0 &&
                elem[*k].pre_blank == 0)
                while (i++ < elem[*k].width - (int)ft_strlen(value))
                    ft_putchar((elem[*k].pre_zero == 1) ? '0' : ' ');
            else if (elem[*k].neg != -1 && (elem[*k].pre_sign == 1 ||
                elem[*k].pre_blank == 1) && elem[*k].pre_zero == 0)
                while (i++ < elem[*k].width - (int)ft_strlen(value) - 1)
                    ft_putchar(' ');
            else if (elem[*k].neg == -1 && elem[*k].pre_zero == 0)
                while (i++ < elem[*k].width - (int)ft_strlen(value) - 1)
                    ft_putchar(' ');
        }
    }
}

void ft_put_signed_end_space(char const *value, int *k, t_args *elem)
{
    int i;

    i = 0;
    if (elem[*k].end_space == 1)
    {
        if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1)
            ft_signed_end_space(value, elem, k);
        else if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1)
        {
            while (i++ < elem[*k].width - (int)ft_strlen(value) -
            ((elem[*k].neg == -1) ? 1 : 0) - (elem[*k].neg != -1 &&
            (elem[*k].pre_blank == 1 || elem[*k].pre_sign == 1)) ? 1 : 0)
                ft_putchar(' ');
        }
    }
}
