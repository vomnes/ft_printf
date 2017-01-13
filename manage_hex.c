
# include "ft_printf.h"

int ft_manage_hex(const char *value, t_args *elem, const char *prefix, int *k)
{
	int i;

	i = 0;
	ft_adapt(value, elem, k);
	// Print space before
	if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1 && elem[*k].end_space == 0 && elem[*k].pre_zero == 0)
	{
		i = 0;
		if (elem[*k].pre_hash == 0 || value[0] == '0')
			while (i++ < elem[*k].width - elem[*k].size)
				ft_putchar(' ');
		else
			while (i++ < elem[*k].width - ((int)ft_strlen(value) + 2))
				ft_putchar(' ');
	}
	if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 0 && elem[*k].pre_zero == 0 && elem[*k].pre_hash == 0)
		while (i++ < elem[*k].precision - elem[*k].size)
			ft_putchar('0');
	if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1 && elem[*k].pre_zero == 0 && elem[*k].pre_hash == 0)
	{
		if (elem[*k].width <= elem[*k].precision)
			while (i++ < elem[*k].precision - elem[*k].size)
				ft_putchar('0');
		else if (elem[*k].precision <= ft_strlen(value) && elem[*k].end_space == 0)
			while (i++ < elem[*k].width - elem[*k].precision - (ft_strlen(value) - elem[*k].precision))
				ft_putchar(' ');
		else
		{
			if (elem[*k].end_space == 0)
				while (i++ < elem[*k].width - elem[*k].precision)
					ft_putchar(' ');
			i = 0;
			while (i++ < elem[*k].precision - elem[*k].size)
				ft_putchar('0');
		}
	}
    if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1 && elem[*k].pre_zero == 0 && elem[*k].pre_hash == 1 && elem[*k].end_space == 1)
        if ((elem[*k].precision < elem[*k].width) && value[0] == '0')
            ft_putchar('0');
	if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1 && elem[*k].pre_zero == 0 && elem[*k].pre_hash == 1 && elem[*k].end_space == 0)
	{
		if (elem[*k].precision <= ft_strlen(value))
			while (i++ < elem[*k].width - elem[*k].precision - (int)ft_strlen(value))
				ft_putchar(' ');
		else
		{
			while (i++ < elem[*k].width - elem[*k].precision - (int)ft_strlen(value))
				ft_putchar(' ');
			if (elem[*k].width >= elem[*k].precision && value[0] == '0')
				ft_putchar(' ');
			if (value[0] == '0')
				ft_putchar('0');
		}
	}
	// Print prefix
	if (elem[*k].pre_hash == 1 && elem[*k].u_nb != 0)
		ft_putstr(prefix);
	// Print zeroes
	if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 0 && elem[*k].pre_zero == 0 && elem[*k].pre_hash == 1)
	{
		while (i++ < elem[*k].precision - elem[*k].size - (int)ft_strlen(value))
			ft_putchar('0');
		if (value[0] == '0')
			ft_putchar('0');
	}
	if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1 && elem[*k].pre_zero == 0 && elem[*k].pre_hash == 1)
	{
		if (elem[*k].width <= elem[*k].precision)
			while (i++ < elem[*k].precision - elem[*k].size - (int)ft_strlen(value) + ((elem[*k].end_space == 1 && value[0] != '0') ? 0 : 1))
				ft_putchar('0');
		else
		{
			i = 0;
			while (i++ < elem[*k].precision - elem[*k].size - (int)ft_strlen(value))
				ft_putchar('0');
		}
	}
	i = 0;
	if (elem[*k].pre_zero == 1 && elem[*k].ok_precision == 1 && elem[*k].ok_width == 0)
    	while (i++ < elem[*k].precision - elem[*k].size)
			ft_putchar('0');
	if (elem[*k].pre_zero == 1 && elem[*k].ok_precision == 1 && elem[*k].ok_width == 1)
	{
		if (elem[*k].width <= elem[*k].precision)
			while (i++ < elem[*k].precision - elem[*k].size)
				ft_putchar('0');
		else
		{
			while (i++ < elem[*k].width - elem[*k].precision)
				ft_putchar('0');
			while (i++ < elem[*k].precision - elem[*k].size)
				ft_putchar('0');
		}
	}
	//Print Value
	if (elem[*k].ok_precision == 1 && elem[*k].precision == 0 && value[0] == '0')
		ft_putchar('@');
	else
		ft_putstr(value);
	i = 0;
	if (elem[*k].end_space == 1 && elem[*k].ok_width == 1 && elem[*k].ok_precision == 0)
		while (i++ < elem[*k].width - elem[*k].size - ((elem[*k].pre_hash == 1 && value[0] != '0') ? ((int)ft_strlen(value) + 2) : 0))
			ft_putchar(' ');
	if (elem[*k].end_space == 1 && elem[*k].ok_width == 1 && elem[*k].ok_precision == 1)
	{
		if (elem[*k].width > elem[*k].precision)
		{
			if (elem[*k].precision <= ft_strlen(value))
				while (i++ < elem[*k].width - elem[*k].precision - ((int)ft_strlen(value) - elem[*k].precision) - ((elem[*k].pre_hash == 1 && value[0] != '0') ? 2 : 0))
					ft_putchar(' ');
			else
				while (i++ < elem[*k].width - elem[*k].precision - ((elem[*k].pre_hash == 1 && value[0] != '0') ? 2 : 0))
					ft_putchar(' ');
		}
	}
	return (0);
}

/*if (elem[*k].pre_blank == 1)
{
	if (elem[*k].u_nb >= 0)
		ft_putchar(' ');
	else
		ft_putchar('-');
}*/

/*if (elem[*k].pre_sign == 1)
{
	if (elem[*k].u_nb >= 0)
		ft_putchar('+');
	else
		ft_putchar('-');
}*/
//	if (elem[*k].i_nb < 0)
//		ft_putchar('-');
