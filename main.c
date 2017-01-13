# include <stdio.h>
# include <limits.h>
# include "ft_printf.h"

int		ft_my_itoa_octal(unsigned long long int nb)
{
	int			len;
	char		str[100];

	ft_bzero(str, 100);
	len = ft_count_ho(nb, 8);
	if (len > 100)
		return (-1);
	str[len + 1] = '\0';
	if (nb == 0)
		str[len] = '0';
	while (len--)
	{
		str[len] = (nb % 8) + '0';
		nb /= 8;
	}
    ft_putendl(str);
	return (0);
}

int main()
{
    setlocale(LC_CTYPE, "");
    t_args *elem;
    int len;
    char const *s = "%#0-300.180d % -+040.*lls --> %zus\n"; // % -+040.*llS
    //char const *s = "%s %20% d %10.20%\n";
    long long int ptr = LLONG_MIN;
	//ft_printf("%#-10.20X\n", 15);
	//ft_printf("%-X\n", -15);
/*    printf("%+15X\n", -15);
	printf("%+X\n", -15);
	printf("%+X\n", 15);
	printf("%+X\n", 0);
	printf("% 15X\n", -15);
	printf("% X\n", -15);
	printf("% X\n", 15);
	printf("% X\n", 0);
	ft_printf("% 15X\n", -15);
	ft_printf("% X\n", -15);
	ft_printf("% X\n", 15);
	ft_printf("% X\n", 0);
	ft_printf("%+15X\n", -15);
	ft_printf("%+X\n", -15);
	ft_printf("%+X\n", 15);
	ft_printf("%+X\n", 0);
	ft_printf("%-15X$\n", -15);
	printf("%-15X$\n", -15);
	ft_printf("%-X$\n", -15);
	printf("%-X$\n", -15);
	ft_printf("%-X$\n", 15);
	printf("%-X$\n", 15);
	ft_printf("%-X$\n", 0);
	printf("%-X$\n", 0);
		ft_printf("%10.2x<--\n", 20);
		printf("%10.2x<--\n\n", 20);
		ft_printf("%10.2x<--\n", -20);
		printf("%10.2x<--\n\n", -20);

		ft_printf("%10x<--\n", -20);
		printf("%10x<--\n\n", -20);

		ft_printf("%4x<--\n", -20);
		printf("%4x<--\n\n", -20);
		ft_printf("%6x<--\n", -20);
		printf("%6x<--\n\n", -20);

		ft_putendl("x.x");
		ft_printf("%10.10x<--\n", -20);
		printf("%10.10x<--\n\n", -20);
		ft_printf("%2.10x<--\n", -142);
		printf("%2.10x<--\n\n", -142);
		ft_printf("%2.10x<--\n", 142);
		printf("%2.10x<--\n\n", 142);
		ft_printf("%1.10x<--\n", 142);
		printf("%1.10x<--\n\n", 142);
		ft_printf("%10.5x<--\n", 20);
		printf("%10.5x<--\n\n", 20);
		ft_printf("%10.2x<--\n", 20);
		printf("%10.2x<--\n\n", 20);
		ft_printf("%10.1x<--\n", 20); //
		printf("%10.1x<--\n\n", 20); //
		ft_printf("%10.1x<--\n", 142); //
		printf("%10.1x<--\n\n", 142); //
		ft_printf("%10.1x<--\n", 1420); //
		printf("%10.1x<--\n\n", 1420); //

		ft_printf("%10.15x<--\n", 142);
		printf("%10.15x<--\n\n", 142);
		ft_printf("%10.0x<--\n", 0);
		printf("%10.0x<--\n\n", 0);

		ft_printf("%10.0x<--\n", 1); //
		printf("%10.0x<--\n\n", 1);

		ft_printf("%10.1x<--\n", 0);
		printf("%10.1x<--\n\n", 0);

		ft_putendl("x");
		ft_printf("%10x<--\n", -20);
		printf("%10x<--\n\n", -20);
		ft_printf("%2x<--\n", -142);
		printf("%2x<--\n\n", -142);
		ft_printf("%2x<--\n", 142);
		printf("%2x<--\n\n", 142);
		ft_printf("%1x<--\n", 142);
		printf("%1x<--\n\n", 142);
		ft_printf("%10x<--\n", 20);
		printf("%10x<--\n\n", 20);
		ft_printf("%10x<--\n", 20);
		printf("%10x<--\n\n", 20);

		ft_printf("%15x<--\n", 142);
		printf("%15x<--\n\n", 142);
		ft_printf("%1x<--\n", 0);
		printf("%1x<--\n\n", 0);

		ft_printf("%30x<--\n", 1);
		printf("%30x<--\n\n", 1);
		ft_printf("%50x<--\n", 0);
		printf("%50x<--\n\n", 0);

		ft_printf("%.25x<--\n", -20);
		printf("%.25x<--\n\n", -20);
		ft_printf("%.25x<--\n", 20);
		printf("%.25x<--\n\n", 20);
		ft_printf("%.25x<--\n", 0);
		printf("%.25x<--\n\n", 0);

		ft_printf("%10x<--\n", -20);
		printf("%10x<--\n\n", -20);
		ft_printf("%10x<--\n", -142);
		printf("%10x<--\n\n", -142);
		ft_printf("%10x<--\n", 20);
		printf("%10x<--\n\n", 20);
		ft_printf("%10x<--\n", 142);
		printf("%10x<--\n\n", 142);
		ft_printf("%10x<--\n", 0);
		printf("%10x<--\n\n", 0);


			printf("-->###<--\n\n");

			ft_printf("-->Width_Precision<--\n\n");
			ft_printf("%#10.10x<--\n", 42);
			printf("%#10.10x<--\n\n", 42);
			ft_printf("%#10.8x<--\n", 42);
			printf("%#10.8x<--\n\n", 42);
			ft_printf("%#10.15x<--\n", 0);
			printf("%#10.15x<--\n\n", 0);
			ft_printf("%#10.8x<--\n", 20);
			printf("%#10.8x<--\n\n", 20);
			ft_printf("%#10.8x<--\n", 20);
			printf("%#10.8x<--\n\n", 20);
			ft_printf("%#10.6x<--\n", 120);
			printf("%#10.6x<--\n\n", 120);
			ft_printf("%#10.2x<--\n", 20);
			printf("%#10.2x<--\n\n", 20);

			ft_printf("%#10.2x<--\n", 0);
			printf("%#10.2x<--\n\n", 0);

			ft_printf("%#10.4x<--\n", 0);
			printf("%#10.4x<--\n\n", 0);

			ft_printf("%10.2x<--\n", 0);
			printf("%10.2x<--\n\n", 0);
			ft_printf("%#10.5x<--\n", ULLONG_MAX);
			printf("%#10.5x<--\n\n", ULLONG_MAX);
			ft_printf("%10.5x<--\n", LLONG_MAX);
			printf("%10.5x<--\n\n", LLONG_MAX);

			ft_printf("%#10.12x<--\n", 20);
			printf("%#10.12x<--\n\n", 20);
			ft_printf("%#10.12x<--\n", 120);
			printf("%#10.12x<--\n\n", 120);
			ft_printf("%#10.12x<--\n", 20);
			printf("%#10.12x<--\n\n", 20);

			ft_printf("%#10.12X<--\n", 0);
			printf("%#10.12X<--\n\n", 0);

			ft_printf("-->Width<--\n\n");
			ft_printf("%#10x<--\n", 42);
			printf("%#10x<--\n\n", 42);
			ft_printf("%#10x<--\n", 142);
			printf("%#10x<--\n\n", 142);
			ft_printf("%#10x<--\n", 14200);
			printf("%#10x<--\n\n", 14200);
			ft_printf("%#10x<--\n", 42);
			printf("%#10x<--\n\n", 42);
			ft_printf("%#10x<--\n", 142);
			printf("%#10x<--\n\n", 142);
			ft_printf("%#10x<--\n", 20);
			printf("%#10x<--\n\n", 20);
			ft_printf("%#10x<--\n", 0);
			printf("%#10x<--\n\n", 0);
			ft_printf("%#1x<--\n", 42);
			printf("%#1x<--\n\n", 42);

			ft_printf("-->Precision<--\n\n");
			ft_printf("%#.8x<--\n", 42);
			printf("%#.8x<--\n\n", 42);
			ft_printf("%#.8x<--\n", 142);
			printf("%#.8x<--\n\n", 142);
			ft_printf("%#.8x<--\n", 42);
			printf("%#.8x<--\n\n", 42);
			ft_printf("%#.2x<--\n", 142);
			printf("%#.2x<--\n\n", 142);
			ft_printf("%#.8x<--\n", 0);
			printf("%#.8x<--\n\n", 0);

			printf("-->---<--\n\n");

			ft_printf("-->Width_Precision<--\n\n");
			ft_printf("%-10.10x<--\n", 42);
			printf("%-10.10x<--\n\n", 42);
			ft_printf("%-10.8x<--\n", 42);
			printf("%-10.8x<--\n\n", 42);
			ft_printf("%-10.15x<--\n", 0);
			printf("%-10.15x<--\n\n", 0);
			ft_printf("%-10.8x<--\n", 20);
			printf("%-10.8x<--\n\n", 20);
			ft_printf("%-10.8x<--\n", 20);
			printf("%-10.8x<--\n\n", 20);
			ft_printf("%-10.6x<--\n", 120);
			printf("%-10.6x<--\n\n", 120);
			ft_printf("%-10.2x<--\n", 20);
			printf("%-10.2x<--\n\n", 20);

			ft_printf("%-10.2x<--\n", 0);
			printf("%-10.2x<--\n\n", 0);

			ft_printf("%-10.4x<--\n", 0);
			printf("%-10.4x<--\n\n", 0);

//			ft_printf("%10.2x<--\n", 0);
//			printf("%10.2x<--\n\n", 0);
			ft_printf("%-10.5x<--\n", ULLONG_MAX);
			printf("%-10.5x<--\n\n", ULLONG_MAX);
			ft_printf("%-10.2x<--\n", 100000);
			printf("%-10.2x<--\n\n", 100000);
			ft_printf("%-10.1x<--\n", 100);
			printf("%-10.1x<--\n\n", 100);
			ft_printf("%-10.0x<--\n", 10);
			printf("%-10.0x<--\n\n", 10);
//			ft_printf("%10.5x<--\n", LLONG_MAX);
//			printf("%10.5x<--\n\n", LLONG_MAX);

			ft_printf("%-10.12x<--\n", 20);
			printf("%-10.12x<--\n\n", 20);
			ft_printf("%-10.12x<--\n", 120);
			printf("%-10.12x<--\n\n", 120);
			ft_printf("%-10.12x<--\n", 20);
			printf("%-10.12x<--\n\n", 20);

			ft_printf("%-10.12X<--\n", 0);
			printf("%-10.12X<--\n\n", 0);

			ft_printf("-->Width<--\n\n");
			ft_printf("%-10x<--\n", 42);
			printf("%-10x<--\n\n", 42);
			ft_printf("%-10x<--\n", 142);
			printf("%-10x<--\n\n", 142);
			ft_printf("%-10x<--\n", 14200);
			printf("%-10x<--\n\n", 14200);
			ft_printf("%-10x<--\n", 42);
			printf("%-10x<--\n\n", 42);
			ft_printf("%-10x<--\n", 142);
			printf("%-10x<--\n\n", 142);
			ft_printf("%-10x<--\n", 20);
			printf("%-10x<--\n\n", 20);
			ft_printf("%-10x<--\n", 0);
			printf("%-10x<--\n\n", 0);
			ft_printf("%-1x<--\n", 42);
			printf("%-1x<--\n\n", 42);

			ft_printf("-->Precision<--\n\n");
			ft_printf("%-.8x<--\n", 42);
			printf("%-.8x<--\n\n", 42);
			ft_printf("%-.8x<--\n", 142);
			printf("%-.8x<--\n\n", 142);
			ft_printf("%-.8x<--\n", 42);
			printf("%-.8x<--\n\n", 42);
			ft_printf("%-.2x<--\n", 142);
			printf("%-.2x<--\n\n", 142);
			ft_printf("%-.8x<--\n", 0);
			printf("%-.8x<--\n\n", 0);

			printf("-->   <--\n\n");

			ft_printf("-->Width_Precision<--\n\n");
			ft_printf("% 10.10x<--\n", 42);
			printf("% 10.10x<--\n\n", 42);
			ft_printf("% 10.8x<--\n", 42);
			printf("% 10.8x<--\n\n", 42);
			ft_printf("% 10.15x<--\n", 0);
			printf("% 10.15x<--\n\n", 0);
			ft_printf("% 10.8x<--\n", 20);
			printf("% 10.8x<--\n\n", 20);
			ft_printf("% 10.8x<--\n", 20);
			printf("% 10.8x<--\n\n", 20);
			ft_printf("% 10.6x<--\n", 120);
			printf("% 10.6x<--\n\n", 120);
			ft_printf("% 10.2x<--\n", 20);
			printf("% 10.2x<--\n\n", 20);

			ft_printf("% 10.2x<--\n", 0);
			printf("% 10.2x<--\n\n", 0);

			ft_printf("% 10.4x<--\n", 0);
			printf("% 10.4x<--\n\n", 0);

			//			ft_printf("%10.2x<--\n", 0);
			//			printf("%10.2x<--\n\n", 0);
			ft_printf("% 10.5x<--\n", ULLONG_MAX);
			printf("% 10.5x<--\n\n", ULLONG_MAX);
			ft_printf("% 10.2x<--\n", 100000);
			printf("% 10.2x<--\n\n", 100000);
			ft_printf("% 10.1x<--\n", 100);
			printf("% 10.1x<--\n\n", 100);
			ft_printf("% 10.0x<--\n", 10);
			printf("% 10.0x<--\n\n", 10);
			//			ft_printf("%10.5x<--\n", LLONG_MAX);
			//			printf("%10.5x<--\n\n", LLONG_MAX);

			ft_printf("% 10.12x<--\n", 20);
			printf("% 10.12x<--\n\n", 20);
			ft_printf("% 10.12x<--\n", 120);
			printf("% 10.12x<--\n\n", 120);
			ft_printf("% 10.12x<--\n", 20);
			printf("% 10.12x<--\n\n", 20);

			ft_printf("% 10.12X<--\n", 0);
			printf("% 10.12X<--\n\n", 0);

			ft_printf("-->Width<--\n\n");
			ft_printf("% 10x<--\n", 42);
			printf("% 10x<--\n\n", 42);
			ft_printf("% 10x<--\n", 142);
			printf("% 10x<--\n\n", 142);
			ft_printf("% 10x<--\n", 14200);
			printf("% 10x<--\n\n", 14200);
			ft_printf("% 10x<--\n", 42);
			printf("% 10x<--\n\n", 42);
			ft_printf("% 10x<--\n", 142);
			printf("% 10x<--\n\n", 142);
			ft_printf("% 10x<--\n", 20);
			printf("% 10x<--\n\n", 20);
			ft_printf("% 10x<--\n", 0);
			printf("% 10x<--\n\n", 0);
			ft_printf("% 1x<--\n", 42);
			printf("% 1x<--\n\n", 42);

			ft_printf("-->Precision<--\n\n");
			ft_printf("% .8x<--\n", 42);
			printf("% .8x<--\n\n", 42);
			ft_printf("% .8x<--\n", 142);
			printf("% .8x<--\n\n", 142);
			ft_printf("% .8x<--\n", 42);
			printf("% .8x<--\n\n", 42);
			ft_printf("% .2x<--\n", 142);
			printf("% .2x<--\n\n", 142);
			ft_printf("% .8x<--\n", 0);
			printf("% .8x<--\n\n", 0);

	ft_printf("-->##--x--##<--\n\n");

	ft_printf("-->Width_Precision<--\n\n");
	ft_printf("%#-10.12x<--\n", 42);
	printf("%#-10.12x<--\n\n", 42);
	ft_printf("%#-10.10x<--\n", 42);
	printf("%#-10.10x<--\n\n", 42);
	ft_printf("%#-10.8x<--\n", 42);
	printf("%#-10.8x<--\n\n", 42);
	ft_printf("%#-10.15x<--\n", 0);
	printf("%#-10.15x<--\n\n", 0);

	ft_printf("%#-10.8x<--\n", 20);
	printf("%#-10.8x<--\n\n", 20);
	ft_printf("%#-10.8x<--\n", 20);
	printf("%#-10.8x<--\n\n", 20);
	ft_printf("%#-10.6x<--\n", 120);
	printf("%#-10.6x<--\n\n", 120);
	ft_printf("%#-10.2x<--\n", 20);
	printf("%#-10.2x<--\n\n", 20);

	ft_printf("%#-10.1x<--\n", 120);
	printf("%#-10.1x<--\n\n", 120);
	ft_printf("%#-10.1x<--\n", 20);
	printf("%#-10.1x<--\n\n", 20);

	ft_printf("%#-10.2x<--\n", 0);
	printf("%#-10.2x<--\n\n", 0);
	ft_printf("%-10.2x<--\n", 0);
	printf("%-10.2x<--\n\n", 0);
	ft_printf("%#10.2x<--\n", 0);
	printf("%#10.2x<--\n\n", 0);

	ft_printf("%#-10.12x<--\n", 20);
	printf("%#-10.12x<--\n\n", 20);
	ft_printf("%#-10.12x<--\n", 120);
	printf("%#-10.12x<--\n\n", 120);
	ft_printf("%#-10.12x<--\n", 20);
	printf("%#-10.12x<--\n\n", 20);
	ft_printf("%#-10.12x<--\n", 0);
	printf("%#-10.12x<--\n\n", 0);

	ft_printf("-->Width<--\n\n");
	ft_printf("%#-10x<--\n", 42);
	printf("%#-10x<--\n\n", 42);
	ft_printf("%#-10x<--\n", 142);
	printf("%#-10x<--\n\n", 142);
	ft_printf("%#-10x<--\n", 42);
	printf("%#-10x<--\n\n", 42);
	ft_printf("%#-10x<--\n", 142);
	printf("%#-10x<--\n\n", 142);
	ft_printf("%#-10x<--\n", 20);
	printf("%#-10x<--\n\n", 20);
	ft_printf("%#-10x<--\n", 0);
	printf("%#-10x<--\n\n", 0);
	ft_printf("%#-1x<--\n", 42);
	printf("%#-1x<--\n\n", 42);

	ft_printf("-->Precision<--\n\n");
	ft_printf("%#-.8x<--\n", 42);
	printf("%#-.8x<--\n\n", 42);
	ft_printf("%#-.8x<--\n", 142);
	printf("%#-.8x<--\n\n", 142);
	ft_printf("%#-.8x<--\n", 42);
	printf("%#-.8x<--\n\n", 42);
	ft_printf("%#-.2x<--\n", 142);
	printf("%#-.2x<--\n\n", 142);
	ft_printf("%#-.8x<--\n", 0);
	printf("%#-.8x<--\n\n", 0);

	ft_printf("-->##--  x  --##<--\n\n");

	ft_printf("-->Width_Precision<--\n\n");
	ft_printf("%#- 10.12x<--\n", 42);
	printf("%#- 10.12x<--\n\n", 42);
	ft_printf("%#- 10.10x<--\n", 42);
	printf("%#- 10.10x<--\n\n", 42);
	ft_printf("%#- 10.8x<--\n", 42);
	printf("%#- 10.8x<--\n\n", 42);
	ft_printf("%#- 10.15x<--\n", 0);
	printf("%#- 10.15x<--\n\n", 0);

	ft_printf("%#- 10.8x<--\n", 20);
	printf("%#- 10.8x<--\n\n", 20);
	ft_printf("%#- 10.8x<--\n", 20);
	printf("%#- 10.8x<--\n\n", 20);
	ft_printf("%#- 10.6x<--\n", 120);
	printf("%#- 10.6x<--\n\n", 120);
	ft_printf("%#- 10.2x<--\n", 20);
	printf("%#- 10.2x<--\n\n", 20);

	ft_printf("%#- 10.1x<--\n", 120);
	printf("%#- 10.1x<--\n\n", 120);
	ft_printf("%#- 10.1x<--\n", 20);
	printf("%#- 10.1x<--\n\n", 20);

	ft_printf("%#- 10.2x<--\n", 0);
	printf("%#- 10.2x<--\n\n", 0);
	ft_printf("%#-10.2x<--\n", 0);
	printf("%#-10.2x<--\n\n", 0);
	ft_printf("%- 10.2x<--\n", 0);
	printf("%- 10.2x<--\n\n", 0);
	ft_printf("%-010.2x<--\n", 0);
	printf("%-010.2x<--\n\n", 0);
	ft_printf("%#10.2x<--\n", 0);
	printf("%#10.2x<--\n\n", 0);

	ft_printf("%#- 10.12x<--\n", 20);
	printf("%#- 10.12x<--\n\n", 20);
	ft_printf("%#- 10.12x<--\n", 120);
	printf("%#- 10.12x<--\n\n", 120);
	ft_printf("%#- 10.12x<--\n", 20);
	printf("%#- 10.12x<--\n\n", 20);
	ft_printf("%#- 10.12x<--\n", 0);
	printf("%#- 10.12x<--\n\n", 0);

	ft_printf("-->Width<--\n\n");
	ft_printf("%#- 10x<--\n", 42);
	printf("%#- 10x<--\n\n", 42);
	ft_printf("%#- 10x<--\n", 142);
	printf("%#- 10x<--\n\n", 142);
	ft_printf("%#- 10x<--\n", 42);
	printf("%#- 10x<--\n\n", 42);
	ft_printf("%#- 10x<--\n", 142);
	printf("%#- 10x<--\n\n", 142);
	ft_printf("%#- 10x<--\n", 20);
	printf("%#- 10x<--\n\n", 20);
	ft_printf("%#- 10x<--\n", 0);
	printf("%#- 10x<--\n\n", 0);
	ft_printf("%#- 1x<--\n", 42);
	printf("%#- 1x<--\n\n", 42);

	ft_printf("-->Precision<--\n\n");
	ft_printf("%#- .8x<--\n", 42);
	printf("%#- .8x<--\n\n", 42);
	ft_printf("%#- .8x<--\n", 142);
	printf("%#- .8x<--\n\n", 142);
	ft_printf("%#- .8x<--\n", 42);
	printf("%#- .8x<--\n\n", 42);
	ft_printf("%#- .2x<--\n", 142);
	printf("%#- .2x<--\n\n", 142);
	ft_printf("%#- .1x<--\n", 42);
	printf("%#- .1x<--\n\n", 42);
	ft_printf("%#- .x<--\n", 42);
	printf("%#- .x<--\n\n", 42);
	ft_printf("%.x<--\n", 42);
	printf("%.x<--\n\n", 42);
	ft_printf("%#.x<--\n", 42);
	printf("%#.x<--\n\n", 42);
	ft_printf("%#- .0x<--\n", 42);
	printf("%#- .0x<--\n\n", 42);
	ft_printf("%#- .8x<--\n", 0);
	printf("%#- .8x<--\n\n", 0);

	ft_printf("-->##++x++##<--\n\n");

	ft_printf("-->Width_Precision<--\n\n");
	ft_printf("%#-+10.12x<--\n", 42);
	printf("%#-+10.12x<--\n\n", 42);
	ft_printf("%#-+10.10x<--\n", 42);
	printf("%#-+10.10x<--\n\n", 42);
	ft_printf("%#-+10.8x<--\n", 42);
	printf("%#-+10.8x<--\n\n", 42);
	ft_printf("%#-+10.15x<--\n", 0);
	printf("%#-+10.15x<--\n\n", 0);

	ft_printf("%#-+10.8x<--\n", 20);
	printf("%#-+10.8x<--\n\n", 20);
	ft_printf("%#-+10.8x<--\n", 20);
	printf("%#-+10.8x<--\n\n", 20);
	ft_printf("%#-+10.6x<--\n", 120);
	printf("%#-+10.6x<--\n\n", 120);
	ft_printf("%#-+10.2x<--\n", 20);
	printf("%#-+10.2x<--\n\n", 20);

	ft_printf("%#-+10.1x<--\n", 120);
	printf("%#-+10.1x<--\n\n", 120);
	ft_printf("%#-+10.1x<--\n", 20);
	printf("%#-+10.1x<--\n\n", 20);

	ft_printf("%#-+10.2x<--\n", 0);
	printf("%#-+10.2x<--\n\n", 0);
	ft_printf("%#-+10.2x<--\n", 0);
	printf("%#-+10.2x<--\n\n", 0);
	ft_printf("%-+10.2x<--\n", 0);
	printf("%-+10.2x<--\n\n", 0);
	ft_printf("%-010.2x<--\n", 0);
	printf("%-010.2x<--\n\n", 0);
	ft_printf("%#10.2x<--\n", 0);
	printf("%#10.2x<--\n\n", 0);

	ft_printf("%#-+10.12x<--\n", 20);
	printf("%#-+10.12x<--\n\n", 20);
	ft_printf("%#-+10.12x<--\n", 120);
	printf("%#-+10.12x<--\n\n", 120);
	ft_printf("%#-+10.12x<--\n", 20);
	printf("%#-+10.12x<--\n\n", 20);
	ft_printf("%#-+10.12x<--\n", 0);
	printf("%#-+10.12x<--\n\n", 0);

	ft_printf("-->Width<--\n\n");
	ft_printf("%#-+10x<--\n", 42);
	printf("%#-+10x<--\n\n", 42);
	ft_printf("%#-+10x<--\n", 142);
	printf("%#-+10x<--\n\n", 142);
	ft_printf("%#-+10x<--\n", 42);
	printf("%#-+10x<--\n\n", 42);
	ft_printf("%#-+2x<--\n", 142);
	printf("%#-+1x<--\n\n", 142);
	ft_printf("%#-+2x<--\n", 20);
	printf("%#-+2x<--\n\n", 20);
	ft_printf("%#-+1x<--\n", 0);
	printf("%#-+1x<--\n\n", 0);
	ft_printf("%#-+1x<--\n", 42);
	printf("%#-+1x<--\n\n", 42);

	ft_printf("-->Precision<--\n\n");
	ft_printf("%#-+.8x<--\n", 42);
	printf("%#-+.8x<--\n\n", 42);
	ft_printf("%#-+.8x<--\n", 142);
	printf("%#-+.8x<--\n\n", 142);
	ft_printf("%#-+.8x<--\n", 42);
	printf("%#-+.8x<--\n\n", 42);
	ft_printf("%#-+.2x<--\n", 142);
	printf("%#-+.2x<--\n\n", 142);
	ft_printf("%#-+.1x<--\n", 42);
	printf("%#-+.1x<--\n\n", 42);
	ft_printf("%#-+.x<--\n", 42);
	printf("%#-+.x<--\n\n", 42);
	ft_printf("%+.x<--\n", 42);
	printf("%+.x<--\n\n", 42);
	ft_printf("%#.x<--\n", 42);
	printf("%#.x<--\n\n", 42);
	ft_printf("%#-+.0x<--\n", 42);
	printf("%#-+.0x<--\n\n", 42);
	ft_printf("%#-+.8x<--\n", 0);
	printf("%#-+.8x<--\n\n", 0);

	ft_printf("%#-+.0x<--\n", 0);
	printf("%#-+.0x<--\n\n", 0);
	ft_printf("%#-+.0x<--\n", 0);
	printf("%#-+.0x<--\n\n", 0);
	ft_printf("%#.0x<--\n", 0);
	printf("%#.0x<--\n\n", 0);
	ft_printf("%-.0x<--\n", 0);
	printf("%-.0x<--\n\n", 0);
	ft_printf("%-.0x<--\n", 0);
	printf("%-.0x<--\n\n", 0);
	ft_printf("%-.1x<--\n", 0);
	printf("%-.1x<--\n\n", 0);
	ft_printf("%10.0x<--\n", 0);
	printf("%10.0x<--\n\n", 0);
	ft_printf("%1.0x<--\n", 0);
	printf("%1.0x<--\n\n", 0);

	ft_printf("%#10.5llx<--\n", ULLONG_MAX);
	printf("%#10.5llx<--\n\n", ULLONG_MAX);

	ft_printf("%#10.5llx<--\n", LLONG_MIN);
	printf("%#10.5llx<--\n\n", LLONG_MIN);

	ft_printf("%#10.5lx<--\n", LONG_MAX);
	printf("%#10.5lx<--\n\n", LONG_MAX);

	ft_printf("%#10.5x<--\n", INT_MAX);
	printf("%#10.5x<--\n\n", INT_MAX);

	ft_putendl("Ok");
	ft_printf("%#10.5x<--\n", 42);
	printf("%#10.5x<--\n\n", 42);

	ft_printf("#10.0x %#10.0x<--\n", 42);
	printf("#10.0x %#10.0x<--\n\n", 42);

	ft_printf("#10.1x %#10.1x<--\n", 42);
	printf("#10.1x %#10.1x<--\n\n", 42);

	ft_printf("10.0x %10.0x<--\n", 42);
	printf("10.0x %10.0x<--\n\n", 42);

	ft_printf("10.1x %10.1x<--\n", 42);
	printf("10.1x %10.1x<--\n\n", 42);

	ft_printf("%#10.2x<--\n", 20);
	printf("%#10.2x<--\n\n", 20);

	ft_printf("%10.5x<--\n", LLONG_MAX);
	printf("%10.5x<--\n\n", LLONG_MAX);

	ft_printf("%llx<--\n", ULLONG_MAX);
	printf("%llx<--\n", ULLONG_MAX);

	printf("%llx<--\n", ULLONG_MAX);
	printf("%+llx<--\n\n", LLONG_MIN);
	printf("% llo<--\n\n", LLONG_MIN);
	printf("%#llo<--\n\n", LLONG_MIN);
	printf("%0llo<--\n\n", LLONG_MIN);
*/
/*	ft_printf("%-15O$\n", -15);
	printf("%-15O$\n", -15);
	ft_printf("%-O$\n", -15);
	printf("%-O$\n", -15);
	ft_printf("%-O$\n", 15);
	printf("%-O$\n", 15);
	ft_printf("%-O$\n", 0);
	printf("%-O$\n", 0);
		ft_printf("%10.2o<--\n", 20);
		printf("%10.2o<--\n\n", 20);
		ft_printf("%10.2o<--\n", -20);
		printf("%10.2o<--\n\n", -20);

		ft_printf("%10o<--\n", -20);
		printf("%10o<--\n\n", -20);

		ft_printf("%4o<--\n", -20);
		printf("%4o<--\n\n", -20);
		ft_printf("%6o<--\n", -20);
		printf("%6o<--\n\n", -20);
*/
		ft_putendl("x.x");
		ft_printf("%10.10o<--\n", -20);
		printf("%10.10o<--\n\n", -20);
		ft_printf("%2.10o<--\n", -142);
		printf("%2.10o<--\n\n", -142);
		ft_printf("%2.10o<--\n", 142);
		printf("%2.10o<--\n\n", 142);
		ft_printf("%1.10o<--\n", 142);
		printf("%1.10o<--\n\n", 142);
		ft_printf("%10.5o<--\n", 20);
		printf("%10.5o<--\n\n", 20);
		ft_printf("%10.2o<--\n", 20);
		printf("%10.2o<--\n\n", 20);
		ft_printf("%10.1o<--\n", 20); //
		printf("%10.1o<--\n\n", 20); //
		ft_printf("%10.1o<--\n", 142); //
		printf("%10.1o<--\n\n", 142); //
		ft_printf("%10.1o<--\n", 1420); //
		printf("%10.1o<--\n\n", 1420); //

		ft_printf("%10.15o<--\n", 142);
		printf("%10.15o<--\n\n", 142);

		ft_printf("%10.0o<--\n", 0);
		printf("%10.0o<--\n\n", 0);

		ft_printf("%10.0o<--\n", 1); //
		printf("%10.0o<--\n\n", 1);

		ft_printf("%10.1o<--\n", 0);
		printf("%10.1o<--\n\n", 0);

		ft_putendl("x");
		ft_printf("%10o<--\n", -20);
		printf("%10o<--\n\n", -20);
		ft_printf("%2o<--\n", -142);
		printf("%2o<--\n\n", -142);
		ft_printf("%2o<--\n", 142);
		printf("%2o<--\n\n", 142);
		ft_printf("%1o<--\n", 142);
		printf("%1o<--\n\n", 142);
		ft_printf("%10o<--\n", 20);
		printf("%10o<--\n\n", 20);
		ft_printf("%10o<--\n", 20);
		printf("%10o<--\n\n", 20);

		ft_printf("%15o<--\n", 142);
		printf("%15o<--\n\n", 142);
		ft_printf("%1o<--\n", 0);
		printf("%1o<--\n\n", 0);

		ft_printf("%30o<--\n", 1);
		printf("%30o<--\n\n", 1);
		ft_printf("%50o<--\n", 0);
		printf("%50o<--\n\n", 0);

		ft_printf("%.25o<--\n", -20);
		printf("%.25o<--\n\n", -20);
		ft_printf("%.25o<--\n", 20);
		printf("%.25o<--\n\n", 20);
		ft_printf("%.25o<--\n", 0);
		printf("%.25o<--\n\n", 0);

		ft_printf("%10o<--\n", -20);
		printf("%10o<--\n\n", -20);
		ft_printf("%10o<--\n", -142);
		printf("%10o<--\n\n", -142);
		ft_printf("%10o<--\n", 20);
		printf("%10o<--\n\n", 20);
		ft_printf("%10o<--\n", 142);
		printf("%10o<--\n\n", 142);
		ft_printf("%10o<--\n", 0);
		printf("%10o<--\n\n", 0);
        ft_printf("%10o<--\n", -1);
        printf("%10o<--\n\n", -1);


			printf("-->###<--\n\n");

			ft_printf("-->Width_Precision<--\n\n");
			ft_printf("%#10.10o<--\n", 42);
			printf("%#10.10o<--\n\n", 42);

			ft_printf("%#10.10o<--\n", 4242);
			printf("%#10.10o<--\n\n", 4242);

			ft_printf("%#10.15o<--\n", 0);
			printf("%#10.15o<--\n\n", 0);

			ft_printf("%#10.8o<--\n", 42);
			printf("%#10.8o<--\n\n", 42);

			ft_printf("%#10.8o<--\n", 20);
			printf("%#10.8o<--\n\n", 20);

			ft_printf("%#10.4o<--\n", 20);
			printf("%#10.4o<--\n\n", 20);

			ft_printf("%#10.6o<--\n", 120);
			printf("%#10.6o<--\n\n", 120);

			ft_printf("%#10.8o<--\n", 1200);
			printf("%#10.8o<--\n\n", 1200);

			ft_printf("%#10.1o<--\n", 120);
			printf("%#10.1o<--\n\n", 120);

			ft_printf("%#10.6o<--\n", 242);
			printf("%#10.6o<--\n\n", 242);

			ft_printf("%#10.6o<--\n", 4242);
			printf("%#10.6o<--\n\n", 4242);

			ft_printf("%#10.2o<--\n", 4242);
			printf("%#10.2o<--\n\n", 4242);

			ft_printf("%#10.0o<--\n", 4242);
			printf("%#10.0o<--\n\n", 4242);

			ft_printf("%#10.5o<--\n", 4242);
			printf("%#10.5o<--\n\n", 4242);

			ft_printf("%#10.2o<--\n", 20);
			printf("%#10.2o<--\n\n", 20);

			ft_putendl("ok");
			ft_printf("%#10.2o<--\n", 0);
			printf("%#10.2o<--\n\n", 0);

			ft_printf("%#10.4o<--\n", 0);
			printf("%#10.4o<--\n\n", 0);

			ft_printf("%10.2o<--\n", 0);
			printf("%10.2o<--\n\n", 0);
			ft_printf("%.2o<--\n", 0);
			printf("%.2o<--\n\n", 0);
			ft_printf("%10o<--\n", 0);
			printf("%10o<--\n\n", 0);
			ft_printf("%#10.5o<--\n", ULLONG_MAX);
			printf("%#10.5o<--\n\n", ULLONG_MAX);
			ft_printf("%10.5o<--\n", LLONG_MAX);
			printf("%10.5o<--\n\n", LLONG_MAX);

			ft_printf("%#10.12o<--\n", 20);
			printf("%#10.12o<--\n\n", 20);
			ft_printf("%#10.12o<--\n", 120);
			printf("%#10.12o<--\n\n", 120);
			ft_printf("%#10.12o<--\n", 20);
			printf("%#10.12o<--\n\n", 20);

			ft_printf("%#10.12o<--\n", 0);
			printf("%#10.12o<--\n\n", 0);

			ft_printf("-->Width<--\n\n");
			ft_printf("%#10o<--\n", 42);
			printf("%#10o<--\n\n", 42);
			ft_printf("%#10o<--\n", 142);
			printf("%#10o<--\n\n", 142);
			ft_printf("%#10o<--\n", 14200);
			printf("%#10o<--\n\n", 14200);
			ft_printf("%#10o<--\n", 42);
			printf("%#10o<--\n\n", 42);
			ft_printf("%#10o<--\n", 142);
			printf("%#10o<--\n\n", 142);
			ft_printf("%#10o<--\n", 20);
			printf("%#10o<--\n\n", 20);
			ft_printf("%#10o<--\n", 0);
			printf("%#10o<--\n\n", 0);
			ft_printf("%#1o<--\n", 42);
			printf("%#1o<--\n\n", 42);

			ft_printf("-->Precision<--\n\n");
			ft_printf("%#.8o<--\n", 42);
			printf("%#.8o<--\n\n", 42);

			ft_printf("%#.8o<--\n", 142);
			printf("%#.8o<--\n\n", 142);

			ft_printf("%#.8o<--\n", 42);
			printf("%#.8o<--\n\n", 42);

			ft_printf("%#.2o<--\n", 142);
			printf("%#.2o<--\n\n", 142);

			ft_printf("%#.8o<--\n", 0);
			printf("%#.8o<--\n\n", 0);

/*			printf("-->---<--\n\n");

			ft_printf("-->Width_Precision<--\n\n");
			ft_printf("%-10.10o<--\n", 42);
			printf("%-10.10o<--\n\n", 42);
			ft_printf("%-10.8o<--\n", 42);
			printf("%-10.8o<--\n\n", 42);
			ft_printf("%-10.15o<--\n", 0);
			printf("%-10.15o<--\n\n", 0);
			ft_printf("%-10.8o<--\n", 20);
			printf("%-10.8o<--\n\n", 20);
			ft_printf("%-10.8o<--\n", 20);
			printf("%-10.8o<--\n\n", 20);
			ft_printf("%-10.6o<--\n", 120);
			printf("%-10.6o<--\n\n", 120);
			ft_printf("%-10.2o<--\n", 20);
			printf("%-10.2o<--\n\n", 20);

			ft_printf("%-10.2o<--\n", 0);
			printf("%-10.2o<--\n\n", 0);

			ft_printf("%-10.4o<--\n", 0);
			printf("%-10.4o<--\n\n", 0);

	//			ft_printf("%10.2o<--\n", 0);
	//			printf("%10.2o<--\n\n", 0);
			ft_printf("%-10.5o<--\n", ULLONG_MAX);
			printf("%-10.5o<--\n\n", ULLONG_MAX);
			ft_printf("%-10.2o<--\n", 100000);
			printf("%-10.2o<--\n\n", 100000);
			ft_printf("%-10.1o<--\n", 100);
			printf("%-10.1o<--\n\n", 100);
			ft_printf("%-10.0o<--\n", 10);
			printf("%-10.0o<--\n\n", 10);
	//			ft_printf("%10.5o<--\n", LLONG_MAX);
	//			printf("%10.5o<--\n\n", LLONG_MAX);

			ft_printf("%-10.12o<--\n", 20);
			printf("%-10.12o<--\n\n", 20);
			ft_printf("%-10.12o<--\n", 120);
			printf("%-10.12o<--\n\n", 120);
			ft_printf("%-10.12o<--\n", 20);
			printf("%-10.12o<--\n\n", 20);

			ft_printf("%-10.12o<--\n", 0);
			printf("%-10.12o<--\n\n", 0);

			ft_printf("-->Width<--\n\n");
			ft_printf("%-10o<--\n", 42);
			printf("%-10o<--\n\n", 42);
			ft_printf("%-10o<--\n", 142);
			printf("%-10o<--\n\n", 142);
			ft_printf("%-10o<--\n", 14200);
			printf("%-10o<--\n\n", 14200);
			ft_printf("%-10o<--\n", 42);
			printf("%-10o<--\n\n", 42);
			ft_printf("%-10o<--\n", 142);
			printf("%-10o<--\n\n", 142);
			ft_printf("%-10o<--\n", 20);
			printf("%-10o<--\n\n", 20);
			ft_printf("%-10o<--\n", 0);
			printf("%-10o<--\n\n", 0);
			ft_printf("%-1o<--\n", 42);
			printf("%-1o<--\n\n", 42);

			ft_printf("-->Precision<--\n\n");
			ft_printf("%-.8o<--\n", 42);
			printf("%-.8o<--\n\n", 42);
			ft_printf("%-.8o<--\n", 142);
			printf("%-.8o<--\n\n", 142);
			ft_printf("%-.8o<--\n", 42);
			printf("%-.8o<--\n\n", 42);
			ft_printf("%-.2o<--\n", 142);
			printf("%-.2o<--\n\n", 142);
			ft_printf("%-.8o<--\n", 0);
			printf("%-.8o<--\n\n", 0);

			printf("-->   <--\n\n");

			ft_printf("-->Width_Precision<--\n\n");
			ft_printf("% 10.10o<--\n", 42);
			printf("% 10.10o<--\n\n", 42);
			ft_printf("% 10.8o<--\n", 42);
			printf("% 10.8o<--\n\n", 42);
			ft_printf("% 10.15o<--\n", 0);
			printf("% 10.15o<--\n\n", 0);
			ft_printf("% 10.8o<--\n", 20);
			printf("% 10.8o<--\n\n", 20);
			ft_printf("% 10.8o<--\n", 20);
			printf("% 10.8o<--\n\n", 20);
			ft_printf("% 10.6o<--\n", 120);
			printf("% 10.6o<--\n\n", 120);
			ft_printf("% 10.2o<--\n", 20);
			printf("% 10.2o<--\n\n", 20);

			ft_printf("% 10.2o<--\n", 0);
			printf("% 10.2o<--\n\n", 0);

			ft_printf("% 10.4o<--\n", 0);
			printf("% 10.4o<--\n\n", 0);

			//			ft_printf("%10.2o<--\n", 0);
			//			printf("%10.2o<--\n\n", 0);
			ft_printf("% 10.5o<--\n", ULLONG_MAX);
			printf("% 10.5o<--\n\n", ULLONG_MAX);
			ft_printf("% 10.2o<--\n", 100000);
			printf("% 10.2o<--\n\n", 100000);
			ft_printf("% 10.1o<--\n", 100);
			printf("% 10.1o<--\n\n", 100);
			ft_printf("% 10.0o<--\n", 10);
			printf("% 10.0o<--\n\n", 10);
			//			ft_printf("%10.5o<--\n", LLONG_MAX);
			//			printf("%10.5o<--\n\n", LLONG_MAX);

			ft_printf("% 10.12o<--\n", 20);
			printf("% 10.12o<--\n\n", 20);
			ft_printf("% 10.12o<--\n", 120);
			printf("% 10.12o<--\n\n", 120);
			ft_printf("% 10.12o<--\n", 20);
			printf("% 10.12o<--\n\n", 20);

			ft_printf("% 10.12o<--\n", 0);
			printf("% 10.12o<--\n\n", 0);

			ft_printf("-->Width<--\n\n");
			ft_printf("% 10o<--\n", 42);
			printf("% 10o<--\n\n", 42);
			ft_printf("% 10o<--\n", 142);
			printf("% 10o<--\n\n", 142);
			ft_printf("% 10o<--\n", 14200);
			printf("% 10o<--\n\n", 14200);
			ft_printf("% 10o<--\n", 42);
			printf("% 10o<--\n\n", 42);
			ft_printf("% 10o<--\n", 142);
			printf("% 10o<--\n\n", 142);
			ft_printf("% 10o<--\n", 20);
			printf("% 10o<--\n\n", 20);
			ft_printf("% 10o<--\n", 0);
			printf("% 10o<--\n\n", 0);
			ft_printf("% 1o<--\n", 42);
			printf("% 1o<--\n\n", 42);

			ft_printf("-->Precision<--\n\n");
			ft_printf("% .8o<--\n", 42);
			printf("% .8o<--\n\n", 42);
			ft_printf("% .8o<--\n", 142);
			printf("% .8o<--\n\n", 142);
			ft_printf("% .8o<--\n", 42);
			printf("% .8o<--\n\n", 42);
			ft_printf("% .2o<--\n", 142);
			printf("% .2o<--\n\n", 142);
			ft_printf("% .8o<--\n", 0);
			printf("% .8o<--\n\n", 0);

	ft_printf("-->##--x--##<--\n\n");

	ft_printf("-->Width_Precision<--\n\n");
	ft_printf("%#-10.12o<--\n", 42);
	printf("%#-10.12o<--\n\n", 42);
	ft_printf("%#-10.10o<--\n", 42);
	printf("%#-10.10o<--\n\n", 42);
	ft_printf("%#-10.8o<--\n", 42);
	printf("%#-10.8o<--\n\n", 42);
	ft_printf("%#-10.15o<--\n", 0);
	printf("%#-10.15o<--\n\n", 0);

	ft_printf("%#-10.8o<--\n", 20);
	printf("%#-10.8o<--\n\n", 20);
	ft_printf("%#-10.8o<--\n", 20);
	printf("%#-10.8o<--\n\n", 20);
	ft_printf("%#-10.6o<--\n", 120);
	printf("%#-10.6o<--\n\n", 120);
	ft_printf("%#-10.2o<--\n", 20);
	printf("%#-10.2o<--\n\n", 20);

	ft_printf("%#-10.1o<--\n", 120);
	printf("%#-10.1o<--\n\n", 120);
	ft_printf("%#-10.1o<--\n", 20);
	printf("%#-10.1o<--\n\n", 20);

	ft_printf("%#-10.2o<--\n", 0);
	printf("%#-10.2o<--\n\n", 0);
	ft_printf("%-10.2o<--\n", 0);
	printf("%-10.2o<--\n\n", 0);
	ft_printf("%#10.2o<--\n", 0);
	printf("%#10.2o<--\n\n", 0);

	ft_printf("%#-10.12o<--\n", 20);
	printf("%#-10.12o<--\n\n", 20);
	ft_printf("%#-10.12o<--\n", 120);
	printf("%#-10.12o<--\n\n", 120);
	ft_printf("%#-10.12o<--\n", 20);
	printf("%#-10.12o<--\n\n", 20);
	ft_printf("%#-10.12o<--\n", 0);
	printf("%#-10.12o<--\n\n", 0);

	ft_printf("-->Width<--\n\n");
	ft_printf("%#-10o<--\n", 42);
	printf("%#-10o<--\n\n", 42);
	ft_printf("%#-10o<--\n", 142);
	printf("%#-10o<--\n\n", 142);
	ft_printf("%#-10o<--\n", 42);
	printf("%#-10o<--\n\n", 42);
	ft_printf("%#-10o<--\n", 142);
	printf("%#-10o<--\n\n", 142);
	ft_printf("%#-10o<--\n", 20);
	printf("%#-10o<--\n\n", 20);
	ft_printf("%#-10o<--\n", 0);
	printf("%#-10o<--\n\n", 0);
	ft_printf("%#-1o<--\n", 42);
	printf("%#-1o<--\n\n", 42);

	ft_printf("-->Precision<--\n\n");
	ft_printf("%#-.8o<--\n", 42);
	printf("%#-.8o<--\n\n", 42);
	ft_printf("%#-.8o<--\n", 142);
	printf("%#-.8o<--\n\n", 142);
	ft_printf("%#-.8o<--\n", 42);
	printf("%#-.8o<--\n\n", 42);
	ft_printf("%#-.2o<--\n", 142);
	printf("%#-.2o<--\n\n", 142);
	ft_printf("%#-.8o<--\n", 0);
	printf("%#-.8o<--\n\n", 0);

	ft_printf("-->##--  x  --##<--\n\n");

	ft_printf("-->Width_Precision<--\n\n");
	ft_printf("%#- 10.12o<--\n", 42);
	printf("%#- 10.12o<--\n\n", 42);
	ft_printf("%#- 10.10o<--\n", 42);
	printf("%#- 10.10o<--\n\n", 42);
	ft_printf("%#- 10.8o<--\n", 42);
	printf("%#- 10.8o<--\n\n", 42);
	ft_printf("%#- 10.15o<--\n", 0);
	printf("%#- 10.15o<--\n\n", 0);

	ft_printf("%#- 10.8o<--\n", 20);
	printf("%#- 10.8o<--\n\n", 20);
	ft_printf("%#- 10.8o<--\n", 20);
	printf("%#- 10.8o<--\n\n", 20);
	ft_printf("%#- 10.6o<--\n", 120);
	printf("%#- 10.6o<--\n\n", 120);
	ft_printf("%#- 10.2o<--\n", 20);
	printf("%#- 10.2o<--\n\n", 20);

	ft_printf("%#- 10.1o<--\n", 120);
	printf("%#- 10.1o<--\n\n", 120);
	ft_printf("%#- 10.1o<--\n", 20);
	printf("%#- 10.1o<--\n\n", 20);

	ft_printf("%#- 10.2o<--\n", 0);
	printf("%#- 10.2o<--\n\n", 0);
	ft_printf("%#-10.2o<--\n", 0);
	printf("%#-10.2o<--\n\n", 0);
	ft_printf("%- 10.2o<--\n", 0);
	printf("%- 10.2o<--\n\n", 0);
	ft_printf("%-010.2o<--\n", 0);
	printf("%-010.2o<--\n\n", 0);
	ft_printf("%#10.2o<--\n", 0);
	printf("%#10.2o<--\n\n", 0);

	ft_printf("%#- 10.12o<--\n", 20);
	printf("%#- 10.12o<--\n\n", 20);
	ft_printf("%#- 10.12o<--\n", 120);
	printf("%#- 10.12o<--\n\n", 120);
	ft_printf("%#- 10.12o<--\n", 20);
	printf("%#- 10.12o<--\n\n", 20);
	ft_printf("%#- 10.12o<--\n", 0);
	printf("%#- 10.12o<--\n\n", 0);

	ft_printf("-->Width<--\n\n");
	ft_printf("%#- 10o<--\n", 42);
	printf("%#- 10o<--\n\n", 42);
	ft_printf("%#- 10o<--\n", 142);
	printf("%#- 10o<--\n\n", 142);
	ft_printf("%#- 10o<--\n", 42);
	printf("%#- 10o<--\n\n", 42);
	ft_printf("%#- 10o<--\n", 142);
	printf("%#- 10o<--\n\n", 142);
	ft_printf("%#- 10o<--\n", 20);
	printf("%#- 10o<--\n\n", 20);
	ft_printf("%#- 10o<--\n", 0);
	printf("%#- 10o<--\n\n", 0);
	ft_printf("%#- 1o<--\n", 42);
	printf("%#- 1o<--\n\n", 42);

	ft_printf("-->Precision<--\n\n");
	ft_printf("%#- .8o<--\n", 42);
	printf("%#- .8o<--\n\n", 42);
	ft_printf("%#- .8o<--\n", 142);
	printf("%#- .8o<--\n\n", 142);
	ft_printf("%#- .8o<--\n", 42);
	printf("%#- .8o<--\n\n", 42);
	ft_printf("%#- .2o<--\n", 142);
	printf("%#- .2o<--\n\n", 142);
	ft_printf("%#- .1o<--\n", 42);
	printf("%#- .1o<--\n\n", 42);
	ft_printf("%#- .o<--\n", 42);
	printf("%#- .o<--\n\n", 42);
	ft_printf("%.o<--\n", 42);
	printf("%.o<--\n\n", 42);
	ft_printf("%#.o<--\n", 42);
	printf("%#.o<--\n\n", 42);
	ft_printf("%#- .0o<--\n", 42);
	printf("%#- .0o<--\n\n", 42);
	ft_printf("%#- .8o<--\n", 0);
	printf("%#- .8o<--\n\n", 0);

	ft_printf("-->##++x++##<--\n\n");

	ft_printf("-->Width_Precision<--\n\n");
	ft_printf("%#-+10.12o<--\n", 42);
	printf("%#-+10.12o<--\n\n", 42);
	ft_printf("%#-+10.10o<--\n", 42);
	printf("%#-+10.10o<--\n\n", 42);
	ft_printf("%#-+10.8o<--\n", 42);
	printf("%#-+10.8o<--\n\n", 42);
	ft_printf("%#-+10.15o<--\n", 0);
	printf("%#-+10.15o<--\n\n", 0);

	ft_printf("%#-+10.8o<--\n", 20);
	printf("%#-+10.8o<--\n\n", 20);
	ft_printf("%#-+10.8o<--\n", 20);
	printf("%#-+10.8o<--\n\n", 20);
	ft_printf("%#-+10.6o<--\n", 120);
	printf("%#-+10.6o<--\n\n", 120);
	ft_printf("%#-+10.2o<--\n", 20);
	printf("%#-+10.2o<--\n\n", 20);

	ft_printf("%#-+10.1o<--\n", 120);
	printf("%#-+10.1o<--\n\n", 120);
	ft_printf("%#-+10.1o<--\n", 20);
	printf("%#-+10.1o<--\n\n", 20);

	ft_printf("%#-+10.2o<--\n", 0);
	printf("%#-+10.2o<--\n\n", 0);
	ft_printf("%#-+10.2o<--\n", 0);
	printf("%#-+10.2o<--\n\n", 0);
	ft_printf("%-+10.2o<--\n", 0);
	printf("%-+10.2o<--\n\n", 0);
	ft_printf("%-010.2o<--\n", 0);
	printf("%-010.2o<--\n\n", 0);
	ft_printf("%#10.2o<--\n", 0);
	printf("%#10.2o<--\n\n", 0);

	ft_printf("%#-+10.12o<--\n", 20);
	printf("%#-+10.12o<--\n\n", 20);
	ft_printf("%#-+10.12o<--\n", 120);
	printf("%#-+10.12o<--\n\n", 120);
	ft_printf("%#-+10.12o<--\n", 20);
	printf("%#-+10.12o<--\n\n", 20);
	ft_printf("%#-+10.12o<--\n", 0);
	printf("%#-+10.12o<--\n\n", 0);

	ft_printf("-->Width<--\n\n");
	ft_printf("%#-+10o<--\n", 42);
	printf("%#-+10o<--\n\n", 42);
	ft_printf("%#-+10o<--\n", 142);
	printf("%#-+10o<--\n\n", 142);
	ft_printf("%#-+10o<--\n", 42);
	printf("%#-+10o<--\n\n", 42);
	ft_printf("%#-+2o<--\n", 142);
	printf("%#-+1o<--\n\n", 142);
	ft_printf("%#-+2o<--\n", 20);
	printf("%#-+2o<--\n\n", 20);
	ft_printf("%#-+1o<--\n", 0);
	printf("%#-+1o<--\n\n", 0);
	ft_printf("%#-+1o<--\n", 42);
	printf("%#-+1o<--\n\n", 42);

	ft_printf("-->Precision<--\n\n");
	ft_printf("%#-+.8o<--\n", 42);
	printf("%#-+.8o<--\n\n", 42);
	ft_printf("%#-+.8o<--\n", 142);
	printf("%#-+.8o<--\n\n", 142);
	ft_printf("%#-+.8o<--\n", 42);
	printf("%#-+.8o<--\n\n", 42);
	ft_printf("%#-+.2o<--\n", 142);
	printf("%#-+.2o<--\n\n", 142);
	ft_printf("%#-+.1o<--\n", 42);
	printf("%#-+.1o<--\n\n", 42);
	ft_printf("%#-+.o<--\n", 42);
	printf("%#-+.o<--\n\n", 42);
	ft_printf("%+.o<--\n", 42);
	printf("%+.o<--\n\n", 42);
	ft_printf("%#.o<--\n", 42);
	printf("%#.o<--\n\n", 42);
	ft_printf("%#-+.0o<--\n", 42);
	printf("%#-+.0o<--\n\n", 42);
	ft_printf("%#-+.8o<--\n", 0);
	printf("%#-+.8o<--\n\n", 0);

	ft_printf("%#-+.0o<--\n", 0);
	printf("%#-+.0o<--\n\n", 0);
	ft_printf("%#-+.0o<--\n", 0);
	printf("%#-+.0o<--\n\n", 0);
	ft_printf("%#.0o<--\n", 0);
	printf("%#.0o<--\n\n", 0);
	ft_printf("%-.0o<--\n", 0);
	printf("%-.0o<--\n\n", 0);
	ft_printf("%-.0o<--\n", 0);
	printf("%-.0o<--\n\n", 0);
	ft_printf("%-.1o<--\n", 0);
	printf("%-.1o<--\n\n", 0);
	ft_printf("%10.0o<--\n", 0);
	printf("%10.0o<--\n\n", 0);
	ft_printf("%1.0o<--\n", 0);
	printf("%1.0o<--\n\n", 0);

	ft_printf("%#10.5llo<--\n", ULLONG_MAX);
	printf("%#10.5llo<--\n\n", ULLONG_MAX);

	ft_printf("%#10.5llo<--\n", LLONG_MIN);
	printf("%#10.5llo<--\n\n", LLONG_MIN);

	ft_printf("%#10.5lo<--\n", LONG_MAX);
	printf("%#10.5lo<--\n\n", LONG_MAX);

	ft_printf("%#10.5o<--\n", INT_MAX);
	printf("%#10.5o<--\n\n", INT_MAX);

	ft_putendl("Ok");
	ft_printf("%#10.5o<--\n", 42);
	printf("%#10.5o<--\n\n", 42);

	ft_printf("#10.0x %#10.0o<--\n", 42);
	printf("#10.0x %#10.0o<--\n\n", 42);

	ft_printf("#10.1x %#10.1o<--\n", 42);
	printf("#10.1x %#10.1o<--\n\n", 42);

	ft_printf("10.0x %10.0o<--\n", 42);
	printf("10.0x %10.0o<--\n\n", 42);

	ft_printf("10.1x %10.1o<--\n", 42);
	printf("10.1x %10.1o<--\n\n", 42);

	ft_printf("%#10.2o<--\n", 20);
	printf("%#10.2o<--\n\n", 20);

	ft_printf("%10.5o<--\n", LLONG_MAX);
	printf("%10.5o<--\n\n", LLONG_MAX);

	ft_printf("%llo<--\n", ULLONG_MAX);
	printf("%llo<--\n", ULLONG_MAX);

	printf("%llo<--\n", ULLONG_MAX);
	printf("%+llo<--\n\n", LLONG_MIN);
	printf("% llo<--\n\n", LLONG_MIN);
	printf("%#llo<--\n\n", LLONG_MIN);
	printf("%0llo<--\n\n", LLONG_MIN);
*/
	//printf("% d\n", -10);
	//printf("% d\n", 0);
//    ft_printf("%-040.25d %-040.25d\n", 120);
//    ft_printf("%-12.94d\n", 120);
    //    ft_printf("%-12.94d\n", 120);
    //        ft_printf("%-12.94d\n", 120);
    //            ft_printf("%-120.940d\n", 120);
    //                ft_printf("%-12.94d\n", 120);
    //                    ft_printf("%-12.94d\n", 120);
    //ft_printf("###%-666.999d\n", 120);
    //printf("\n###%+42.25d\n", 120);
    return (0);
}
