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

int ft_printf_run(char const *format, t_args *elem, va_list *args, int *len)
{
    int i;
	int k;

    i = 0;
	k = 0;
	ft_manage_parsing(format, elem);
    while (format[i] != '\0')
    {
		if (format[i] == '%' && format[i + 1] == '%')
			i++;
        if (i == elem[k].start)
        {
			ft_check_type(elem, &k, args);
			i = elem[k].end;
        }
		else
        	ft_putchar(format[i]);
        i++;
        (*len)++;
    }
    return (*len);
}

int			ft_printf(const char *format, ...)
{
    va_list args;
    t_args *elem;
    int len;

    if (!(elem = ft_memalloc(sizeof(t_args) * 10)))
	   return (-1);
    va_start(args, format);
    ft_printf_run(format, elem, &args, &len);
    va_end(args);
	free(elem);
    return (len);
}
