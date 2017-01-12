# include "ft_printf.h"


void ft_manage_parsing(char **format, t_args *elem, va_list *args)
{
    ft_parsing_flag(format, &(*elem));
    ft_parsing_width(format, &(*elem), args);
    ft_parsing_precision(format, &(*elem), args);
    ft_parsing_length(format, &(*elem));
}

int ft_printf_run(char *format, va_list *args, t_args *elem, int *len)
{
    while (*format != '\0')
    {
        if (*format == '%')
        {
            ft_init_struct(&(*elem));
            format++;
            if (*format == '%')
                ft_putchar('%');
            else
            {
                while (!ft_is_type(*format))
                {
                    ft_manage_parsing((char **)&format, elem, args);
                    format++;
                }
                ft_printf_struct(&(*elem));
                (*len) += ft_strlen("Test");
                format++;
            }
        }
        ft_putchar(*format);
        format++;
        (*len)++;
    }
    return (*len);
}

int			ft_printf(const char *format, ...)
{
    va_list args;
    int len;
    t_args elem;

    va_start(args, format);
    ft_printf_run((char*)format, &args, &elem, &len);
    va_end(args);
    return (len);
}
