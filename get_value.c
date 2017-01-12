# include "ft_printf.h"

static intmax_t ft_get_signed(t_args *elem, int *k, va_list *args)
{
    intmax_t nbr;

    nbr = va_arg(*args, intmax_t);
    elem[*k].i_nb = nbr;
    if (elem[*k].length == hh)
        return ((char)nbr);
    else if (elem[*k].length == h)
        return ((short int)nbr);
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

static uintmax_t ft_get_unsigned(t_args *elem, int *k, va_list *args)
{
    uintmax_t nbr;

    nbr = va_arg(*args, uintmax_t);
    elem[*k].u_nb = nbr;
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

void ft_check_type(t_args *elem, int *k, va_list *args)
{
    char *my_s;
    int my_c;
    wchar_t my_C;
    wchar_t* my_S;

	if (elem[*k].type == 's')
		my_s = va_arg(*args, char *);
	if (elem[*k].type == 'c')
		ft_putchar(va_arg(*args, int));
	if (elem[*k].type == 'C')
    {
        my_C = va_arg(*args, wchar_t);
    }
	if (elem[*k].type == 'S')
		ft_putwstr(va_arg(*args, wchar_t*));
	if (ft_is_signed(elem[*k].type))
		ft_get_signed(elem, k, args);
	if (elem[*k].type == 'U' || elem[*k].type == 'u')
		ft_get_unsigned(elem, k, args);
	if (elem[*k].type == 'X')
		ft_itoa_hex(ft_get_unsigned(elem, k, args), 'A'); //Best ft_itoa_hex... without malloc
	if (elem[*k].type == 'x')
		ft_itoa_hex(ft_get_unsigned(elem, k, args), 'a');
	if (elem[*k].type == 'p')
		ft_itoa_hex(ft_get_unsigned(elem, k, args), 'a');
	if (elem[*k].type == 'o' || elem[*k].type == 'O')
		ft_itoa_octal(ft_get_unsigned(elem, k, args));
}
