# include "ft_printf.h"

void ft_month(const char *value, int month, int checker)
{
    if (month == checker)
        ft_putstr(value);
}
void ft_put_month(int month)
{
    ft_month("Jan", month, 1);
    ft_month("Feb", month, 2);
    ft_month("Mar", month, 3);
    ft_month("Apr", month, 4);
    ft_month("May", month, 5);
    ft_month("Jun", month, 6);
    ft_month("Jul", month, 7);
    ft_month("Aug", month, 8);
    ft_month("Sep", month, 9);
    ft_month("Oct", month, 10);
    ft_month("Nov", month, 11);
    ft_month("Dec", month, 12);
}

void ft_put_day(int day, char space)
{
    if (day < 10)
    {
        ft_putchar(space);
        ft_putnbr(day);
    }
    else
        ft_putnbr(day);
}

int ft_put_date(const char *format)//, int *k, t_args *elem)
{
    int date[6];
    int i;
    int k;

    i = 0;
    while (i < 6)
        date[i++] = 0;
    i = 0;
    k = 0;

    while (format[i] != '\0')
    {
        if (!ft_isdigit(format[i]) && format[i] != 'T' && format[i] != ':'
            && format[i] != '-')
            return (-1);
        if (ft_isdigit(format[i]) == 1)
    		date[k] = date[k] * 10 + (format[i] - '0');
        if (format[i] == '-' && k < 3)
            k++;
        else if (format[i] == 'T' && k == 2)
            k++;
        else if (format[i] == ':')
            k++;
        i++;
    }
    i = 0;
    while (i < 6)
    {
        ft_putnbr(date[i++]);
        ft_putchar('\n');
    }
    if (date[0] > 0 && (date[0] < 1000 || date[0] > 9999))
        return (-1);
    else
        ft_putnbr(date[0]);
    ft_putchar(' ');
    if (date[1] > 0)
        ft_put_month(date[1]);
    ft_putchar(' ');
    if (date[2] > 31)
        return (-1);
    if (date[2] > 0)
        ft_put_day(date[2], '0');
    ft_putchar('\n');
    return (0);
}

/*Year:
   YYYY (eg 1997)
Year and month:
   YYYY-MM (eg 1997-07)
Complete date:
   YYYY-MM-DD (eg 1997-07-16)
Complete date plus hours and minutes:
   YYYY-MM-DDThh:mmTZD (eg 1997-07-16T19:20+01:00)
Complete date plus hours, minutes and seconds:
   YYYY-MM-DDThh:mm:ssTZD (eg 1997-07-16T19:20:30+01:00)
Complete date plus hours, minutes, seconds and a decimal fraction of a
second
   YYYY-MM-DDThh:mm:ss.sTZD (eg 1997-07-16T19:20:30.45+01:00)
where:

  YYYY = four-digit year
  MM   = two-digit month (01=January, etc.)
  DD   = two-digit day of month (01 through 31)
  hh   = two digits of hour (00 through 23) (am/pm NOT allowed)
  mm   = two digits of minute (00 through 59)
  ss   = two digits of second (00 through 59)
  s    = one or more digits representing a decimal fraction of a second
  TZD  = time zone designator (Z or +hh:mm or -hh:mm)
*/
