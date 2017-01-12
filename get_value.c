# include "ft_printf.h"

intmax_t ft_get_signed(t_elem *elem, int *k, va_list *args)
{
    intmax_t nbr;

    nbr = va_arg(*args, intmax_t);
    if (elem[*k].length == hh)
        return ((char)nbr);
    else if (elem[*k].length == h)
        return ((short int)nbr;
    else if (elem[*k].length == l)
        return ((long int)nbr);
    else if (elem[*k].length == ll)
        return ((long long int)nbr);
    else if (elem[*k].length == j)
        return ((intmax_t)nbr);
    else if (elem[*k].length == z)
        return ((ssize_t)nbr);
    return ((int)nbr);
}

uintmax_t ft_get_unsigned(t_elem *elem, int *k, va_list *args)
{
    uintmax_t nbr;

    nbr = va_arg(*args, uintmax_t);
    if (elem[*k].length == hh)
        return ((unsigned char)nbr);
    else if (elem[*k].length == h)
        return ((unsigned short int)nbr);
    else if (elem[*k].length == l)
        return ((unsigned long int)nbr);
    else if (elem[*k].length == ll)
        return ((unsigned long long int)nbr);
    else if (elem[*k].length == j)
        return ((uintmax_t)nbr);
    else if (elem[*k].length == z)
        return ((size_t)nbr);
    return ((unsigned int)nbr);
}
