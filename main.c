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
	printf("% llx<--\n\n", LLONG_MIN);
	printf("%#llx<--\n\n", LLONG_MIN);
	printf("%0llx<--\n\n", LLONG_MIN);
*/
/*	ft_printf("%-15O$\n", -15);
	printf("%-15O$\n", -15);
	ft_printf("%-O$\n", -15);
	printf("%-O$\n", -15);
	ft_printf("%-O$\n", 15);
	printf("%-O$\n", 15);
	ft_printf("%-O$\n", 0);
	printf("%-O$\n", 0);
*/		ft_printf("%10.2o<--\n", 20);
		printf("%10.2o<--\n\n", 20);
		ft_printf("%10.2o<--\n", -20);
		printf("%10.2o<--\n\n", -20);

		ft_printf("%10o<--\n", -20);
		printf("%10o<--\n\n", -20);

		ft_printf("%4o<--\n", -20);
		printf("%4o<--\n\n", -20);
		ft_printf("%6o<--\n", -20);
		printf("%6o<--\n\n", -20);

		ft_printf("%060o<--\n", -20);
		printf("%060o<--\n\n", -20);

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

		ft_printf("%010o<--\n", 10);
		printf("%010o<--\n\n", 10);
		ft_printf("%10o<--\n", 10);
		printf("%10o<--\n\n", 10);

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

			printf("-->---<--\n\n");

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

	ft_printf("%#10.12o<--\n", 20);
	printf("%#10.12o<--\n\n", 20);
	ft_printf("%#10.12o<--\n", 120);
	printf("%#10.12o<--\n\n", 120);
	ft_printf("%#10.12o<--\n", 20);
	printf("%#10.12o<--\n\n", 20);

	ft_printf("%#10.12o<--\n", 0);
	printf("%#10.12o<--\n\n", 0);

	ft_printf("%#-10.2o<--\n", 0);
	printf("%#-10.2o<--\n\n", 0);
	ft_printf("%#-10.0o<--\n", 0);
	printf("%#-10.0o<--\n\n", 0);
	ft_printf("%#-10.1o<--\n", 0);
	printf("%#-10.1o<--\n\n", 0);
//	ft_printf("%-10.2o<--\n", 0);
//	printf("%-10.2o<--\n\n", 0);
//	ft_printf("%#10.2o<--\n", 0);
//	printf("%#10.2o<--\n\n", 0);

	ft_printf("%#-10.12o<--\n", 20);
	printf("%#-10.12o<--\n\n", 20);
	ft_printf("%#-10.12o<--\n", 120);
	printf("%#-10.12o<--\n\n", 120);
	ft_printf("%#-10.13o<--\n", 1200);
	printf("%#-10.13o<--\n\n", 1200);
	ft_printf("%#-10.12o<--\n", 1200);
	printf("%#-10.12o<--\n\n", 1200);
	ft_printf("%#-10.12o<--\n", 20);
	printf("%#-10.12o<--\n\n", 20);
	ft_printf("%#-10.12o<--\n", 0);
	printf("%#-10.12o<--\n\n", 0);

	ft_printf("%10.1o<--\n", 0);
	printf("%10.1o<--\n\n", 0);

	ft_printf("%10.2o<--\n", 16);
	printf("%10.2o<--\n\n", 16);

	ft_printf("%10.o<--\n", 0);
	printf("%10.o<--\n\n", 0);

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
	ft_printf("%#-1o<--\n", 424242);
	printf("%#-1o<--\n\n", 424242);
	ft_printf("%#-25o<--\n", 424242);
	printf("%#-25o<--\n\n", 424242);
	ft_printf("%#-7o<--\n", 424242);
	printf("%#-7o<--\n\n", 424242);
	ft_printf("%#-8o<--\n", 424242);
	printf("%#-8o<--\n\n", 424242);
	ft_printf("%#-o<--\n", 424242);
	printf("%#-o<--\n\n", 424242);
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

	ft_printf("%#-+.0o<--\n", 0);
	printf("%#-+.0o<--\n\n", 0);
	ft_printf("%#-+.0o<--\n", 0);
	printf("%#-+.0o<--\n\n", 0);
	ft_printf("%#.0o<--\n", 0);
	printf("%#.0o<--\n\n", 0);

	ft_putendl("OK");
	ft_printf("%#-+.1o<--\n", 0);
	printf("%#-+.1o<--\n\n", 0);
	ft_printf("%#-+.o<--\n", 0);
	printf("%#-+.o<--\n\n", 0);
	ft_printf("%#- .1o<--\n", 0);
	printf("%#- .1o<--\n\n", 0);
	ft_printf("%#-.1o<--\n", 0);
	printf("%#-.1o<--\n\n", 0);
	ft_printf("%#.1o<--\n", 0);
	printf("%#.1o<--\n\n", 0);
	ft_printf("%.1o<--\n", 0);
	printf("%.1o<--\n\n", 0);
	ft_printf("#-+.8o %#-+.8o<--\n", 0);
	printf("#-+.8o %#-+.8o<--\n\n", 0);
	ft_printf("#-.8o %#-.8o<--\n", 0);
	printf("#-.8o %#-.8o<--\n\n", 0);
	ft_printf("#.8 %#.8o<--\n", 0);
	printf("#.8 %#.8o<--\n\n", 0);
	ft_printf("-+.8o %-+.8o<--\n", 0);
	printf("-+.8o %-+.8o<--\n\n", 0);
	ft_printf("-.8o %-.8o<--\n", 0);
	printf("-.8o %-.8o<--\n\n", 0);
	ft_printf(".8 %.8o<--\n", 0);
	printf(".8 %.8o<--\n\n", 0);
	ft_putendl("/");
	ft_printf("#-+.1o %#-+.1o<--\n", 0);
	printf("#-+.1o %#-+.1o<--\n\n", 0);
	ft_printf("#-+.2o %#-+.2o<--\n", 0);
	printf("#-+.2o %#-+.2o<--\n\n", 0);
	ft_printf("#-+.1o %#-+.1o<--\n", 0);
	printf("#-+.1o %#-+.1o<--\n\n", 0);
	ft_printf("#-.8o %#-.8o<--\n", 0);
	printf("#-.8o %#-.8o<--\n\n", 0);
	ft_printf("#.8 %#.8o<--\n", 0);
	printf("#.8 %#.8o<--\n\n", 0);
	ft_printf("-+.8o %-+.8o<--\n", 0);
	printf("-+.8o %-+.8o<--\n\n", 0);
	ft_printf("-.8o %-.8o<--\n", 0);
	printf("-.8o %-.8o<--\n\n", 0);
	ft_printf(".8 %.8o<--\n", 0);
	printf(".8 %.8o<--\n\n", 0);
	ft_putendl("OK");
	ft_printf("%#-+.o<--\n", 0);
	printf("%#-+.o<--\n\n", 0);
	ft_printf("%#- .o<--\n", 0);
	printf("%#- .o<--\n\n", 0);
	ft_printf("%#-.o<--\n", 0);
	printf("%#-.o<--\n\n", 0);
	ft_printf("%#.o<--\n", 0);
	printf("%#.o<--\n\n", 0);
	ft_printf("%.o<--\n", 0);
	printf("%.o<--\n\n", 0);
	ft_putendl("OK");
	ft_printf("%#-+10.0o<--\n", 0);
	printf("%#-+10.0o<--\n\n", 0);
	ft_printf("%#-+10.0o<--\n", 0);
	printf("%#-+10.0o<--\n\n", 0);
	ft_printf("%#10.0o<--\n", 0);
	printf("%#10.0o<--\n\n", 0);

	ft_printf("%010.0o<--\n", 10);
	printf("%010.0o<--\n\n", 10);
	ft_printf("%10.0o<--\n", 10);
	printf("%10.0o<--\n\n", 10);

	printf("-->000<--\n\n");

	ft_printf("-->Width_Precision<--\n\n");
	ft_printf("%010.10o<--\n", 42);
	printf("%010.10o<--\n\n", 42);

	ft_printf("%010.10o<--\n", 4242);
	printf("%010.10o<--\n\n", 4242);

	ft_printf("%010.15o<--\n", 0);
	printf("%010.15o<--\n\n", 0);

	ft_printf("%010.8o<--\n", 42);
	printf("%010.8o<--\n\n", 42);

	ft_printf("%010.8o<--\n", 20);
	printf("%010.8o<--\n\n", 20);

	ft_printf("%010.4o<--\n", 20);
	printf("%010.4o<--\n\n", 20);

	ft_printf("%010.6o<--\n", 120);
	printf("%010.6o<--\n\n", 120);

	ft_printf("%010.8o<--\n", 1200);
	printf("%010.8o<--\n\n", 1200);

	ft_printf("%010.1o<--\n", 120);
	printf("%010.1o<--\n\n", 120);

	ft_printf("%010.6o<--\n", 242);
	printf("%010.6o<--\n\n", 242);

	ft_printf("%010.6o<--\n", 4242);
	printf("%010.6o<--\n\n", 4242);

	ft_printf("%010.2o<--\n", 4242);
	printf("%010.2o<--\n\n", 4242);

	ft_printf("%010.0o<--\n", 4242);
	printf("%010.0o<--\n\n", 4242);

	ft_printf("%010.5o<--\n", 4242);
	printf("%010.5o<--\n\n", 4242);

	ft_printf("%010.2o<--\n", 20);
	printf("%010.2o<--\n\n", 20);

	ft_putendl("ok");
	ft_printf("%010.2o<--\n", 0);
	printf("%010.2o<--\n\n", 0);

	ft_printf("%010.4o<--\n", 0);
	printf("%010.4o<--\n\n", 0);

	ft_printf("%010.2o<--\n", 0);
	printf("%010.2o<--\n\n", 0);
	ft_printf("%0.2o<--\n", 0);
	printf("%0.2o<--\n\n", 0);
	ft_printf("%010o<--\n", 0);
	printf("%010o<--\n\n", 0);
	ft_printf("%010.5o<--\n", ULLONG_MAX);
	printf("%010.5o<--\n\n", ULLONG_MAX);
	ft_printf("%010.5o<--\n", LLONG_MAX);
	printf("%010.5o<--\n\n", LLONG_MAX);

	ft_printf("%010.12o<--\n", 20);
	printf("%010.12o<--\n\n", 20);
	ft_printf("%010.12o<--\n", 120);
	printf("%010.12o<--\n\n", 120);
	ft_printf("%010.12o<--\n", 20);
	printf("%010.12o<--\n\n", 20);

	ft_printf("%010.12o<--\n", 0);
	printf("%010.12o<--\n\n", 0);
/*
	ft_printf("-->Width<--\n\n");
	ft_printf("%010o<--\n", 42);
	printf("%010o<--\n\n", 42);
	ft_printf("%010o<--\n", 142);
	printf("%010o<--\n\n", 142);
	ft_printf("%010o<--\n", 14200);
	printf("%010o<--\n\n", 14200);
	ft_printf("%010o<--\n", 42);
	printf("%010o<--\n\n", 42);
	ft_printf("%010o<--\n", 142);
	printf("%010o<--\n\n", 142);
	ft_printf("%010o<--\n", 20);
	printf("%010o<--\n\n", 20);
	ft_printf("%010o<--\n", 0);
	printf("%010o<--\n\n", 0);
	ft_printf("%01o<--\n", 42);
	printf("%01o<--\n\n", 42);

	ft_printf("-->Precision<--\n\n");
	ft_printf("%0.8o<--\n", 42);
	printf("%0.8o<--\n\n", 42);

	ft_printf("%0.8o<--\n", 142);
	printf("%0.8o<--\n\n", 142);

	ft_printf("%0.8o<--\n", 42);
	printf("%0.8o<--\n\n", 42);

	ft_printf("%0.2o<--\n", 142);
	printf("%0.2o<--\n\n", 142);

	ft_printf("%0.8o<--\n", 0);
	printf("%0.8o<--\n\n", 0);

	ft_printf("%025p<--\n", &ptr);
	printf("%025p<--\n\n", &ptr);
*/
/*	unsigned long long int ptr1 = ULLONG_MAX;
	ft_printf("%10.0p<--\n", &ptr1);
	printf("%10.0p<--\n\n", &ptr1);
	long long int ptr2 = LLONG_MIN;
	ft_printf("%25.0p<--\n", &ptr2);
	printf("%25.0p<--\n\n", &ptr2);

	ft_printf("%25.25p<--\n", &ptr2);
	printf("%25.25p<--\n\n", &ptr2);
	int ptr3 = 42;
	ft_printf("%25.0p<--\n", &ptr3);
	printf("%25.0p<--\n\n", &ptr3);
	ptr3 = 123456789;
	ft_printf("%25.0p<--\n", &ptr3);
	printf("%25.0p<--\n\n", &ptr3);
	ft_printf("%-25.0p<--\n", &ptr3);
	printf("%-25.0p<--\n\n", &ptr3);

			ft_putendl("x.x");
			ft_printf("%10.10p<--\n", 20);
			//printf("%10.10p<--\n\n", &20);
			ft_printf("%2.10p<--\n", -142);
			printf("%2.10p<--\n\n", -142);
			ft_printf("%2.10p<--\n", 142);
			printf("%2.10p<--\n\n", 142);
			ft_printf("%1.10p<--\n", 142);
			printf("%1.10p<--\n\n", 142);
			ft_printf("%10.5p<--\n", 20);
			printf("%10.5p<--\n\n", 20);
			ft_printf("%10.2p<--\n", 20);
			printf("%10.2p<--\n\n", 20);
			ft_printf("%10.1p<--\n", 20); //
			printf("%10.1p<--\n\n", 20); //
			ft_printf("%10.1p<--\n", 142); //
			printf("%10.1p<--\n\n", 142); //
			ft_printf("%10.1p<--\n", 1420); //
			printf("%10.1p<--\n\n", 1420); //

			ft_printf("%10.15p<--\n", 142);
			printf("%10.15p<--\n\n", 142);

			ft_printf("%10.0p<--\n", 0);
			printf("%10.0p<--\n\n", 0);

			ft_printf("%10.0p<--\n", 1); //
			printf("%10.0p<--\n\n", 1);

			ft_printf("%10.1p<--\n", 0);
			printf("%10.1p<--\n\n", 0);

			ft_putendl("x");
			ft_printf("%10p<--\n", -20);
			printf("%10p<--\n\n", -20);
			ft_printf("%2p<--\n", -142);
			printf("%2p<--\n\n", -142);
			ft_printf("%2p<--\n", 142);
			printf("%2p<--\n\n", 142);
			ft_printf("%1p<--\n", 142);
			printf("%1p<--\n\n", 142);
			ft_printf("%10p<--\n", 20);
			printf("%10p<--\n\n", 20);
			ft_printf("%10p<--\n", 20);
			printf("%10p<--\n\n", 20);

			ft_printf("%15p<--\n", 142);
			printf("%15p<--\n\n", 142);
			ft_printf("%1p<--\n", 0);
			printf("%1p<--\n\n", 0);

			ft_printf("%30p<--\n", 1);
			printf("%30p<--\n\n", 1);
			ft_printf("%50p<--\n", 0);
			printf("%50p<--\n\n", 0);

			ft_printf("%.25p<--\n", -20);
			printf("%.25p<--\n\n", -20);
			ft_printf("%.25p<--\n", 20);
			printf("%.25p<--\n\n", 20);
			ft_printf("%.25p<--\n", 0);
			printf("%.25p<--\n\n", 0);

			ft_printf("%10p<--\n", -20);
			printf("%10p<--\n\n", -20);
			ft_printf("%10p<--\n", -142);
			printf("%10p<--\n\n", -142);
			ft_printf("%10p<--\n", 20);
			printf("%10p<--\n\n", 20);
			ft_printf("%10p<--\n", 142);
			printf("%10p<--\n\n", 142);
			ft_printf("%10p<--\n", 0);
			printf("%10p<--\n\n", 0);
	        ft_printf("%10p<--\n", -1);
	        printf("%10p<--\n\n", -1);


				printf("-->###<--\n\n");

				ft_printf("-->Width_Precision<--\n\n");
				ft_printf("%#10.10p<--\n", 42);
				printf("%#10.10p<--\n\n", 42);

				ft_printf("%#10.10p<--\n", 4242);
				printf("%#10.10p<--\n\n", 4242);

				ft_printf("%#10.15p<--\n", 0);
				printf("%#10.15p<--\n\n", 0);

				ft_printf("%#10.8p<--\n", 42);
				printf("%#10.8p<--\n\n", 42);

				ft_printf("%#10.8p<--\n", 20);
				printf("%#10.8p<--\n\n", 20);

				ft_printf("%#10.4p<--\n", 20);
				printf("%#10.4p<--\n\n", 20);

				ft_printf("%#10.6p<--\n", 120);
				printf("%#10.6p<--\n\n", 120);

				ft_printf("%#10.8p<--\n", 1200);
				printf("%#10.8p<--\n\n", 1200);

				ft_printf("%#10.1p<--\n", 120);
				printf("%#10.1p<--\n\n", 120);

				ft_printf("%#10.6p<--\n", 242);
				printf("%#10.6p<--\n\n", 242);

				ft_printf("%#10.6p<--\n", 4242);
				printf("%#10.6p<--\n\n", 4242);

				ft_printf("%#10.2p<--\n", 4242);
				printf("%#10.2p<--\n\n", 4242);

				ft_printf("%#10.0p<--\n", 4242);
				printf("%#10.0p<--\n\n", 4242);

				ft_printf("%#10.5p<--\n", 4242);
				printf("%#10.5p<--\n\n", 4242);

				ft_printf("%#10.2p<--\n", 20);
				printf("%#10.2p<--\n\n", 20);

				ft_putendl("ok");
				ft_printf("%#10.2p<--\n", 0);
				printf("%#10.2p<--\n\n", 0);

				ft_printf("%#10.4p<--\n", 0);
				printf("%#10.4p<--\n\n", 0);

				ft_printf("%10.2p<--\n", 0);
				printf("%10.2p<--\n\n", 0);
				ft_printf("%.2p<--\n", 0);
				printf("%.2p<--\n\n", 0);
				ft_printf("%10p<--\n", 0);
				printf("%10p<--\n\n", 0);
				ft_printf("%#10.5p<--\n", ULLONG_MAX);
				printf("%#10.5p<--\n\n", ULLONG_MAX);
				ft_printf("%10.5p<--\n", LLONG_MAX);
				printf("%10.5p<--\n\n", LLONG_MAX);

				ft_printf("%#10.12p<--\n", 20);
				printf("%#10.12p<--\n\n", 20);
				ft_printf("%#10.12p<--\n", 120);
				printf("%#10.12p<--\n\n", 120);
				ft_printf("%#10.12p<--\n", 20);
				printf("%#10.12p<--\n\n", 20);

				ft_printf("%#10.12p<--\n", 0);
				printf("%#10.12p<--\n\n", 0);

				ft_printf("-->Width<--\n\n");
				ft_printf("%#10p<--\n", 42);
				printf("%#10p<--\n\n", 42);
				ft_printf("%#10p<--\n", 142);
				printf("%#10p<--\n\n", 142);
				ft_printf("%#10p<--\n", 14200);
				printf("%#10p<--\n\n", 14200);
				ft_printf("%#10p<--\n", 42);
				printf("%#10p<--\n\n", 42);
				ft_printf("%#10p<--\n", 142);
				printf("%#10p<--\n\n", 142);
				ft_printf("%#10p<--\n", 20);
				printf("%#10p<--\n\n", 20);
				ft_printf("%#10p<--\n", 0);
				printf("%#10p<--\n\n", 0);
				ft_printf("%#1p<--\n", 42);
				printf("%#1p<--\n\n", 42);

				ft_printf("-->Precision<--\n\n");
				ft_printf("%#.8p<--\n", 42);
				printf("%#.8p<--\n\n", 42);

				ft_printf("%#.8p<--\n", 142);
				printf("%#.8p<--\n\n", 142);

				ft_printf("%#.8p<--\n", 42);
				printf("%#.8p<--\n\n", 42);

				ft_printf("%#.2p<--\n", 142);
				printf("%#.2p<--\n\n", 142);

				ft_printf("%#.8p<--\n", 0);
				printf("%#.8p<--\n\n", 0);

				printf("-->---<--\n\n");

				ft_printf("-->Width_Precision<--\n\n");
				ft_printf("%-10.10p<--\n", 42);
				printf("%-10.10p<--\n\n", 42);
				ft_printf("%-10.8p<--\n", 42);
				printf("%-10.8p<--\n\n", 42);
				ft_printf("%-10.15p<--\n", 0);
				printf("%-10.15p<--\n\n", 0);
				ft_printf("%-10.8p<--\n", 20);
				printf("%-10.8p<--\n\n", 20);
				ft_printf("%-10.8p<--\n", 20);
				printf("%-10.8p<--\n\n", 20);
				ft_printf("%-10.6p<--\n", 120);
				printf("%-10.6p<--\n\n", 120);
				ft_printf("%-10.2p<--\n", 20);
				printf("%-10.2p<--\n\n", 20);

				ft_printf("%-10.2p<--\n", 0);
				printf("%-10.2p<--\n\n", 0);

				ft_printf("%-10.4p<--\n", 0);
				printf("%-10.4p<--\n\n", 0);

		//			ft_printf("%10.2p<--\n", 0);
		//			printf("%10.2p<--\n\n", 0);
				ft_printf("%-10.5p<--\n", ULLONG_MAX);
				printf("%-10.5p<--\n\n", ULLONG_MAX);
				ft_printf("%-10.2p<--\n", 100000);
				printf("%-10.2p<--\n\n", 100000);
				ft_printf("%-10.1p<--\n", 100);
				printf("%-10.1p<--\n\n", 100);
				ft_printf("%-10.0p<--\n", 10);
				printf("%-10.0p<--\n\n", 10);
		//			ft_printf("%10.5p<--\n", LLONG_MAX);
		//			printf("%10.5p<--\n\n", LLONG_MAX);

				ft_printf("%-10.12p<--\n", 20);
				printf("%-10.12p<--\n\n", 20);
				ft_printf("%-10.12p<--\n", 120);
				printf("%-10.12p<--\n\n", 120);
				ft_printf("%-10.12p<--\n", 20);
				printf("%-10.12p<--\n\n", 20);

				ft_printf("%-10.12p<--\n", 0);
				printf("%-10.12p<--\n\n", 0);

				ft_printf("-->Width<--\n\n");
				ft_printf("%-10p<--\n", 42);
				printf("%-10p<--\n\n", 42);
				ft_printf("%-10p<--\n", 142);
				printf("%-10p<--\n\n", 142);
				ft_printf("%-10p<--\n", 14200);
				printf("%-10p<--\n\n", 14200);
				ft_printf("%-10p<--\n", 42);
				printf("%-10p<--\n\n", 42);
				ft_printf("%-10p<--\n", 142);
				printf("%-10p<--\n\n", 142);
				ft_printf("%-10p<--\n", 20);
				printf("%-10p<--\n\n", 20);
				ft_printf("%-10p<--\n", 0);
				printf("%-10p<--\n\n", 0);
				ft_printf("%-1p<--\n", 42);
				printf("%-1p<--\n\n", 42);

				ft_printf("-->Precision<--\n\n");
				ft_printf("%-.8p<--\n", 42);
				printf("%-.8p<--\n\n", 42);
				ft_printf("%-.8p<--\n", 142);
				printf("%-.8p<--\n\n", 142);
				ft_printf("%-.8p<--\n", 42);
				printf("%-.8p<--\n\n", 42);
				ft_printf("%-.2p<--\n", 142);
				printf("%-.2p<--\n\n", 142);
				ft_printf("%-.8p<--\n", 0);
				printf("%-.8p<--\n\n", 0);

				printf("-->   <--\n\n");

				ft_printf("-->Width_Precision<--\n\n");
				ft_printf("% 10.10p<--\n", 42);
				printf("% 10.10p<--\n\n", 42);
				ft_printf("% 10.8p<--\n", 42);
				printf("% 10.8p<--\n\n", 42);
				ft_printf("% 10.15p<--\n", 0);
				printf("% 10.15p<--\n\n", 0);
				ft_printf("% 10.8p<--\n", 20);
				printf("% 10.8p<--\n\n", 20);
				ft_printf("% 10.8p<--\n", 20);
				printf("% 10.8p<--\n\n", 20);
				ft_printf("% 10.6p<--\n", 120);
				printf("% 10.6p<--\n\n", 120);
				ft_printf("% 10.2p<--\n", 20);
				printf("% 10.2p<--\n\n", 20);

				ft_printf("% 10.2p<--\n", 0);
				printf("% 10.2p<--\n\n", 0);

				ft_printf("% 10.4p<--\n", 0);
				printf("% 10.4p<--\n\n", 0);

				//			ft_printf("%10.2p<--\n", 0);
				//			printf("%10.2p<--\n\n", 0);
				ft_printf("% 10.5p<--\n", ULLONG_MAX);
				printf("% 10.5p<--\n\n", ULLONG_MAX);
				ft_printf("% 10.2p<--\n", 100000);
				printf("% 10.2p<--\n\n", 100000);
				ft_printf("% 10.1p<--\n", 100);
				printf("% 10.1p<--\n\n", 100);
				ft_printf("% 10.0p<--\n", 10);
				printf("% 10.0p<--\n\n", 10);
				//			ft_printf("%10.5p<--\n", LLONG_MAX);
				//			printf("%10.5p<--\n\n", LLONG_MAX);

				ft_printf("% 10.12p<--\n", 20);
				printf("% 10.12p<--\n\n", 20);
				ft_printf("% 10.12p<--\n", 120);
				printf("% 10.12p<--\n\n", 120);
				ft_printf("% 10.12p<--\n", 20);
				printf("% 10.12p<--\n\n", 20);

				ft_printf("% 10.12p<--\n", 0);
				printf("% 10.12p<--\n\n", 0);

				ft_printf("-->Width<--\n\n");
				ft_printf("% 10p<--\n", 42);
				printf("% 10p<--\n\n", 42);
				ft_printf("% 10p<--\n", 142);
				printf("% 10p<--\n\n", 142);
				ft_printf("% 10p<--\n", 14200);
				printf("% 10p<--\n\n", 14200);
				ft_printf("% 10p<--\n", 42);
				printf("% 10p<--\n\n", 42);
				ft_printf("% 10p<--\n", 142);
				printf("% 10p<--\n\n", 142);
				ft_printf("% 10p<--\n", 20);
				printf("% 10p<--\n\n", 20);
				ft_printf("% 10p<--\n", 0);
				printf("% 10p<--\n\n", 0);
				ft_printf("% 1p<--\n", 42);
				printf("% 1p<--\n\n", 42);

				ft_printf("-->Precision<--\n\n");
				ft_printf("% .8p<--\n", 42);
				printf("% .8p<--\n\n", 42);
				ft_printf("% .8p<--\n", 142);
				printf("% .8p<--\n\n", 142);
				ft_printf("% .8p<--\n", 42);
				printf("% .8p<--\n\n", 42);
				ft_printf("% .2p<--\n", 142);
				printf("% .2p<--\n\n", 142);
				ft_printf("% .8p<--\n", 0);
				printf("% .8p<--\n\n", 0);

		ft_printf("-->##--x--##<--\n\n");

		ft_printf("-->Width_Precision<--\n\n");
		ft_printf("%#-10.12p<--\n", 42);
		printf("%#-10.12p<--\n\n", 42);
		ft_printf("%#-10.10p<--\n", 42);
		printf("%#-10.10p<--\n\n", 42);
		ft_printf("%#-10.8p<--\n", 42);
		printf("%#-10.8p<--\n\n", 42);
		ft_printf("%#-10.15p<--\n", 0);
		printf("%#-10.15p<--\n\n", 0);

		ft_printf("%#-10.8p<--\n", 20);
		printf("%#-10.8p<--\n\n", 20);
		ft_printf("%#-10.8p<--\n", 20);
		printf("%#-10.8p<--\n\n", 20);
		ft_printf("%#-10.6p<--\n", 120);
		printf("%#-10.6p<--\n\n", 120);
		ft_printf("%#-10.2p<--\n", 20);
		printf("%#-10.2p<--\n\n", 20);

		ft_printf("%#-10.1p<--\n", 120);
		printf("%#-10.1p<--\n\n", 120);
		ft_printf("%#-10.1p<--\n", 20);
		printf("%#-10.1p<--\n\n", 20);

		ft_printf("%#10.12p<--\n", 20);
		printf("%#10.12p<--\n\n", 20);
		ft_printf("%#10.12p<--\n", 120);
		printf("%#10.12p<--\n\n", 120);
		ft_printf("%#10.12p<--\n", 20);
		printf("%#10.12p<--\n\n", 20);

		ft_printf("%#10.12p<--\n", 0);
		printf("%#10.12p<--\n\n", 0);

		ft_printf("%#-10.2p<--\n", 0);
		printf("%#-10.2p<--\n\n", 0);
		ft_printf("%#-10.0p<--\n", 0);
		printf("%#-10.0p<--\n\n", 0);
		ft_printf("%#-10.1p<--\n", 0);
		printf("%#-10.1p<--\n\n", 0);
	//	ft_printf("%-10.2p<--\n", 0);
	//	printf("%-10.2p<--\n\n", 0);
	//	ft_printf("%#10.2p<--\n", 0);
	//	printf("%#10.2p<--\n\n", 0);

		ft_printf("%#-10.12p<--\n", 20);
		printf("%#-10.12p<--\n\n", 20);
		ft_printf("%#-10.12p<--\n", 120);
		printf("%#-10.12p<--\n\n", 120);
		ft_printf("%#-10.13p<--\n", 1200);
		printf("%#-10.13p<--\n\n", 1200);
		ft_printf("%#-10.12p<--\n", 1200);
		printf("%#-10.12p<--\n\n", 1200);
		ft_printf("%#-10.12p<--\n", 20);
		printf("%#-10.12p<--\n\n", 20);
		ft_printf("%#-10.12p<--\n", 0);
		printf("%#-10.12p<--\n\n", 0);

		ft_printf("%10.1p<--\n", 0);
		printf("%10.1p<--\n\n", 0);

		ft_printf("%10.2p<--\n", 16);
		printf("%10.2p<--\n\n", 16);

		ft_printf("%10.p<--\n", 0);
		printf("%10.p<--\n\n", 0);

		ft_printf("-->Precision<--\n\n");
		ft_printf("%#-.8p<--\n", 42);
		printf("%#-.8p<--\n\n", 42);
		ft_printf("%#-.8p<--\n", 142);
		printf("%#-.8p<--\n\n", 142);
		ft_printf("%#-.8p<--\n", 42);
		printf("%#-.8p<--\n\n", 42);
		ft_printf("%#-.2p<--\n", 142);
		printf("%#-.2p<--\n\n", 142);
		ft_printf("%#-.8p<--\n", 0);
		printf("%#-.8p<--\n\n", 0);

		ft_printf("-->Width<--\n\n");
		ft_printf("%#-10p<--\n", 42);
		printf("%#-10p<--\n\n", 42);
		ft_printf("%#-10p<--\n", 142);
		printf("%#-10p<--\n\n", 142);
		ft_printf("%#-10p<--\n", 42);
		printf("%#-10p<--\n\n", 42);
		ft_printf("%#-10p<--\n", 142);
		printf("%#-10p<--\n\n", 142);
		ft_printf("%#-10p<--\n", 20);
		printf("%#-10p<--\n\n", 20);
		ft_printf("%#-10p<--\n", 0);
		printf("%#-10p<--\n\n", 0);
		ft_printf("%#-1p<--\n", 42);
		printf("%#-1p<--\n\n", 42);
		ft_printf("%#-1p<--\n", 424242);
		printf("%#-1p<--\n\n", 424242);
		ft_printf("%#-25p<--\n", 424242);
		printf("%#-25p<--\n\n", 424242);
		ft_printf("%#-7p<--\n", 424242);
		printf("%#-7p<--\n\n", 424242);
		ft_printf("%#-8p<--\n", 424242);
		printf("%#-8p<--\n\n", 424242);
		ft_printf("%#-p<--\n", 424242);
		printf("%#-p<--\n\n", 424242);
		ft_printf("-->Width<--\n\n");
		ft_printf("%-10p<--\n", 42);
		printf("%-10p<--\n\n", 42);
		ft_printf("%-10p<--\n", 142);
		printf("%-10p<--\n\n", 142);
		ft_printf("%-10p<--\n", 14200);
		printf("%-10p<--\n\n", 14200);
		ft_printf("%-10p<--\n", 42);
		printf("%-10p<--\n\n", 42);
		ft_printf("%-10p<--\n", 142);
		printf("%-10p<--\n\n", 142);
		ft_printf("%-10p<--\n", 20);
		printf("%-10p<--\n\n", 20);
		ft_printf("%-10p<--\n", 0);
		printf("%-10p<--\n\n", 0);
		ft_printf("%-1p<--\n", 42);
		printf("%-1p<--\n\n", 42);

		ft_printf("-->##--  x  --##<--\n\n");

		ft_printf("-->Width_Precision<--\n\n");
		ft_printf("%#- 10.12p<--\n", 42);
		printf("%#- 10.12p<--\n\n", 42);
		ft_printf("%#- 10.10p<--\n", 42);
		printf("%#- 10.10p<--\n\n", 42);
		ft_printf("%#- 10.8p<--\n", 42);
		printf("%#- 10.8p<--\n\n", 42);
		ft_printf("%#- 10.15p<--\n", 0);
		printf("%#- 10.15p<--\n\n", 0);

		ft_printf("%#- 10.8p<--\n", 20);
		printf("%#- 10.8p<--\n\n", 20);
		ft_printf("%#- 10.8p<--\n", 20);
		printf("%#- 10.8p<--\n\n", 20);
		ft_printf("%#- 10.6p<--\n", 120);
		printf("%#- 10.6p<--\n\n", 120);
		ft_printf("%#- 10.2p<--\n", 20);
		printf("%#- 10.2p<--\n\n", 20);

		ft_printf("%#- 10.1p<--\n", 120);
		printf("%#- 10.1p<--\n\n", 120);
		ft_printf("%#- 10.1p<--\n", 20);
		printf("%#- 10.1p<--\n\n", 20);

		ft_printf("%#- 10.2p<--\n", 0);
		printf("%#- 10.2p<--\n\n", 0);
		ft_printf("%#-10.2p<--\n", 0);
		printf("%#-10.2p<--\n\n", 0);
		ft_printf("%- 10.2p<--\n", 0);
		printf("%- 10.2p<--\n\n", 0);
		ft_printf("%-010.2p<--\n", 0);
		printf("%-010.2p<--\n\n", 0);
		ft_printf("%#10.2p<--\n", 0);
		printf("%#10.2p<--\n\n", 0);

		ft_printf("%#- 10.12p<--\n", 20);
		printf("%#- 10.12p<--\n\n", 20);
		ft_printf("%#- 10.12p<--\n", 120);
		printf("%#- 10.12p<--\n\n", 120);
		ft_printf("%#- 10.12p<--\n", 20);
		printf("%#- 10.12p<--\n\n", 20);
		ft_printf("%#- 10.12p<--\n", 0);
		printf("%#- 10.12p<--\n\n", 0);

		ft_printf("-->Width<--\n\n");
		ft_printf("%#- 10p<--\n", 42);
		printf("%#- 10p<--\n\n", 42);
		ft_printf("%#- 10p<--\n", 142);
		printf("%#- 10p<--\n\n", 142);
		ft_printf("%#- 10p<--\n", 42);
		printf("%#- 10p<--\n\n", 42);
		ft_printf("%#- 10p<--\n", 142);
		printf("%#- 10p<--\n\n", 142);
		ft_printf("%#- 10p<--\n", 20);
		printf("%#- 10p<--\n\n", 20);
		ft_printf("%#- 10p<--\n", 0);
		printf("%#- 10p<--\n\n", 0);
		ft_printf("%#- 1p<--\n", 42);
		printf("%#- 1p<--\n\n", 42);

		ft_printf("-->Precision<--\n\n");
		ft_printf("%#- .8p<--\n", 42);
		printf("%#- .8p<--\n\n", 42);
		ft_printf("%#- .8p<--\n", 142);
		printf("%#- .8p<--\n\n", 142);
		ft_printf("%#- .8p<--\n", 42);
		printf("%#- .8p<--\n\n", 42);
		ft_printf("%#- .2p<--\n", 142);
		printf("%#- .2p<--\n\n", 142);
		ft_printf("%#- .1p<--\n", 42);
		printf("%#- .1p<--\n\n", 42);
		ft_printf("%#- .p<--\n", 42);
		printf("%#- .p<--\n\n", 42);
		ft_printf("%.p<--\n", 42);
		printf("%.p<--\n\n", 42);
		ft_printf("%#.p<--\n", 42);
		printf("%#.p<--\n\n", 42);
		ft_printf("%#- .0p<--\n", 42);
		printf("%#- .0p<--\n\n", 42);
		ft_printf("%#- .8p<--\n", 0);
		printf("%#- .8p<--\n\n", 0);

		ft_printf("-->##++x++##<--\n\n");

		ft_printf("-->Width_Precision<--\n\n");
		ft_printf("%#-+10.12p<--\n", 42);
		printf("%#-+10.12p<--\n\n", 42);
		ft_printf("%#-+10.10p<--\n", 42);
		printf("%#-+10.10p<--\n\n", 42);
		ft_printf("%#-+10.8p<--\n", 42);
		printf("%#-+10.8p<--\n\n", 42);
		ft_printf("%#-+10.15p<--\n", 0);
		printf("%#-+10.15p<--\n\n", 0);

		ft_printf("%#-+10.8p<--\n", 20);
		printf("%#-+10.8p<--\n\n", 20);
		ft_printf("%#-+10.8p<--\n", 20);
		printf("%#-+10.8p<--\n\n", 20);
		ft_printf("%#-+10.6p<--\n", 120);
		printf("%#-+10.6p<--\n\n", 120);
		ft_printf("%#-+10.2p<--\n", 20);
		printf("%#-+10.2p<--\n\n", 20);

		ft_printf("%#-+10.1p<--\n", 120);
		printf("%#-+10.1p<--\n\n", 120);
		ft_printf("%#-+10.1p<--\n", 20);
		printf("%#-+10.1p<--\n\n", 20);

		ft_printf("%#-+10.2p<--\n", 0);
		printf("%#-+10.2p<--\n\n", 0);
		ft_printf("%#-+10.2p<--\n", 0);
		printf("%#-+10.2p<--\n\n", 0);
		ft_printf("%-+10.2p<--\n", 0);
		printf("%-+10.2p<--\n\n", 0);
		ft_printf("%-010.2p<--\n", 0);
		printf("%-010.2p<--\n\n", 0);
		ft_printf("%#10.2p<--\n", 0);
		printf("%#10.2p<--\n\n", 0);

		ft_printf("%#-+10.12p<--\n", 20);
		printf("%#-+10.12p<--\n\n", 20);
		ft_printf("%#-+10.12p<--\n", 120);
		printf("%#-+10.12p<--\n\n", 120);
		ft_printf("%#-+10.12p<--\n", 20);
		printf("%#-+10.12p<--\n\n", 20);
		ft_printf("%#-+10.12p<--\n", 0);
		printf("%#-+10.12p<--\n\n", 0);

		ft_printf("-->Width<--\n\n");
		ft_printf("%#-+10p<--\n", 42);
		printf("%#-+10p<--\n\n", 42);
		ft_printf("%#-+10p<--\n", 142);
		printf("%#-+10p<--\n\n", 142);
		ft_printf("%#-+10p<--\n", 42);
		printf("%#-+10p<--\n\n", 42);
		ft_printf("%#-+2p<--\n", 142);
		printf("%#-+1p<--\n\n", 142);
		ft_printf("%#-+2p<--\n", 20);
		printf("%#-+2p<--\n\n", 20);
		ft_printf("%#-+1p<--\n", 0);
		printf("%#-+1p<--\n\n", 0);
		ft_printf("%#-+1p<--\n", 42);
		printf("%#-+1p<--\n\n", 42);

		ft_printf("-->Precision<--\n\n");
		ft_printf("%#-+.8p<--\n", 42);
		printf("%#-+.8p<--\n\n", 42);
		ft_printf("%#-+.8p<--\n", 142);
		printf("%#-+.8p<--\n\n", 142);
		ft_printf("%#-+.8p<--\n", 42);
		printf("%#-+.8p<--\n\n", 42);
		ft_printf("%#-+.2p<--\n", 142);
		printf("%#-+.2p<--\n\n", 142);
		ft_printf("%#-+.1p<--\n", 42);
		printf("%#-+.1p<--\n\n", 42);
		ft_printf("%#-+.p<--\n", 42);
		printf("%#-+.p<--\n\n", 42);
		ft_printf("%+.p<--\n", 42);
		printf("%+.p<--\n\n", 42);
		ft_printf("%#.p<--\n", 42);
		printf("%#.p<--\n\n", 42);
		ft_printf("%#-+.0p<--\n", 42);
		printf("%#-+.0p<--\n\n", 42);
		ft_printf("%#-+.8p<--\n", 0);
		printf("%#-+.8p<--\n\n", 0);

		ft_printf("%-.0p<--\n", 0);
		printf("%-.0p<--\n\n", 0);
		ft_printf("%-.0p<--\n", 0);
		printf("%-.0p<--\n\n", 0);
		ft_printf("%-.1p<--\n", 0);
		printf("%-.1p<--\n\n", 0);
		ft_printf("%10.0p<--\n", 0);
		printf("%10.0p<--\n\n", 0);
		ft_printf("%1.0p<--\n", 0);
		printf("%1.0p<--\n\n", 0);

		ft_printf("%#10.5llp<--\n", ULLONG_MAX);
		printf("%#10.5llp<--\n\n", ULLONG_MAX);

		ft_printf("%#10.5llp<--\n", LLONG_MIN);
		printf("%#10.5llp<--\n\n", LLONG_MIN);

		ft_printf("%#10.5lp<--\n", LONG_MAX);
		printf("%#10.5lp<--\n\n", LONG_MAX);

		ft_printf("%#10.5p<--\n", INT_MAX);
		printf("%#10.5p<--\n\n", INT_MAX);

		ft_putendl("Ok");
		ft_printf("%#10.5p<--\n", 42);
		printf("%#10.5p<--\n\n", 42);

		ft_printf("#10.0x %#10.0p<--\n", 42);
		printf("#10.0x %#10.0p<--\n\n", 42);

		ft_printf("#10.1x %#10.1p<--\n", 42);
		printf("#10.1x %#10.1p<--\n\n", 42);

		ft_printf("10.0x %10.0p<--\n", 42);
		printf("10.0x %10.0p<--\n\n", 42);

		ft_printf("10.1x %10.1p<--\n", 42);
		printf("10.1x %10.1p<--\n\n", 42);

		ft_printf("%#10.2p<--\n", 20);
		printf("%#10.2p<--\n\n", 20);

		ft_printf("%10.5p<--\n", LLONG_MAX);
		printf("%10.5p<--\n\n", LLONG_MAX);

		ft_printf("%llp<--\n", ULLONG_MAX);
		printf("%llp<--\n", ULLONG_MAX);

		ft_printf("%#-+.0p<--\n", 0);
		printf("%#-+.0p<--\n\n", 0);
		ft_printf("%#-+.0p<--\n", 0);
		printf("%#-+.0p<--\n\n", 0);
		ft_printf("%#.0p<--\n", 0);
		printf("%#.0p<--\n\n", 0);

		ft_putendl("OK");
		ft_printf("%#-+.1p<--\n", 0);
		printf("%#-+.1p<--\n\n", 0);
		ft_printf("%#-+.p<--\n", 0);
		printf("%#-+.p<--\n\n", 0);
		ft_printf("%#- .1p<--\n", 0);
		printf("%#- .1p<--\n\n", 0);
		ft_printf("%#-.1p<--\n", 0);
		printf("%#-.1p<--\n\n", 0);
		ft_printf("%#.1p<--\n", 0);
		printf("%#.1p<--\n\n", 0);
		ft_printf("%.1p<--\n", 0);
		printf("%.1p<--\n\n", 0);
		ft_printf("#-+.8o %#-+.8p<--\n", 0);
		printf("#-+.8o %#-+.8p<--\n\n", 0);
		ft_printf("#-.8o %#-.8p<--\n", 0);
		printf("#-.8o %#-.8p<--\n\n", 0);
		ft_printf("#.8 %#.8p<--\n", 0);
		printf("#.8 %#.8p<--\n\n", 0);
		ft_printf("-+.8o %-+.8p<--\n", 0);
		printf("-+.8o %-+.8p<--\n\n", 0);
		ft_printf("-.8o %-.8p<--\n", 0);
		printf("-.8o %-.8p<--\n\n", 0);
		ft_printf(".8 %.8p<--\n", 0);
		printf(".8 %.8p<--\n\n", 0);
		ft_putendl("/");
		ft_printf("#-+.1o %#-+.1p<--\n", 0);
		printf("#-+.1o %#-+.1p<--\n\n", 0);
		ft_printf("#-+.2o %#-+.2p<--\n", 0);
		printf("#-+.2o %#-+.2p<--\n\n", 0);
		ft_printf("#-+.1o %#-+.1p<--\n", 0);
		printf("#-+.1o %#-+.1p<--\n\n", 0);
		ft_printf("#-.8o %#-.8p<--\n", 0);
		printf("#-.8o %#-.8p<--\n\n", 0);
		ft_printf("#.8 %#.8p<--\n", 0);
		printf("#.8 %#.8p<--\n\n", 0);
		ft_printf("-+.8o %-+.8p<--\n", 0);
		printf("-+.8o %-+.8p<--\n\n", 0);
		ft_printf("-.8o %-.8p<--\n", 0);
		printf("-.8o %-.8p<--\n\n", 0);
		ft_printf(".8 %.8p<--\n", 0);
		printf(".8 %.8p<--\n\n", 0);
		ft_putendl("OK");
		ft_printf("%#-+.p<--\n", 0);
		printf("%#-+.p<--\n\n", 0);
		ft_printf("%#- .p<--\n", 0);
		printf("%#- .p<--\n\n", 0);
		ft_printf("%#-.p<--\n", 0);
		printf("%#-.p<--\n\n", 0);
		ft_printf("%#.p<--\n", 0);
		printf("%#.p<--\n\n", 0);
		ft_printf("%.p<--\n", 0);
		printf("%.p<--\n\n", 0);
		ft_putendl("OK");
		ft_printf("%#-+10.0p<--\n", 0);
		printf("%#-+10.0p<--\n\n", 0);
		ft_printf("%#-+10.0p<--\n", 0);
		printf("%#-+10.0p<--\n\n", 0);
		ft_printf("%#10.0p<--\n", 0);
		printf("%#10.0p<--\n\n", 0);
*/
/*		ft_putendl("Check Unsigned");
		ft_putendl("x.x");
		ft_printf("%10.10u<--\n", 20);
		printf("%10.10u<--\n\n", 20);
		ft_printf("%2.10u<--\n", -142);
		printf("%2.10u<--\n\n", -142);
		ft_printf("%2.10u<--\n", 142);
		printf("%2.10u<--\n\n", 142);
		ft_printf("%1.10u<--\n", 142);
		printf("%1.10u<--\n\n", 142);

		ft_printf("%10.5u<--\n", 20);
		printf("%10.5u<--\n\n", 20);

		ft_printf("%10.2u<--\n", 20);
		printf("%10.2u<--\n\n", 20);
		ft_printf("%10.1u<--\n", 20); //
		printf("%10.1u<--\n\n", 20); //
		ft_printf("%10.1u<--\n", 142); //
		printf("%10.1u<--\n\n", 142); //
		ft_printf("%10.1u<--\n", 1420); //
		printf("%10.1u<--\n\n", 1420); //
		ft_printf("%10.3u<--\n", 1420); //
		printf("%10.3u<--\n\n", 1420); //
		ft_printf("%10.0u<--\n", 1420); //
		printf("%10.0u<--\n\n", 1420); //
		ft_printf("%10.1u<--\n", 0); //
		printf("%10.1u<--\n\n", 0); //
		ft_printf("%10.u<--\n", 0); //
		printf("%10.u<--\n\n", 0); //
		ft_printf("%10.0u<--\n", 0); //
		printf("%10.0u<--\n\n", 0); //


		ft_printf("%10.15u<--\n", 142);
		printf("%10.15u<--\n\n", 142);

		ft_printf("%10.15u<--\n", -142);
		printf("%10.15u<--\n\n", -142);

		ft_printf("%10.0u<--\n", 0);
		printf("%10.0u<--\n\n", 0);

		ft_printf("%10.0u<--\n", 1); //
		printf("%10.0u<--\n\n", 1);

		ft_printf("%10.1u<--\n", 0);
		printf("%10.1u<--\n\n", 0);

		ft_putendl("x");
		ft_printf("%10u<--\n", -20);
		printf("%10u<--\n\n", -20);
		ft_printf("%2u<--\n", -142);
		printf("%2u<--\n\n", -142);
		ft_printf("%2u<--\n", 142);
		printf("%2u<--\n\n", 142);
		ft_printf("%1u<--\n", 142);
		printf("%1u<--\n\n", 142);
		ft_printf("%10u<--\n", 20);
		printf("%10u<--\n\n", 20);
		ft_printf("%10u<--\n", 20);
		printf("%10u<--\n\n", 20);

		ft_printf("%15u<--\n", 142);
		printf("%15u<--\n\n", 142);
		ft_printf("%1u<--\n", 0);
		printf("%1u<--\n\n", 0);

		ft_printf("%30u<--\n", 1);
		printf("%30u<--\n\n", 1);
		ft_printf("%50u<--\n", 0);
		printf("%50u<--\n\n", 0);
		ft_printf("%1u<--\n", 0);
		printf("%1u<--\n\n", 0);
		ft_printf("%2u<--\n", 20);
		printf("%2u<--\n\n", 20);
		ft_printf("%2u<--\n", 200);
		printf("%2u<--\n\n", 200);
		ft_printf("%4u<--\n", 200);
		printf("%4u<--\n\n", 200);

		ft_printf("%.25u<--\n", -20);
		printf("%.25u<--\n\n", -20);
		ft_printf("%.25u<--\n", 20);
		printf("%.25u<--\n\n", 20);
		ft_printf("%.25u<--\n", 0);
		printf("%.25u<--\n\n", 0);

		ft_printf("%10u<--\n", -20);
		printf("%10u<--\n\n", -20);
		ft_printf("%10u<--\n", -142);
		printf("%10u<--\n\n", -142);
		ft_printf("%10u<--\n", 20);
		printf("%10u<--\n\n", 20);
		ft_printf("%10u<--\n", 142);
		printf("%10u<--\n\n", 142);
		ft_printf("%10u<--\n", 0);
		printf("%10u<--\n\n", 0);
		ft_printf("%10u<--\n", -1);
		printf("%10u<--\n\n", -1);

		ft_printf("%10u<--\n", -150);
		printf("%10u<--\n\n", -150);

		ft_printf("%#10u<--\n", -150);
		printf("%#10u<--\n\n", -150);
		ft_printf("% 10u<--\n", -150);
		printf("% 10u<--\n\n", -150);
		ft_printf("%+10u<--\n", -150);
		printf("%+10u<--\n\n", -150);

			printf("-->###<--\n\n");

			ft_printf("-->Width_Precision<--\n\n");
			ft_printf("%#10.10u<--\n", 42);
			printf("%#10.10u<--\n\n", 42);

			ft_printf("%#10.10u<--\n", 4242);
			printf("%#10.10u<--\n\n", 4242);

			ft_printf("%#10.15u<--\n", 0);
			printf("%#10.15u<--\n\n", 0);

			ft_printf("%#10.8u<--\n", 42);
			printf("%#10.8u<--\n\n", 42);

			ft_printf("%#10.8u<--\n", 20);
			printf("%#10.8u<--\n\n", 20);

			ft_printf("%#10.4u<--\n", 20);
			printf("%#10.4u<--\n\n", 20);

			ft_printf("%#10.6u<--\n", 120);
			printf("%#10.6u<--\n\n", 120);

			ft_printf("%#10.8u<--\n", 1200);
			printf("%#10.8u<--\n\n", 1200);

			ft_printf("%#10.1u<--\n", 120);
			printf("%#10.1u<--\n\n", 120);

			ft_printf("%#10.6u<--\n", 242);
			printf("%#10.6u<--\n\n", 242);

			ft_printf("%#10.6u<--\n", 4242);
			printf("%#10.6u<--\n\n", 4242);

			ft_printf("%#10.2u<--\n", 4242);
			printf("%#10.2u<--\n\n", 4242);

			ft_printf("%#10.0u<--\n", 4242);
			printf("%#10.0u<--\n\n", 4242);

			ft_printf("%#10.5u<--\n", 4242);
			printf("%#10.5u<--\n\n", 4242);

			ft_printf("%#10.2u<--\n", 20);
			printf("%#10.2u<--\n\n", 20);

			ft_putendl("ok");
			ft_printf("%#10.2u<--\n", 0);
			printf("%#10.2u<--\n\n", 0);

			ft_printf("%#10.4u<--\n", 0);
			printf("%#10.4u<--\n\n", 0);

			ft_printf("%10.2u<--\n", 0);
			printf("%10.2u<--\n\n", 0);
			ft_printf("%.2u<--\n", 0);
			printf("%.2u<--\n\n", 0);
			ft_printf("%10u<--\n", 0);
			printf("%10u<--\n\n", 0);
			ft_printf("%#10.5u<--\n", ULLONG_MAX);
			printf("%#10.5u<--\n\n", ULLONG_MAX);
			ft_printf("%10.5u<--\n", LLONG_MAX);
			printf("%10.5u<--\n\n", LLONG_MAX);

			ft_printf("%#10.12u<--\n", 20);
			printf("%#10.12u<--\n\n", 20);
			ft_printf("%#10.12u<--\n", 120);
			printf("%#10.12u<--\n\n", 120);
			ft_printf("%#10.12u<--\n", 20);
			printf("%#10.12u<--\n\n", 20);

			ft_printf("%#10.12u<--\n", 0);
			printf("%#10.12u<--\n\n", 0);

			ft_printf("-->Width<--\n\n");
			ft_printf("%#10u<--\n", 42);
			printf("%#10u<--\n\n", 42);
			ft_printf("%#10u<--\n", 142);
			printf("%#10u<--\n\n", 142);
			ft_printf("%#10u<--\n", 14200);
			printf("%#10u<--\n\n", 14200);
			ft_printf("%#10u<--\n", 42);
			printf("%#10u<--\n\n", 42);
			ft_printf("%#10u<--\n", 142);
			printf("%#10u<--\n\n", 142);
			ft_printf("%#10u<--\n", 20);
			printf("%#10u<--\n\n", 20);
			ft_printf("%#10u<--\n", 0);
			printf("%#10u<--\n\n", 0);
			ft_printf("%#1u<--\n", 42);
			printf("%#1u<--\n\n", 42);

			ft_printf("-->Precision<--\n\n");
			ft_printf("%#.8u<--\n", 42);
			printf("%#.8u<--\n\n", 42);

			ft_printf("%#.8u<--\n", 142);
			printf("%#.8u<--\n\n", 142);

			ft_printf("%#.8u<--\n", 42);
			printf("%#.8u<--\n\n", 42);

			ft_printf("%#.2u<--\n", 142);
			printf("%#.2u<--\n\n", 142);

			ft_printf("%#.8u<--\n", 0);
			printf("%#.8u<--\n\n", 0);

			printf("-->---<--\n\n");

			ft_printf("-->Width_Precision<--\n\n");
			ft_printf("%-10.10u<--\n", 42);
			printf("%-10.10u<--\n\n", 42);
			ft_printf("%-10.8u<--\n", 42);
			printf("%-10.8u<--\n\n", 42);
			ft_printf("%-10.15u<--\n", 0);
			printf("%-10.15u<--\n\n", 0);
			ft_printf("%-10.8u<--\n", 20);
			printf("%-10.8u<--\n\n", 20);
			ft_printf("%-10.8u<--\n", 20);
			printf("%-10.8u<--\n\n", 20);
			ft_printf("%-10.6u<--\n", 120);
			printf("%-10.6u<--\n\n", 120);
			ft_printf("%-10.6u<--\n", 1200);
			printf("%-10.6u<--\n\n", 1200);
			ft_printf("%-10.6u<--\n", 1);
			printf("%-10.6u<--\n\n", 1);
			ft_printf("%-10.2u<--\n", 20);
			printf("%-10.2u<--\n\n", 20);

			ft_printf("%-10.2u<--\n", 0);
			printf("%-10.2u<--\n\n", 0);

			ft_printf("%-10.4u<--\n", 0);
			printf("%-10.4u<--\n\n", 0);

			ft_printf("%10.2u<--\n", 0);
			printf("%10.2u<--\n\n", 0);
			ft_printf("%-10.5u<--\n", ULLONG_MAX);
			printf("%-10.5u<--\n\n", ULLONG_MAX);
			ft_printf("%-10.2u<--\n", 100000);
			printf("%-10.2u<--\n\n", 100000);
			ft_printf("%-10.1u<--\n", 100);
			printf("%-10.1u<--\n\n", 100);
			ft_printf("%-10.0u<--\n", 10);
			printf("%-10.0u<--\n\n", 10);
		//			ft_printf("%10.5u<--\n", LLONG_MAX);
		//			printf("%10.5u<--\n\n", LLONG_MAX);

			ft_printf("%-10.12u<--\n", 20);
			printf("%-10.12u<--\n\n", 20);
			ft_printf("%-10.12u<--\n", 120);
			printf("%-10.12u<--\n\n", 120);
			ft_printf("%-10.12u<--\n", 20);
			printf("%-10.12u<--\n\n", 20);

			ft_printf("%-10.12u<--\n", 0);
			printf("%-10.12u<--\n\n", 0);

			ft_printf("-->Width<--\n\n");
			ft_printf("%-10u<--\n", 42);
			printf("%-10u<--\n\n", 42);
			ft_printf("%-10u<--\n", 142);
			printf("%-10u<--\n\n", 142);
			ft_printf("%-10u<--\n", 14200);
			printf("%-10u<--\n\n", 14200);
			ft_printf("%-10u<--\n", 42);
			printf("%-10u<--\n\n", 42);
			ft_printf("%-10u<--\n", 142);
			printf("%-10u<--\n\n", 142);
			ft_printf("%-10u<--\n", 20);
			printf("%-10u<--\n\n", 20);
			ft_printf("%-10u<--\n", 0);
			printf("%-10u<--\n\n", 0);
			ft_printf("%-1u<--\n", 42);
			printf("%-1u<--\n\n", 42);
			ft_printf("%-2u<--\n", 10);
			printf("%-2u<--\n\n", 10);
			ft_printf("%-4u<--\n", 424);
			printf("%-4u<--\n\n", 424);
			ft_printf("%-1u<--\n", 0);
			printf("%-1u<--\n\n", 0);

			ft_printf("-->Precision<--\n\n");
			ft_printf("%-.8u<--\n", 42);
			printf("%-.8u<--\n\n", 42);
			ft_printf("%-.8u<--\n", 142);
			printf("%-.8u<--\n\n", 142);
			ft_printf("%-.8u<--\n", 42);
			printf("%-.8u<--\n\n", 42);
			ft_printf("%-.2u<--\n", 142);
			printf("%-.2u<--\n\n", 142);
			ft_printf("%-.8u<--\n", 0);
			printf("%-.8u<--\n\n", 0);
			ft_printf("%-.u<--\n", 0);
			printf("%-.u<--\n\n", 0);
			ft_printf("%-.0u<--\n", 0);
			printf("%-.0u<--\n\n", 0);
			ft_printf("%.u<--\n", 0);
			printf("%.u<--\n\n", 0);
			ft_printf("%-.1u<--\n", 0);
			printf("%-.1u<--\n\n", 0);
			ft_printf("%-.3u<--\n", 142);
			printf("%-.3u<--\n\n", 142);
			ft_printf("%-.4u<--\n", 142);
			printf("%-.4u<--\n\n", 142);
			printf("-->   <--\n\n");

			ft_printf("-->Width_Precision<--\n\n");
			ft_printf("% 10.10u<--\n", 42);
			printf("% 10.10u<--\n\n", 42);
			ft_printf("% 10.8u<--\n", 42);
			printf("% 10.8u<--\n\n", 42);
			ft_printf("% 10.15u<--\n", 0);
			printf("% 10.15u<--\n\n", 0);
			ft_printf("% 10.8u<--\n", 20);
			printf("% 10.8u<--\n\n", 20);
			ft_printf("% 10.8u<--\n", 20);
			printf("% 10.8u<--\n\n", 20);
			ft_printf("% 10.6u<--\n", 120);
			printf("% 10.6u<--\n\n", 120);
			ft_printf("% 10.2u<--\n", 20);
			printf("% 10.2u<--\n\n", 20);

			ft_printf("% 10.2u<--\n", 0);
			printf("% 10.2u<--\n\n", 0);

			ft_printf("% 10.4u<--\n", 0);
			printf("% 10.4u<--\n\n", 0);

			//			ft_printf("%10.2u<--\n", 0);
			//			printf("%10.2u<--\n\n", 0);
			ft_printf("% 10.5u<--\n", ULLONG_MAX);
			printf("% 10.5u<--\n\n", ULLONG_MAX);
			ft_printf("% 10.2u<--\n", 100000);
			printf("% 10.2u<--\n\n", 100000);
			ft_printf("% 10.1u<--\n", 100);
			printf("% 10.1u<--\n\n", 100);
			ft_printf("% 10.0u<--\n", 10);
			printf("% 10.0u<--\n\n", 10);
			//			ft_printf("%10.5u<--\n", LLONG_MAX);
			//			printf("%10.5u<--\n\n", LLONG_MAX);

			ft_printf("% 10.12u<--\n", 20);
			printf("% 10.12u<--\n\n", 20);
			ft_printf("% 10.12u<--\n", 120);
			printf("% 10.12u<--\n\n", 120);
			ft_printf("% 10.12u<--\n", 20);
			printf("% 10.12u<--\n\n", 20);

			ft_printf("% 10.12u<--\n", 0);
			printf("% 10.12u<--\n\n", 0);

			ft_printf("-->Width<--\n\n");
			ft_printf("% 10u<--\n", 42);
			printf("% 10u<--\n\n", 42);
			ft_printf("% 10u<--\n", 142);
			printf("% 10u<--\n\n", 142);
			ft_printf("% 10u<--\n", 14200);
			printf("% 10u<--\n\n", 14200);
			ft_printf("% 10u<--\n", 42);
			printf("% 10u<--\n\n", 42);
			ft_printf("% 10u<--\n", 142);
			printf("% 10u<--\n\n", 142);
			ft_printf("% 10u<--\n", 20);
			printf("% 10u<--\n\n", 20);
			ft_printf("% 10u<--\n", 0);
			printf("% 10u<--\n\n", 0);
			ft_printf("% 1u<--\n", 42);
			printf("% 1u<--\n\n", 42);

			ft_printf("-->Precision<--\n\n");
			ft_printf("% .8u<--\n", 42);
			printf("% .8u<--\n\n", 42);
			ft_printf("% .8u<--\n", 142);
			printf("% .8u<--\n\n", 142);
			ft_printf("% .8u<--\n", 42);
			printf("% .8u<--\n\n", 42);
			ft_printf("% .2u<--\n", 142);
			printf("% .2u<--\n\n", 142);
			ft_printf("% .8u<--\n", 0);
			printf("% .8u<--\n\n", 0);

		ft_printf("-->##--x--##<--\n\n");

		ft_printf("-->Width_Precision<--\n\n");
		ft_printf("%#-10.12u<--\n", 42);
		printf("%#-10.12u<--\n\n", 42);
		ft_printf("%#-10.10u<--\n", 42);
		printf("%#-10.10u<--\n\n", 42);
		ft_printf("%#-10.8u<--\n", 42);
		printf("%#-10.8u<--\n\n", 42);
		ft_printf("%#-10.15u<--\n", 0);
		printf("%#-10.15u<--\n\n", 0);

		ft_printf("%#-10.8u<--\n", 20);
		printf("%#-10.8u<--\n\n", 20);
		ft_printf("%#-10.8u<--\n", 20);
		printf("%#-10.8u<--\n\n", 20);
		ft_printf("%#-10.6u<--\n", 120);
		printf("%#-10.6u<--\n\n", 120);
		ft_printf("%#-10.2u<--\n", 20);
		printf("%#-10.2u<--\n\n", 20);

		ft_printf("%#-10.1u<--\n", 120);
		printf("%#-10.1u<--\n\n", 120);
		ft_printf("%#-10.1u<--\n", 20);
		printf("%#-10.1u<--\n\n", 20);

		ft_printf("%#10.12u<--\n", 20);
		printf("%#10.12u<--\n\n", 20);
		ft_printf("%#10.12u<--\n", 120);
		printf("%#10.12u<--\n\n", 120);
		ft_printf("%#10.12u<--\n", 20);
		printf("%#10.12u<--\n\n", 20);

		ft_printf("%#10.12u<--\n", 0);
		printf("%#10.12u<--\n\n", 0);

		ft_printf("%#-10.2u<--\n", 0);
		printf("%#-10.2u<--\n\n", 0);
		ft_printf("%#-10.0u<--\n", 0);
		printf("%#-10.0u<--\n\n", 0);
		ft_printf("%#-10.1u<--\n", 0);
		printf("%#-10.1u<--\n\n", 0);
		//	ft_printf("%-10.2u<--\n", 0);
		//	printf("%-10.2u<--\n\n", 0);
		//	ft_printf("%#10.2u<--\n", 0);
		//	printf("%#10.2u<--\n\n", 0);

		ft_printf("%#-10.12u<--\n", 20);
		printf("%#-10.12u<--\n\n", 20);
		ft_printf("%#-10.12u<--\n", 120);
		printf("%#-10.12u<--\n\n", 120);
		ft_printf("%#-10.13u<--\n", 1200);
		printf("%#-10.13u<--\n\n", 1200);
		ft_printf("%#-10.12u<--\n", 1200);
		printf("%#-10.12u<--\n\n", 1200);
		ft_printf("%#-10.12u<--\n", 20);
		printf("%#-10.12u<--\n\n", 20);
		ft_printf("%#-10.12u<--\n", 0);
		printf("%#-10.12u<--\n\n", 0);

		ft_printf("%10.1u<--\n", 0);
		printf("%10.1u<--\n\n", 0);

		ft_printf("%10.2u<--\n", 16);
		printf("%10.2u<--\n\n", 16);

		ft_printf("%10.u<--\n", 0);
		printf("%10.u<--\n\n", 0);

		ft_printf("-->Precision<--\n\n");
		ft_printf("%#-.8u<--\n", 42);
		printf("%#-.8u<--\n\n", 42);
		ft_printf("%#-.8u<--\n", 142);
		printf("%#-.8u<--\n\n", 142);
		ft_printf("%#-.8u<--\n", 42);
		printf("%#-.8u<--\n\n", 42);
		ft_printf("%#-.2u<--\n", 142);
		printf("%#-.2u<--\n\n", 142);
		ft_printf("%#-.8u<--\n", 0);
		printf("%#-.8u<--\n\n", 0);

		ft_printf("-->Width<--\n\n");
		ft_printf("%#-10u<--\n", 42);
		printf("%#-10u<--\n\n", 42);
		ft_printf("%#-10u<--\n", 142);
		printf("%#-10u<--\n\n", 142);
		ft_printf("%#-10u<--\n", 42);
		printf("%#-10u<--\n\n", 42);
		ft_printf("%#-10u<--\n", 142);
		printf("%#-10u<--\n\n", 142);
		ft_printf("%#-10u<--\n", 20);
		printf("%#-10u<--\n\n", 20);
		ft_printf("%#-10u<--\n", 0);
		printf("%#-10u<--\n\n", 0);
		ft_printf("%#-1u<--\n", 42);
		printf("%#-1u<--\n\n", 42);
		ft_printf("%#-1u<--\n", 424242);
		printf("%#-1u<--\n\n", 424242);
		ft_printf("%#-25u<--\n", 424242);
		printf("%#-25u<--\n\n", 424242);
		ft_printf("%#-7u<--\n", 424242);
		printf("%#-7u<--\n\n", 424242);
		ft_printf("%#-8u<--\n", 424242);
		printf("%#-8u<--\n\n", 424242);
		ft_printf("%#-u<--\n", 424242);
		printf("%#-u<--\n\n", 424242);
		ft_printf("-->Width<--\n\n");
		ft_printf("%-10u<--\n", 42);
		printf("%-10u<--\n\n", 42);
		ft_printf("%-10u<--\n", 142);
		printf("%-10u<--\n\n", 142);
		ft_printf("%-10u<--\n", 14200);
		printf("%-10u<--\n\n", 14200);
		ft_printf("%-10u<--\n", 42);
		printf("%-10u<--\n\n", 42);
		ft_printf("%-10u<--\n", 142);
		printf("%-10u<--\n\n", 142);
		ft_printf("%-10u<--\n", 20);
		printf("%-10u<--\n\n", 20);
		ft_printf("%-10u<--\n", 0);
		printf("%-10u<--\n\n", 0);
		ft_printf("%-1u<--\n", 42);
		printf("%-1u<--\n\n", 42);

		ft_printf("-->##--  x  --##<--\n\n");

		ft_printf("-->Width_Precision<--\n\n");
		ft_printf("%#- 10.12u<--\n", 42);
		printf("%#- 10.12u<--\n\n", 42);
		ft_printf("%#- 10.10u<--\n", 42);
		printf("%#- 10.10u<--\n\n", 42);
		ft_printf("%#- 10.8u<--\n", 42);
		printf("%#- 10.8u<--\n\n", 42);
		ft_printf("%#- 10.15u<--\n", 0);
		printf("%#- 10.15u<--\n\n", 0);

		ft_printf("%#- 10.8u<--\n", 20);
		printf("%#- 10.8u<--\n\n", 20);
		ft_printf("%#- 10.8u<--\n", 20);
		printf("%#- 10.8u<--\n\n", 20);
		ft_printf("%#- 10.6u<--\n", 120);
		printf("%#- 10.6u<--\n\n", 120);
		ft_printf("%#- 10.2u<--\n", 20);
		printf("%#- 10.2u<--\n\n", 20);

		ft_printf("%#- 10.1u<--\n", 120);
		printf("%#- 10.1u<--\n\n", 120);
		ft_printf("%#- 10.1u<--\n", 20);
		printf("%#- 10.1u<--\n\n", 20);

		ft_printf("%#- 10.2u<--\n", 0);
		printf("%#- 10.2u<--\n\n", 0);
		ft_printf("%#-10.2u<--\n", 0);
		printf("%#-10.2u<--\n\n", 0);
		ft_printf("%- 10.2u<--\n", 0);
		printf("%- 10.2u<--\n\n", 0);
		ft_printf("%-010.2u<--\n", 0);
		printf("%-010.2u<--\n\n", 0);
		ft_printf("%#10.2u<--\n", 0);
		printf("%#10.2u<--\n\n", 0);

		ft_printf("%#- 10.12u<--\n", 20);
		printf("%#- 10.12u<--\n\n", 20);
		ft_printf("%#- 10.12u<--\n", 120);
		printf("%#- 10.12u<--\n\n", 120);
		ft_printf("%#- 10.12u<--\n", 20);
		printf("%#- 10.12u<--\n\n", 20);
		ft_printf("%#- 10.12u<--\n", 0);
		printf("%#- 10.12u<--\n\n", 0);

		ft_printf("-->Width<--\n\n");
		ft_printf("%#- 10u<--\n", 42);
		printf("%#- 10u<--\n\n", 42);
		ft_printf("%#- 10u<--\n", 142);
		printf("%#- 10u<--\n\n", 142);
		ft_printf("%#- 10u<--\n", 42);
		printf("%#- 10u<--\n\n", 42);
		ft_printf("%#- 10u<--\n", 142);
		printf("%#- 10u<--\n\n", 142);
		ft_printf("%#- 10u<--\n", 20);
		printf("%#- 10u<--\n\n", 20);
		ft_printf("%#- 10u<--\n", 0);
		printf("%#- 10u<--\n\n", 0);
		ft_printf("%#- 1u<--\n", 42);
		printf("%#- 1u<--\n\n", 42);

		ft_printf("-->Precision<--\n\n");
		ft_printf("%#- .8u<--\n", 42);
		printf("%#- .8u<--\n\n", 42);
		ft_printf("%#- .8u<--\n", 142);
		printf("%#- .8u<--\n\n", 142);
		ft_printf("%#- .8u<--\n", 42);
		printf("%#- .8u<--\n\n", 42);
		ft_printf("%#- .2u<--\n", 142);
		printf("%#- .2u<--\n\n", 142);
		ft_printf("%#- .1u<--\n", 42);
		printf("%#- .1u<--\n\n", 42);
		ft_printf("%#- .u<--\n", 42);
		printf("%#- .u<--\n\n", 42);
		ft_printf("%.u<--\n", 42);
		printf("%.u<--\n\n", 42);
		ft_printf("%#.u<--\n", 42);
		printf("%#.u<--\n\n", 42);
		ft_printf("%#- .0u<--\n", 42);
		printf("%#- .0u<--\n\n", 42);
		ft_printf("%#- .8u<--\n", 0);
		printf("%#- .8u<--\n\n", 0);

		ft_printf("-->##++x++##<--\n\n");

		ft_printf("-->Width_Precision<--\n\n");
		ft_printf("%#-+10.12u<--\n", 42);
		printf("%#-+10.12u<--\n\n", 42);
		ft_printf("%#-+10.10u<--\n", 42);
		printf("%#-+10.10u<--\n\n", 42);
		ft_printf("%#-+10.8u<--\n", 42);
		printf("%#-+10.8u<--\n\n", 42);
		ft_printf("%#-+10.15u<--\n", 0);
		printf("%#-+10.15u<--\n\n", 0);

		ft_printf("%#-+10.8u<--\n", 20);
		printf("%#-+10.8u<--\n\n", 20);
		ft_printf("%#-+10.8u<--\n", 20);
		printf("%#-+10.8u<--\n\n", 20);
		ft_printf("%#-+10.6u<--\n", 120);
		printf("%#-+10.6u<--\n\n", 120);
		ft_printf("%#-+10.2u<--\n", 20);
		printf("%#-+10.2u<--\n\n", 20);

		ft_printf("%#-+10.1u<--\n", 120);
		printf("%#-+10.1u<--\n\n", 120);
		ft_printf("%#-+10.1u<--\n", 20);
		printf("%#-+10.1u<--\n\n", 20);

		ft_printf("%#-+10.2u<--\n", 0);
		printf("%#-+10.2u<--\n\n", 0);
		ft_printf("%#-+10.2u<--\n", 0);
		printf("%#-+10.2u<--\n\n", 0);
		ft_printf("%-+10.2u<--\n", 0);
		printf("%-+10.2u<--\n\n", 0);
		ft_printf("%-010.2u<--\n", 0);
		printf("%-010.2u<--\n\n", 0);
		ft_printf("%#10.2u<--\n", 0);
		printf("%#10.2u<--\n\n", 0);

		ft_printf("%#-+10.12u<--\n", 20);
		printf("%#-+10.12u<--\n\n", 20);
		ft_printf("%#-+10.12u<--\n", 120);
		printf("%#-+10.12u<--\n\n", 120);
		ft_printf("%#-+10.12u<--\n", 20);
		printf("%#-+10.12u<--\n\n", 20);
		ft_printf("%#-+10.12u<--\n", 0);
		printf("%#-+10.12u<--\n\n", 0);

		ft_printf("-->Width<--\n\n");
		ft_printf("%#-+10u<--\n", 42);
		printf("%#-+10u<--\n\n", 42);
		ft_printf("%#-+10u<--\n", 142);
		printf("%#-+10u<--\n\n", 142);
		ft_printf("%#-+10u<--\n", 42);
		printf("%#-+10u<--\n\n", 42);
		ft_printf("%#-+2u<--\n", 142);
		printf("%#-+1u<--\n\n", 142);
		ft_printf("%#-+2u<--\n", 20);
		printf("%#-+2u<--\n\n", 20);
		ft_printf("%#-+1u<--\n", 0);
		printf("%#-+1u<--\n\n", 0);
		ft_printf("%#-+1u<--\n", 42);
		printf("%#-+1u<--\n\n", 42);

		ft_printf("-->Precision<--\n\n");
		ft_printf("%#-+.8u<--\n", 42);
		printf("%#-+.8u<--\n\n", 42);
		ft_printf("%#-+.8u<--\n", 142);
		printf("%#-+.8u<--\n\n", 142);
		ft_printf("%#-+.8u<--\n", 42);
		printf("%#-+.8u<--\n\n", 42);
		ft_printf("%#-+.2u<--\n", 142);
		printf("%#-+.2u<--\n\n", 142);
		ft_printf("%#-+.1u<--\n", 42);
		printf("%#-+.1u<--\n\n", 42);
		ft_printf("%#-+.u<--\n", 42);
		printf("%#-+.u<--\n\n", 42);
		ft_printf("%+.u<--\n", 42);
		printf("%+.u<--\n\n", 42);
		ft_printf("%#.u<--\n", 42);
		printf("%#.u<--\n\n", 42);
		ft_printf("%#-+.0u<--\n", 42);
		printf("%#-+.0u<--\n\n", 42);
		ft_printf("%#-+.8u<--\n", 0);
		printf("%#-+.8u<--\n\n", 0);

		ft_printf("%-.0u<--\n", 0);
		printf("%-.0u<--\n\n", 0);
		ft_printf("%-.0u<--\n", 0);
		printf("%-.0u<--\n\n", 0);
		ft_printf("%-.1u<--\n", 0);
		printf("%-.1u<--\n\n", 0);
		ft_printf("%10.0u<--\n", 0);
		printf("%10.0u<--\n\n", 0);
		ft_printf("%1.0u<--\n", 0);
		printf("%1.0u<--\n\n", 0);

		ft_printf("%#10.5llu<--\n", ULLONG_MAX);
		printf("%#10.5llu<--\n\n", ULLONG_MAX);

		ft_printf("%#10.5llu<--\n", LLONG_MIN);
		printf("%#10.5llu<--\n\n", LLONG_MIN);

		ft_printf("%#10.5lu<--\n", LONG_MAX);
		printf("%#10.5lu<--\n\n", LONG_MAX);

		ft_printf("%#10.5u<--\n", INT_MAX);
		printf("%#10.5u<--\n\n", INT_MAX);

		ft_putendl("Ok");
		ft_printf("%#10.5u<--\n", 42);
		printf("%#10.5u<--\n\n", 42);

		ft_printf("#10.0x %#10.0u<--\n", 42);
		printf("#10.0x %#10.0u<--\n\n", 42);

		ft_printf("#10.1x %#10.1u<--\n", 42);
		printf("#10.1x %#10.1u<--\n\n", 42);

		ft_printf("10.0x %10.0u<--\n", 42);
		printf("10.0x %10.0u<--\n\n", 42);

		ft_printf("10.1x %10.1u<--\n", 42);
		printf("10.1x %10.1u<--\n\n", 42);

		ft_printf("%#10.2u<--\n", 20);
		printf("%#10.2u<--\n\n", 20);

		ft_printf("%10.5u<--\n", LLONG_MAX);
		printf("%10.5u<--\n\n", LLONG_MAX);

		ft_printf("%llu<--\n", ULLONG_MAX);
		printf("%llu<--\n", ULLONG_MAX);

		ft_printf("%#-+.0u<--\n", 0);
		printf("%#-+.0u<--\n\n", 0);
		ft_printf("%#-+.0u<--\n", 0);
		printf("%#-+.0u<--\n\n", 0);
		ft_printf("%#.0u<--\n", 0);
		printf("%#.0u<--\n\n", 0);

		ft_putendl("OK");
		ft_printf("%#-+.1u<--\n", 0);
		printf("%#-+.1u<--\n\n", 0);
		ft_printf("%#-+.u<--\n", 0);
		printf("%#-+.u<--\n\n", 0);
		ft_printf("%#- .1u<--\n", 0);
		printf("%#- .1u<--\n\n", 0);
		ft_printf("%#-.1u<--\n", 0);
		printf("%#-.1u<--\n\n", 0);
		ft_printf("%#.1u<--\n", 0);
		printf("%#.1u<--\n\n", 0);
		ft_printf("%.1u<--\n", 0);
		printf("%.1u<--\n\n", 0);
		ft_printf("#-+.8o %#-+.8u<--\n", 0);
		printf("#-+.8o %#-+.8u<--\n\n", 0);
		ft_printf("#-.8o %#-.8u<--\n", 0);
		printf("#-.8o %#-.8u<--\n\n", 0);
		ft_printf("#.8 %#.8u<--\n", 0);
		printf("#.8 %#.8u<--\n\n", 0);
		ft_printf("-+.8o %-+.8u<--\n", 0);
		printf("-+.8o %-+.8u<--\n\n", 0);
		ft_printf("-.8o %-.8u<--\n", 0);
		printf("-.8o %-.8u<--\n\n", 0);
		ft_printf(".8 %.8u<--\n", 0);
		printf(".8 %.8u<--\n\n", 0);
		ft_putendl("/");
		ft_printf("#-+.1o %#-+.1u<--\n", 0);
		printf("#-+.1o %#-+.1u<--\n\n", 0);
		ft_printf("#-+.2o %#-+.2u<--\n", 0);
		printf("#-+.2o %#-+.2u<--\n\n", 0);
		ft_printf("#-+.1o %#-+.1u<--\n", 0);
		printf("#-+.1o %#-+.1u<--\n\n", 0);
		ft_printf("#-.8o %#-.8u<--\n", 0);
		printf("#-.8o %#-.8u<--\n\n", 0);
		ft_printf("#.8 %#.8u<--\n", 0);
		printf("#.8 %#.8u<--\n\n", 0);
		ft_printf("-+.8o %-+.8u<--\n", 0);
		printf("-+.8o %-+.8u<--\n\n", 0);
		ft_printf("-.8o %-.8u<--\n", 0);
		printf("-.8o %-.8u<--\n\n", 0);
		ft_printf(".8 %.8u<--\n", 0);
		printf(".8 %.8u<--\n\n", 0);
		ft_putendl("OK");
		ft_printf("%#-+.u<--\n", 0);
		printf("%#-+.u<--\n\n", 0);
		ft_printf("%#- .u<--\n", 0);
		printf("%#- .u<--\n\n", 0);
		ft_printf("%#-.u<--\n", 0);
		printf("%#-.u<--\n\n", 0);
		ft_printf("%#.u<--\n", 0);
		printf("%#.u<--\n\n", 0);
		ft_printf("%.u<--\n", 0);
		printf("%.u<--\n\n", 0);
		ft_putendl("OK");
		ft_printf("%#-+10.0u<--\n", 0);
		printf("%#-+10.0u<--\n\n", 0);
		ft_printf("%#-+10.0u<--\n", 0);
		printf("%#-+10.0u<--\n\n", 0);
		ft_printf("%#10.0u<--\n", 0);
		printf("%#10.0u<--\n\n", 0);

		ft_printf("%llu<--\n", ULLONG_MAX);
		printf("%llu<--\n\n", ULLONG_MAX);
		ft_printf("%llu<--\n", LLONG_MAX);
		printf("%llu<--\n\n", LLONG_MAX);
		ft_printf("%lu<--\n", LONG_MAX);
		printf("%lu<--\n\n", LONG_MAX);
		ft_printf("%u<--\n", INT_MAX);
		printf("%u<--\n\n", INT_MAX);
		ft_printf("%u<--\n", 150150);
		printf("%u<--\n\n", 150150);
*/
/*		ft_putendl("Check signed");
		ft_printf("%lld<--\n", ULLONG_MAX);
		printf("%lld<--\n\n", ULLONG_MAX);
		ft_printf("%lld<--\n", LLONG_MAX);
		printf("%lld<--\n\n", LLONG_MAX);
		ft_printf("%lld<--\n", LLONG_MAX);
		printf("%lld<--\n\n", LLONG_MAX);
		ft_printf("%ld<--\n", LONG_MAX);
		printf("%ld<--\n\n", LONG_MAX);
		ft_printf("%d<--\n", INT_MAX);
		printf("%d<--\n\n", INT_MAX);
		ft_printf("%d<--\n", 150150);
		printf("%d<--\n\n", 150150);
		ft_printf("%lld<--\n", LLONG_MIN);
		printf("%lld<--\n\n", LLONG_MIN);
		ft_printf("%lld<--\n", LLONG_MIN);
		printf("%lld<--\n\n", LLONG_MIN);
		ft_printf("%ld<--\n", LONG_MIN);
		printf("%ld<--\n\n", LONG_MIN);
		ft_printf("%d<--\n", INT_MIN);
		printf("%d<--\n\n", INT_MIN);
		ft_printf("%d<--\n", SHRT_MIN);
		printf("%d<--\n\n", SHRT_MIN);
		ft_printf("%d<--\n", -150150);
		printf("%d<--\n\n", -150150);

		ft_putendl("x.x");
		ft_printf("%10.10d<--\n", 20);
		printf("%10.10d<--\n\n", 20);
		ft_printf("%2.10d<--\n", -142);
		printf("%2.10d<--\n\n", -142);
		ft_printf("%2.10d<--\n", 142);
		printf("%2.10d<--\n\n", 142);
		ft_printf("%1.10d<--\n", 142);
		printf("%1.10d<--\n\n", 142);

		ft_printf("%10.5d<--\n", 20);
		printf("%10.5d<--\n\n", 20);

		ft_printf("%10.2d<--\n", 20);
		printf("%10.2d<--\n\n", 20);
		ft_printf("%10.1d<--\n", 20); //
		printf("%10.1d<--\n\n", 20); //
		ft_printf("%10.1d<--\n", 142); //
		printf("%10.1d<--\n\n", 142); //
		ft_printf("%10.1d<--\n", 1420); //
		printf("%10.1d<--\n\n", 1420); //
		ft_printf("%10.3d<--\n", 1420); //
		printf("%10.3d<--\n\n", 1420); //
		ft_printf("%10.0d<--\n", 1420); //
		printf("%10.0d<--\n\n", 1420); //
		ft_printf("%10.1d<--\n", 0); //
		printf("%10.1d<--\n\n", 0); //
		ft_printf("%10.d<--\n", 0); //
		printf("%10.d<--\n\n", 0); //
		ft_printf("%10.0d<--\n", 0); //
		printf("%10.0d<--\n\n", 0); //

	//	ft_printf("%2.10lld<--\n", INT_MIN);
	//	printf("%2.10lld<--\n\n", INT_MIN);


		ft_printf("%10.15d<--\n", 142);
		printf("%10.15d<--\n\n", 142);

		ft_printf("%10.15d<--\n", -142);
		printf("%10.15d<--\n\n", -142);

		ft_printf("%10.0d<--\n", 0);
		printf("%10.0d<--\n\n", 0);

		ft_printf("%10.0d<--\n", 1); //
		printf("%10.0d<--\n\n", 1);

		ft_printf("%10.1d<--\n", 0);
		printf("%10.1d<--\n\n", 0);

		ft_printf("%#10.10d<--\n", 0);
		printf("%#10.10d<--\n\n", 0);
		ft_printf("% 10.10d<--\n", 0);
		printf("% 10.10d<--\n\n", 0);
		ft_printf("%+10.10d<--\n", 0);
		printf("%+10.10d<--\n\n", 0);
		ft_printf("%-10.10d<--\n", 0);
		printf("%-10.10d<--\n\n", 0);

		ft_putendl("x");
		ft_printf("%10d<--\n", -20);
		printf("%10d<--\n\n", -20);
		ft_printf("%2d<--\n", -20);
		printf("%2d<--\n\n", -20);
		ft_printf("%1d<--\n", -20);
		printf("%1d<--\n\n", -20);
		ft_printf("%3d<--\n", -20);
		printf("%3d<--\n\n", -20);
		ft_printf("%4d<--\n", -20);
		printf("%4d<--\n\n", -20);
		ft_printf("%2d<--\n", -142);
		printf("%2d<--\n\n", -142);
		ft_printf("%2d<--\n", 142);
		printf("%2d<--\n\n", 142);
		ft_printf("%1d<--\n", 142);
		printf("%1d<--\n\n", 142);
		ft_printf("%10d<--\n", 20);
		printf("%10d<--\n\n", 20);
		ft_printf("%10d<--\n", 20);
		printf("%10d<--\n\n", 20);

		ft_printf("%15d<--\n", 142);
		printf("%15d<--\n\n", 142);
		ft_printf("%1d<--\n", 0);
		printf("%1d<--\n\n", 0);

		ft_printf("%30d<--\n", 1);
		printf("%30d<--\n\n", 1);
		ft_printf("%50d<--\n", 0);
		printf("%50d<--\n\n", 0);
		ft_printf("%1d<--\n", 0);
		printf("%1d<--\n\n", 0);
		ft_printf("%2d<--\n", 20);
		printf("%2d<--\n\n", 20);
		ft_printf("%2d<--\n", 200);
		printf("%2d<--\n\n", 200);
		ft_printf("%4d<--\n", 200);
		printf("%4d<--\n\n", 200);

		ft_printf("%10d<--\n", -20);
		printf("%10d<--\n\n", -20);
		ft_printf("%10d<--\n", -142);
		printf("%10d<--\n\n", -142);
		ft_printf("%10d<--\n", 20);
		printf("%10d<--\n\n", 20);
		ft_printf("%10d<--\n", 142);
		printf("%10d<--\n\n", 142);
		ft_printf("%10d<--\n", 0);
		printf("%10d<--\n\n", 0);
		ft_printf("%10d<--\n", -1);
		printf("%10d<--\n\n", -1);

		ft_printf("%10d<--\n", -150);
		printf("%10d<--\n\n", -150);

		ft_printf("%#10d<--\n", -150);
		printf("%#10d<--\n\n", -150);
		ft_printf("% 10d<--\n", -150);
		printf("% 10d<--\n\n", -150);
		ft_printf("%+10d<--\n", -150);
		printf("%+10d<--\n\n", -150);

		ft_printf("%.25d<--\n", -20);
		printf("%.25d<--\n\n", -20);
		ft_printf("%.25d<--\n", 20);
		printf("%.25d<--\n\n", 20);
		ft_printf("%.25d<--\n", 0);
		printf("%.25d<--\n\n", 0);
		ft_printf("%.d<--\n", -20);
		printf("%.d<--\n\n", -20);
		ft_printf("%.1d<--\n", 20);
		printf("%.1d<--\n\n", 20);
		ft_printf("%.0d<--\n", 0);
		printf("%.0d<--\n\n", 0);
		ft_printf("%.1d<--\n", 0);
		printf("%.1d<--\n\n", 0);
		ft_printf("%.10d<--\n", -20);
		printf("%.10d<--\n\n", -20);
		ft_printf("%.2d<--\n", 20);
		printf("%.2d<--\n\n", 20);
		ft_printf("%.3d<--\n", 20);
		printf("%.3d<--\n\n", 20);
		ft_printf("%.15d<--\n", 0);
		printf("%.15d<--\n\n", 0);
			printf("-->###<--\n\n");

			ft_printf("-->Width_Precision<--\n\n");
			ft_printf("%#10.10d<--\n", 42);
			printf("%#10.10d<--\n\n", 42);

			ft_printf("%#10.10d<--\n", 4242);
			printf("%#10.10d<--\n\n", 4242);

			ft_printf("%#10.15d<--\n", 0);
			printf("%#10.15d<--\n\n", 0);

			ft_printf("%#10.8d<--\n", 42);
			printf("%#10.8d<--\n\n", 42);

			ft_printf("%#10.8d<--\n", 20);
			printf("%#10.8d<--\n\n", 20);

			ft_printf("%#10.4d<--\n", 20);
			printf("%#10.4d<--\n\n", 20);

			ft_printf("%#10.6d<--\n", 120);
			printf("%#10.6d<--\n\n", 120);

			ft_printf("%#10.8d<--\n", 1200);
			printf("%#10.8d<--\n\n", 1200);

			ft_printf("%#10.1d<--\n", 120);
			printf("%#10.1d<--\n\n", 120);

			ft_printf("%#10.6d<--\n", 242);
			printf("%#10.6d<--\n\n", 242);

			ft_printf("%#10.6d<--\n", 4242);
			printf("%#10.6d<--\n\n", 4242);

			ft_printf("%#10.2d<--\n", 4242);
			printf("%#10.2d<--\n\n", 4242);

			ft_printf("%#10.0d<--\n", 4242);
			printf("%#10.0d<--\n\n", 4242);

			ft_printf("%#10.5d<--\n", 4242);
			printf("%#10.5d<--\n\n", 4242);

			ft_printf("%#10.2d<--\n", 20);
			printf("%#10.2d<--\n\n", 20);

			ft_putendl("ok");
			ft_printf("%#10.2d<--\n", 0);
			printf("%#10.2d<--\n\n", 0);

			ft_printf("%#10.4d<--\n", 0);
			printf("%#10.4d<--\n\n", 0);

			ft_printf("%10.2d<--\n", 0);
			printf("%10.2d<--\n\n", 0);
			ft_printf("%.2d<--\n", 0);
			printf("%.2d<--\n\n", 0);
			ft_printf("%10d<--\n", 0);
			printf("%10d<--\n\n", 0);
			ft_printf("%#10.5d<--\n", ULLONG_MAX);
			printf("%#10.5d<--\n\n", ULLONG_MAX);
			ft_printf("%10.5d<--\n", LLONG_MAX);
			printf("%10.5d<--\n\n", LLONG_MAX);

			ft_printf("%#10.12d<--\n", 20);
			printf("%#10.12d<--\n\n", 20);
			ft_printf("%#10.12d<--\n", 120);
			printf("%#10.12d<--\n\n", 120);
			ft_printf("%#10.12d<--\n", 20);
			printf("%#10.12d<--\n\n", 20);

			ft_printf("%#10.12d<--\n", 0);
			printf("%#10.12d<--\n\n", 0);

			ft_printf("-->Width<--\n\n");
			ft_printf("%#10d<--\n", 42);
			printf("%#10d<--\n\n", 42);
			ft_printf("%#10d<--\n", 142);
			printf("%#10d<--\n\n", 142);
			ft_printf("%#10d<--\n", 14200);
			printf("%#10d<--\n\n", 14200);
			ft_printf("%#10d<--\n", 42);
			printf("%#10d<--\n\n", 42);
			ft_printf("%#10d<--\n", 142);
			printf("%#10d<--\n\n", 142);
			ft_printf("%#10d<--\n", 20);
			printf("%#10d<--\n\n", 20);
			ft_printf("%#10d<--\n", 0);
			printf("%#10d<--\n\n", 0);
			ft_printf("%#1d<--\n", 42);
			printf("%#1d<--\n\n", 42);

			ft_printf("-->Precision<--\n\n");
			ft_printf("%#.8d<--\n", 42);
			printf("%#.8d<--\n\n", 42);

			ft_printf("%#.8d<--\n", 142);
			printf("%#.8d<--\n\n", 142);

			ft_printf("%#.8d<--\n", 42);
			printf("%#.8d<--\n\n", 42);

			ft_printf("%#.2d<--\n", 142);
			printf("%#.2d<--\n\n", 142);

			ft_printf("%#.8d<--\n", 0);
			printf("%#.8d<--\n\n", 0);

			ft_printf("%#10.5lld<--\n", ULLONG_MAX);
			printf("%#10.5lld<--\n\n", ULLONG_MAX);
			ft_printf("%10.5lld<--\n", LLONG_MAX);
			printf("%10.5lld<--\n\n", LLONG_MAX);


			printf("-->---<--\n\n");

			ft_printf("-->Width_Precision<--\n\n");
			ft_printf("%-10.10d<--\n", 42);
			printf("%-10.10d<--\n\n", 42);
			ft_printf("%-10.8d<--\n", 42);
			printf("%-10.8d<--\n\n", 42);
			ft_printf("%-10.15d<--\n", 0);
			printf("%-10.15d<--\n\n", 0);
			ft_printf("%-10.8d<--\n", 20);
			printf("%-10.8d<--\n\n", 20);
			ft_printf("%-10.8d<--\n", 20);
			printf("%-10.8d<--\n\n", 20);
			ft_printf("%-10.6d<--\n", 120);
			printf("%-10.6d<--\n\n", 120);
			ft_printf("%-10.6d<--\n", 1200);
			printf("%-10.6d<--\n\n", 1200);
			ft_printf("%-10.6d<--\n", 1);
			printf("%-10.6d<--\n\n", 1);
			ft_printf("%-10.2d<--\n", 20);
			printf("%-10.2d<--\n\n", 20);

			ft_printf("%-10.2d<--\n", 0);
			printf("%-10.2d<--\n\n", 0);

			ft_printf("%-10.4d<--\n", 0);
			printf("%-10.4d<--\n\n", 0);

			ft_printf("%10.2d<--\n", 0);
			printf("%10.2d<--\n\n", 0);
			ft_printf("%-10.5d<--\n", ULLONG_MAX);
			printf("%-10.5d<--\n\n", ULLONG_MAX);
			ft_printf("%-10.2d<--\n", 100000);
			printf("%-10.2d<--\n\n", 100000);
			ft_printf("%-10.1d<--\n", 100);
			printf("%-10.1d<--\n\n", 100);
			ft_printf("%-10.0d<--\n", 10);
			printf("%-10.0d<--\n\n", 10);
		//			ft_printf("%10.5d<--\n", LLONG_MAX);
		//			printf("%10.5d<--\n\n", LLONG_MAX);

			ft_printf("%-10.12d<--\n", 20);
			printf("%-10.12d<--\n\n", 20);
			ft_printf("%-10.12d<--\n", 120);
			printf("%-10.12d<--\n\n", 120);
			ft_printf("%-10.12d<--\n", 20);
			printf("%-10.12d<--\n\n", 20);

			ft_printf("%-10.12d<--\n", 0);
			printf("%-10.12d<--\n\n", 0);

			ft_printf("%-10.7d<--\n", -20);
			printf("%-10.7d<--\n\n", -20);
			ft_printf("%-10.1d<--\n", 20);
			printf("%-10.1d<--\n\n", 20);
			ft_printf("%-10.1d<--\n", -20);
			printf("%-10.1d<--\n\n", -20);
			ft_printf("%-10.2d<--\n", -12);
			printf("%-10.2d<--\n\n", -12);
			ft_printf("%-10.2d<--\n", -1242);
			printf("%-10.2d<--\n\n", -1242);

			ft_printf("-->Width<--\n\n");
			ft_printf("%-10d<--\n", 42);
			printf("%-10d<--\n\n", 42);
			ft_printf("%-10d<--\n", -142);
			printf("%-10d<--\n\n", -142);
			ft_printf("%-10d<--\n", 142);
			printf("%-10d<--\n\n", 142);
			ft_printf("%-10d<--\n", 14200);
			printf("%-10d<--\n\n", 14200);
			ft_printf("%-10d<--\n", 42);
			printf("%-10d<--\n\n", 42);
			ft_printf("%-10d<--\n", 142);
			printf("%-10d<--\n\n", 142);
			ft_printf("%-10d<--\n", 20);
			printf("%-10d<--\n\n", 20);
			ft_printf("%-10d<--\n", 0);
			printf("%-10d<--\n\n", 0);
			ft_printf("%-1d<--\n", 42);
			printf("%-1d<--\n\n", 42);
			ft_printf("%-2d<--\n", 10);
			printf("%-2d<--\n\n", 10);
			ft_printf("%-4d<--\n", 424);
			printf("%-4d<--\n\n", 424);
			ft_printf("%-1d<--\n", 0);
			printf("%-1d<--\n\n", 0);

			ft_printf("%#10.5lld<--\n", ULLONG_MAX);
			printf("%#10.5lld<--\n\n", ULLONG_MAX);
			ft_printf("%10.5lld<--\n", LLONG_MAX);
			printf("%10.5lld<--\n\n", LLONG_MAX);

			ft_printf("-->Precision<--\n\n");
			ft_printf("%-.8d<--\n", 42);
			printf("%-.8d<--\n\n", 42);
			ft_printf("%-.8d<--\n", 142);
			printf("%-.8d<--\n\n", 142);
			ft_printf("%-.8d<--\n", 42);
			printf("%-.8d<--\n\n", 42);
			ft_printf("%-.2d<--\n", 142);
			printf("%-.2d<--\n\n", 142);
			ft_printf("%-.8d<--\n", 0);
			printf("%-.8d<--\n\n", 0);
			ft_printf("%-.d<--\n", 0);
			printf("%-.d<--\n\n", 0);
			ft_printf("%-.0d<--\n", 0);
			printf("%-.0d<--\n\n", 0);
			ft_printf("%.d<--\n", 0);
			printf("%.d<--\n\n", 0);
			ft_printf("%-.1d<--\n", 0);
			printf("%-.1d<--\n\n", 0);
			ft_printf("%-.3d<--\n", 142);
			printf("%-.3d<--\n\n", 142);
			ft_printf("%-.4d<--\n", 142);
			printf("%-.4d<--\n\n", 142);

			printf("-->   <--\n\n");

			ft_printf("-->Width_Precision<--\n\n");
			ft_printf("% 10.10d<--\n", 42);
			printf("% 10.10d<--\n\n", 42);
			ft_printf("% 10.8d<--\n", 42);
			printf("% 10.8d<--\n\n", 42);
			ft_printf("% 10.15d<--\n", 0);
			printf("% 10.15d<--\n\n", 0);
			ft_printf("% 10.8d<--\n", 20);
			printf("% 10.8d<--\n\n", 20);
			ft_printf("% 10.8d<--\n", 20);
			printf("% 10.8d<--\n\n", 20);
			ft_printf("% 10.6d<--\n", 120);
			printf("% 10.6d<--\n\n", 120);
			ft_printf("% 10.2d<--\n", 20);
			printf("% 10.2d<--\n\n", 20);

			ft_printf("% 10.2d<--\n", 0);
			printf("% 10.2d<--\n\n", 0);

			ft_printf("% 10.4d<--\n", 0);
			printf("% 10.4d<--\n\n", 0);

			//			ft_printf("%10.2d<--\n", 0);
			//			printf("%10.2d<--\n\n", 0);
			ft_printf("% 10.5d<--\n", ULLONG_MAX);
			printf("% 10.5d<--\n\n", ULLONG_MAX);
			ft_printf("% 10.2d<--\n", 100000);
			printf("% 10.2d<--\n\n", 100000);
			ft_printf("% 10.1d<--\n", 100);
			printf("% 10.1d<--\n\n", 100);
			ft_printf("% 10.0d<--\n", 10);
			printf("% 10.0d<--\n\n", 10);
			//			ft_printf("%10.5d<--\n", LLONG_MAX);
			//			printf("%10.5d<--\n\n", LLONG_MAX);

			ft_printf("% 10.12d<--\n", 20);
			printf("% 10.12d<--\n\n", 20);
			ft_printf("% 10.12d<--\n", 120);
			printf("% 10.12d<--\n\n", 120);
			ft_printf("% 10.12d<--\n", 20);
			printf("% 10.12d<--\n\n", 20);

			ft_printf("% 10.12d<--\n", 0);
			printf("% 10.12d<--\n\n", 0);

			ft_printf("-->Width<--\n\n");
			ft_printf("% 10d<--\n", 42);
			printf("% 10d<--\n\n", 42);
			ft_printf("% 10d<--\n", -142);
			printf("% 10d<--\n\n", -142);
			ft_printf("% 10d<--\n", 142);
			printf("% 10d<--\n\n", 142);
			ft_printf("% 10d<--\n", 14200);
			printf("% 10d<--\n\n", 14200);
			ft_printf("% 10d<--\n", 42);
			printf("% 10d<--\n\n", 42);
			ft_printf("% 10d<--\n", 142);
			printf("% 10d<--\n\n", 142);
			ft_printf("% 10d<--\n", 20);
			printf("% 10d<--\n\n", 20);
			ft_printf("% 10d<--\n", 0);
			printf("% 10d<--\n\n", 0);
			ft_printf("% 1d<--\n", 42);
			printf("% 1d<--\n\n", 42);

			ft_printf("-->Precision<--\n\n");
			ft_printf("% .8d<--\n", 42);
			printf("% .8d<--\n\n", 42);
			ft_printf("% .8d<--\n", 142);
			printf("% .8d<--\n\n", 142);
			ft_printf("% .8d<--\n", 42);
			printf("% .8d<--\n\n", 42);
			ft_printf("% .2d<--\n", 142);
			printf("% .2d<--\n\n", 142);
			ft_printf("% .8d<--\n", 0);
			printf("% .8d<--\n\n", 0);

		ft_printf("-->##--x--##<--\n\n");

		ft_printf("-->Width_Precision<--\n\n");
		ft_printf("%#-10.12d<--\n", 42);
		printf("%#-10.12d<--\n\n", 42);
		ft_printf("%#-10.10d<--\n", 42);
		printf("%#-10.10d<--\n\n", 42);
		ft_printf("%#-10.8d<--\n", 42);
		printf("%#-10.8d<--\n\n", 42);
		ft_printf("%#-10.15d<--\n", 0);
		printf("%#-10.15d<--\n\n", 0);

		ft_printf("%#-10.12d<--\n", -142);
		printf("%#-10.12d<--\n\n", -142);
		ft_printf("%#-10.10d<--\n", -142);
		printf("%#-10.10d<--\n\n", -142);
		ft_printf("%#-10.8d<--\n", -142);
		printf("%#-10.8d<--\n\n", -142);
		ft_printf("%#-10.2d<--\n", -10);
		printf("%#-10.2d<--\n\n", -10);
		ft_printf("%#-10.d<--\n", -10);
		printf("%#-10.d<--\n\n", -10);

		ft_printf("%#-10.8d<--\n", 20);
		printf("%#-10.8d<--\n\n", 20);
		ft_printf("%#-10.8d<--\n", 20);
		printf("%#-10.8d<--\n\n", 20);
		ft_printf("%#-10.6d<--\n", 120);
		printf("%#-10.6d<--\n\n", 120);
		ft_printf("%#-10.2d<--\n", 20);
		printf("%#-10.2d<--\n\n", 20);

		ft_printf("%#-10.1d<--\n", 120);
		printf("%#-10.1d<--\n\n", 120);
		ft_printf("%#-10.1d<--\n", 20);
		printf("%#-10.1d<--\n\n", 20);

		ft_printf("%#10.12d<--\n", 20);
		printf("%#10.12d<--\n\n", 20);
		ft_printf("%#10.12d<--\n", 120);
		printf("%#10.12d<--\n\n", 120);
		ft_printf("%#10.12d<--\n", 20);
		printf("%#10.12d<--\n\n", 20);

		ft_printf("%#10.12d<--\n", 0);
		printf("%#10.12d<--\n\n", 0);

		ft_printf("%#-10.2d<--\n", 0);
		printf("%#-10.2d<--\n\n", 0);
		ft_printf("%#-10.0d<--\n", 0);
		printf("%#-10.0d<--\n\n", 0);
		ft_printf("%#-10.1d<--\n", 0);
		printf("%#-10.1d<--\n\n", 0);
		//	ft_printf("%-10.2d<--\n", 0);
		//	printf("%-10.2d<--\n\n", 0);
		//	ft_printf("%#10.2d<--\n", 0);
		//	printf("%#10.2d<--\n\n", 0);

		ft_printf("%#-10.12d<--\n", 20);
		printf("%#-10.12d<--\n\n", 20);
		ft_printf("%#-10.12d<--\n", 120);
		printf("%#-10.12d<--\n\n", 120);
		ft_printf("%#-10.13d<--\n", 1200);
		printf("%#-10.13d<--\n\n", 1200);
		ft_printf("%#-10.12d<--\n", 1200);
		printf("%#-10.12d<--\n\n", 1200);
		ft_printf("%#-10.12d<--\n", 20);
		printf("%#-10.12d<--\n\n", 20);
		ft_printf("%#-10.12d<--\n", 0);
		printf("%#-10.12d<--\n\n", 0);

		ft_printf("%10.1d<--\n", 0);
		printf("%10.1d<--\n\n", 0);

		ft_printf("%10.2d<--\n", 16);
		printf("%10.2d<--\n\n", 16);

		ft_printf("%10.d<--\n", 0);
		printf("%10.d<--\n\n", 0);

		ft_printf("-->Precision<--\n\n");
		ft_printf("%#-.8d<--\n", 42);
		printf("%#-.8d<--\n\n", 42);
		ft_printf("%#-.8d<--\n", 142);
		printf("%#-.8d<--\n\n", 142);
		ft_printf("%#-.8d<--\n", 42);
		printf("%#-.8d<--\n\n", 42);
		ft_printf("%#-.2d<--\n", 142);
		printf("%#-.2d<--\n\n", 142);
		ft_printf("%#-.8d<--\n", 0);
		printf("%#-.8d<--\n\n", 0);

		ft_printf("-->Width<--\n\n");
		ft_printf("%#-10d<--\n", 42);
		printf("%#-10d<--\n\n", 42);
		ft_printf("%#-10d<--\n", 142);
		printf("%#-10d<--\n\n", 142);
		ft_printf("%#-10d<--\n", 42);
		printf("%#-10d<--\n\n", 42);
		ft_printf("%#-10d<--\n", 142);
		printf("%#-10d<--\n\n", 142);
		ft_printf("%#-10d<--\n", 20);
		printf("%#-10d<--\n\n", 20);
		ft_printf("%#-10d<--\n", 0);
		printf("%#-10d<--\n\n", 0);
		ft_printf("%#-1d<--\n", 42);
		printf("%#-1d<--\n\n", 42);
		ft_printf("%#-1d<--\n", 424242);
		printf("%#-1d<--\n\n", 424242);
		ft_printf("%#-25d<--\n", 424242);
		printf("%#-25d<--\n\n", 424242);
		ft_printf("%#-7d<--\n", 424242);
		printf("%#-7d<--\n\n", 424242);
		ft_printf("%#-8d<--\n", 424242);
		printf("%#-8d<--\n\n", 424242);
		ft_printf("%#-d<--\n", 424242);
		printf("%#-d<--\n\n", 424242);
		ft_printf("-->Width<--\n\n");
		ft_printf("%-10d<--\n", 42);
		printf("%-10d<--\n\n", 42);
		ft_printf("%-10d<--\n", 142);
		printf("%-10d<--\n\n", 142);
		ft_printf("%-10d<--\n", 14200);
		printf("%-10d<--\n\n", 14200);
		ft_printf("%-10d<--\n", 42);
		printf("%-10d<--\n\n", 42);
		ft_printf("%-10d<--\n", 142);
		printf("%-10d<--\n\n", 142);
		ft_printf("%-10d<--\n", 20);
		printf("%-10d<--\n\n", 20);
		ft_printf("%-10d<--\n", 0);
		printf("%-10d<--\n\n", 0);
		ft_printf("%-1d<--\n", 42);
		printf("%-1d<--\n\n", 42);

		ft_printf("-->##--  x  --##<--\n\n");

		ft_printf("-->Width_Precision<--\n\n");
		ft_printf("%#- 10.12d<--\n", 42);
		printf("%#- 10.12d<--\n\n", 42);
		ft_printf("%#- 10.10d<--\n", 42);
		printf("%#- 10.10d<--\n\n", 42);
		ft_printf("%#- 10.8d<--\n", 42);
		printf("%#- 10.8d<--\n\n", 42);
		ft_printf("%#- 10.15d<--\n", 0);
		printf("%#- 10.15d<--\n\n", 0);

		ft_printf("%#- 10.8d<--\n", 20);
		printf("%#- 10.8d<--\n\n", 20);
		ft_printf("%#- 10.8d<--\n", 20);
		printf("%#- 10.8d<--\n\n", 20);
		ft_printf("%#- 10.6d<--\n", 120);
		printf("%#- 10.6d<--\n\n", 120);
		ft_printf("%#- 10.2d<--\n", 20);
		printf("%#- 10.2d<--\n\n", 20);

		ft_printf("%#- 10.1d<--\n", 120);
		printf("%#- 10.1d<--\n\n", 120);
		ft_printf("%#- 10.1d<--\n", 20);
		printf("%#- 10.1d<--\n\n", 20);

		ft_printf("%#- 10.2d<--\n", 0);
		printf("%#- 10.2d<--\n\n", 0);
		ft_printf("%#-10.2d<--\n", 0);
		printf("%#-10.2d<--\n\n", 0);
		ft_printf("%- 10.2d<--\n", 0);
		printf("%- 10.2d<--\n\n", 0);
		ft_printf("%-010.2d<--\n", 0);
		printf("%-010.2d<--\n\n", 0);
		ft_printf("%#10.2d<--\n", 0);
		printf("%#10.2d<--\n\n", 0);

		ft_printf("%#- 10.12d<--\n", 20);
		printf("%#- 10.12d<--\n\n", 20);
		ft_printf("%#- 10.12d<--\n", 120);
		printf("%#- 10.12d<--\n\n", 120);
		ft_printf("%#- 10.12d<--\n", 20);
		printf("%#- 10.12d<--\n\n", 20);
		ft_printf("%#- 10.12d<--\n", 0);
		printf("%#- 10.12d<--\n\n", 0);
		ft_printf("%#- 10.0d<--\n", 0);
		printf("%#- 10.0d<--\n\n", 0);
		ft_printf("%#- 10.1d<--\n", 10);
		printf("%#- 10.1d<--\n\n", 10);


		ft_printf("-->Width<--\n\n");
		ft_printf("%#- 10d<--\n", 42);
		printf("%#- 10d<--\n\n", 42);
		ft_printf("%#- 10d<--\n", 142);
		printf("%#- 10d<--\n\n", 142);
		ft_printf("%#- 10d<--\n", 42);
		printf("%#- 10d<--\n\n", 42);
		ft_printf("%#- 10d<--\n", 142);
		printf("%#- 10d<--\n\n", 142);
		ft_printf("%#- 10d<--\n", 20);
		printf("%#- 10d<--\n\n", 20);
		ft_printf("%#- 10d<--\n", 0);
		printf("%#- 10d<--\n\n", 0);
		ft_printf("%#- 1d<--\n", 42);
		printf("%#- 1d<--\n\n", 42);

		ft_printf("-->Precision<--\n\n");
		ft_printf("%#- .8d<--\n", 42);
		printf("%#- .8d<--\n\n", 42);
		ft_printf("%#- .8d<--\n", 142);
		printf("%#- .8d<--\n\n", 142);
		ft_printf("%#- .8d<--\n", 42);
		printf("%#- .8d<--\n\n", 42);
		ft_printf("%#- .2d<--\n", 142);
		printf("%#- .2d<--\n\n", 142);
		ft_printf("%#- .1d<--\n", 42);
		printf("%#- .1d<--\n\n", 42);
		ft_printf("%#- .d<--\n", 42);
		printf("%#- .d<--\n\n", 42);
		ft_printf("%.d<--\n", 42);
		printf("%.d<--\n\n", 42);
		ft_printf("%#.d<--\n", 42);
		printf("%#.d<--\n\n", 42);
		ft_printf("%#- .0d<--\n", 42);
		printf("%#- .0d<--\n\n", 42);
		ft_printf("%#- .8d<--\n", 0);
		printf("%#- .8d<--\n\n", 0);

		ft_printf("-->##++x++##<--\n\n");

		ft_printf("-->Width_Precision<--\n\n");
		ft_printf("%#-+10.12d<--\n", 42);
		printf("%#-+10.12d<--\n\n", 42);
		ft_printf("%#-+10.10d<--\n", 42);
		printf("%#-+10.10d<--\n\n", 42);
		ft_printf("%#-+10.8d<--\n", 42);
		printf("%#-+10.8d<--\n\n", 42);
		ft_printf("%#-+10.15d<--\n", 0);
		printf("%#-+10.15d<--\n\n", 0);

		ft_printf("%#-+10.8d<--\n", 20);
		printf("%#-+10.8d<--\n\n", 20);
		ft_printf("%#-+10.8d<--\n", 20);
		printf("%#-+10.8d<--\n\n", 20);
		ft_printf("%#-+10.6d<--\n", 120);
		printf("%#-+10.6d<--\n\n", 120);
		ft_printf("%#-+10.2d<--\n", 20);
		printf("%#-+10.2d<--\n\n", 20);

		ft_printf("%#-+10.1d<--\n", 120);
		printf("%#-+10.1d<--\n\n", 120);
		ft_printf("%#-+10.1d<--\n", 20);
		printf("%#-+10.1d<--\n\n", 20);

		ft_printf("%#-+10.2d<--\n", 0);
		printf("%#-+10.2d<--\n\n", 0);
		ft_printf("%#-+10.2d<--\n", 0);
		printf("%#-+10.2d<--\n\n", 0);
		ft_printf("%-+10.2d<--\n", 0);
		printf("%-+10.2d<--\n\n", 0);
		ft_printf("%-010.2d<--\n", 0);
		printf("%-010.2d<--\n\n", 0);
		ft_printf("%#10.2d<--\n", 0);
		printf("%#10.2d<--\n\n", 0);

		ft_printf("%#-+10.12d<--\n", 20);
		printf("%#-+10.12d<--\n\n", 20);
		ft_printf("%#-+10.12d<--\n", 120);
		printf("%#-+10.12d<--\n\n", 120);
		ft_printf("%#-+10.12d<--\n", 20);
		printf("%#-+10.12d<--\n\n", 20);
		ft_printf("%#-+10.12d<--\n", 0);
		printf("%#-+10.12d<--\n\n", 0);

		ft_printf("-->Width<--\n\n");
		ft_printf("%#-+10d<--\n", 42);
		printf("%#-+10d<--\n\n", 42);
		ft_printf("%#-+1d<--\n", 42);
		printf("%#-+1d<--\n\n", 42);
		ft_printf("%#-+2d<--\n", 42);
		printf("%#-+2d<--\n\n", 42);
		ft_printf("%#-+3d<--\n", 42);
		printf("%#-+3d<--\n\n", 42);
		ft_printf("%#-+4d<--\n", 42);
		printf("%#-+4d<--\n\n", 42);
		ft_printf("%#-+10d<--\n", 142);
		printf("%#-+10d<--\n\n", 142);
		ft_printf("%#-+10d<--\n", 42);
		printf("%#-+10d<--\n\n", 42);
		ft_printf("%#-+2d<--\n", 142);
		printf("%#-+1d<--\n\n", 142);
		ft_printf("%#-+2d<--\n", 20);
		printf("%#-+2d<--\n\n", 20);
		ft_printf("%#-+1d<--\n", 0);
		printf("%#-+1d<--\n\n", 0);
		ft_printf("%#-+1d<--\n", 42);
		printf("%#-+1d<--\n\n", 42);

		ft_printf("-->Precision<--\n\n");
		ft_printf("%#-+.8d<--\n", 42);
		printf("%#-+.8d<--\n\n", 42);
		ft_printf("%#-+.0d<--\n", 42);
		printf("%#-+.0d<--\n\n", 42);
		ft_printf("%#-+.d<--\n", 0);
		printf("%#-+.d<--\n\n", 0);
		ft_printf("%#-+.1d<--\n", 0);
		printf("%#-+.1d<--\n\n", 0);
		ft_printf("%#-+.8d<--\n", 142);
		printf("%#-+.8d<--\n\n", 142);
		ft_printf("%#-+.8d<--\n", 42);
		printf("%#-+.8d<--\n\n", 42);
		ft_printf("%#-+.2d<--\n", 142);
		printf("%#-+.2d<--\n\n", 142);
		ft_printf("%#-+.1d<--\n", 42);
		printf("%#-+.1d<--\n\n", 42);
		ft_printf("%#-+.d<--\n", 42);
		printf("%#-+.d<--\n\n", 42);
		ft_printf("%+.d<--\n", 42);
		printf("%+.d<--\n\n", 42);
		ft_printf("%#.d<--\n", 42);
		printf("%#.d<--\n\n", 42);
		ft_printf("%#-+.0d<--\n", 42);
		printf("%#-+.0d<--\n\n", 42);
		ft_printf("%#-+.8d<--\n", 0);
		printf("%#-+.8d<--\n\n", 0);

		ft_printf("%-.0d<--\n", 0);
		printf("%-.0d<--\n\n", 0);
		ft_printf("%-.0d<--\n", 0);
		printf("%-.0d<--\n\n", 0);
		ft_printf("%-.1d<--\n", 0);
		printf("%-.1d<--\n\n", 0);
		ft_printf("%10.0d<--\n", 0);
		printf("%10.0d<--\n\n", 0);
		ft_printf("%1.0d<--\n", 0);
		printf("%1.0d<--\n\n", 0);

		ft_printf("%#10.5lld<--\n", ULLONG_MAX);
		printf("%#10.5lld<--\n\n", ULLONG_MAX);

		ft_printf("%#10.5lld<--\n", LLONG_MIN);
		printf("%#10.5lld<--\n\n", LLONG_MIN);

		ft_printf("%#10.5ld<--\n", LONG_MAX);
		printf("%#10.5ld<--\n\n", LONG_MAX);

		ft_printf("%#10.5d<--\n", INT_MAX);
		printf("%#10.5d<--\n\n", INT_MAX);

		ft_putendl("Ok");
		ft_printf("%#10.5d<--\n", 42);
		printf("%#10.5d<--\n\n", 42);

		ft_printf("#10.0x %#10.0d<--\n", 42);
		printf("#10.0x %#10.0d<--\n\n", 42);

		ft_printf("#10.1x %#10.1d<--\n", 42);
		printf("#10.1x %#10.1d<--\n\n", 42);

		ft_printf("10.0x %10.0d<--\n", 42);
		printf("10.0x %10.0d<--\n\n", 42);

		ft_printf("10.1x %10.1d<--\n", 42);
		printf("10.1x %10.1d<--\n\n", 42);

		ft_printf("%#10.2d<--\n", 20);
		printf("%#10.2d<--\n\n", 20);

		ft_printf("%10.5d<--\n", LLONG_MAX);
		printf("%10.5d<--\n\n", LLONG_MAX);

		ft_printf("%lld<--\n", ULLONG_MAX);
		printf("%lld<--\n", ULLONG_MAX);

		ft_printf("%#-+.0d<--\n", 0);
		printf("%#-+.0d<--\n\n", 0);
		ft_printf("%#-+.0d<--\n", 0);
		printf("%#-+.0d<--\n\n", 0);
		ft_printf("%#.0d<--\n", 0);
		printf("%#.0d<--\n\n", 0);

		ft_putendl("OK");
		ft_printf("%#-+.1d<--\n", 0);
		printf("%#-+.1d<--\n\n", 0);
		ft_printf("%#-+.d<--\n", 0);
		printf("%#-+.d<--\n\n", 0);
		ft_printf("%#- .1d<--\n", 0);
		printf("%#- .1d<--\n\n", 0);
		ft_printf("%#-.1d<--\n", 0);
		printf("%#-.1d<--\n\n", 0);
		ft_printf("%#.1d<--\n", 0);
		printf("%#.1d<--\n\n", 0);
		ft_printf("%.1d<--\n", 0);
		printf("%.1d<--\n\n", 0);
		ft_printf("#-+.8o %#-+.8d<--\n", 0);
		printf("#-+.8o %#-+.8d<--\n\n", 0);
		ft_printf("#-.8o %#-.8d<--\n", 0);
		printf("#-.8o %#-.8d<--\n\n", 0);
		ft_printf("#.8 %#.8d<--\n", 0);
		printf("#.8 %#.8d<--\n\n", 0);
		ft_printf("-+.8o %-+.8d<--\n", 0);
		printf("-+.8o %-+.8d<--\n\n", 0);
		ft_printf("-.8o %-.8d<--\n", 0);
		printf("-.8o %-.8d<--\n\n", 0);
		ft_printf(".8 %.8d<--\n", 0);
		printf(".8 %.8d<--\n\n", 0);
		ft_putendl("/");
		ft_printf("#-+.1o %#-+.1d<--\n", 0);
		printf("#-+.1o %#-+.1d<--\n\n", 0);
		ft_printf("#-+.2o %#-+.2d<--\n", 0);
		printf("#-+.2o %#-+.2d<--\n\n", 0);
		ft_printf("#-+.1o %#-+.1d<--\n", 0);
		printf("#-+.1o %#-+.1d<--\n\n", 0);
		ft_printf("#-.8o %#-.8d<--\n", 0);
		printf("#-.8o %#-.8d<--\n\n", 0);
		ft_printf("#.8 %#.8d<--\n", 0);
		printf("#.8 %#.8d<--\n\n", 0);
		ft_printf("-+.8o %-+.8d<--\n", 0);
		printf("-+.8o %-+.8d<--\n\n", 0);
		ft_printf("-.8o %-.8d<--\n", 0);
		printf("-.8o %-.8d<--\n\n", 0);
		ft_printf(".8 %.8d<--\n", 0);
		printf(".8 %.8d<--\n\n", 0);
		ft_putendl("OK");
		ft_printf("%#-+.d<--\n", 0);
		printf("%#-+.d<--\n\n", 0);
		ft_printf("%#- .d<--\n", 0);
		printf("%#- .d<--\n\n", 0);
		ft_printf("%#-.d<--\n", 0);
		printf("%#-.d<--\n\n", 0);
		ft_printf("%#.d<--\n", 0);
		printf("%#.d<--\n\n", 0);
		ft_printf("%.d<--\n", 0);
		printf("%.d<--\n\n", 0);
		ft_putendl("OK");
		ft_printf("%#-+10.0d<--\n", 0);
		printf("%#-+10.0d<--\n\n", 0);
		ft_printf("%#-+10.0d<--\n", 0);
		printf("%#-+10.0d<--\n\n", 0);
		ft_printf("%#10.0d<--\n", 0);
		printf("%#10.0d<--\n\n", 0);

		ft_printf("%#10.5lld<--\n", ULLONG_MAX);
		printf("%#10.5lld<--\n\n", ULLONG_MAX);

		ft_printf("%#10.5lld<--\n", LLONG_MIN);
		printf("%#10.5lld<--\n\n", LLONG_MIN);

		ft_printf("%#10.25ld<--\n", LONG_MAX);
		printf("%#10.25ld<--\n\n", LONG_MAX);

		ft_printf("%#10.25ld<--\n", LONG_MAX - 150);
		printf("%#10.25ld<--\n\n", LONG_MAX - 150);

		ft_printf("%#10.25ld<--\n", LONG_MAX - 10000);
		printf("%#10.25ld<--\n\n", LONG_MAX - 10000);

		ft_printf("%#10.5d<--\n", INT_MAX);
		printf("%#10.5d<--\n\n", INT_MAX);

		ft_printf("%#10.5lld<--\n", LLONG_MAX);
		printf("%#10.5lld<--\n\n", LLONG_MAX);

		ft_printf("%#10.5d<--\n", -1);
		printf("%#10.5d<--\n\n", -1);
		ft_printf("%#10.5d<--\n", -10);
		printf("%#10.5d<--\n\n", -10);
		ft_printf("%#10.5d<--\n", -100);
		printf("%#10.5d<--\n\n", -100);
		ft_printf("%#10.5d<--\n", -1000);
		printf("%#10.5d<--\n\n", -1000);
		ft_printf("%#10.5d<--\n", -10000);
		printf("%#10.5d<--\n\n", -10000);
		ft_printf("%#10.5d<--\n", -42);
		printf("%#10.5d<--\n\n", -42);

		ft_printf("%#10.5lld<--\n", ULLONG_MAX);
		printf("%#10.5lld<--\n\n", ULLONG_MAX);

		char *str = "Hello";
		ft_putendl("--String--");
		ft_printf("%10.2s<--\n", "Hello");
		printf("%10.2s<--\n\n", "Hello");

		ft_putendl("x.x");
		ft_printf("%10.10s<--\n", str);
		printf("%10.10s<--\n\n", str);
		ft_printf("%2.10s<--\n", str);
		printf("%2.10s<--\n\n", str);
		ft_printf("%2.10s<--\n", str);
		printf("%2.10s<--\n\n", str);
		ft_printf("%1.10s<--\n", str);
		printf("%1.10s<--\n\n", str);

		ft_printf("%10.5s<--\n", str);
		printf("%10.5s<--\n\n", str);

		ft_printf("%10.2s<--\n", str);
		printf("%10.2s<--\n\n", str);
		ft_printf("%10.1s<--\n", str); //
		printf("%10.1s<--\n\n", str); //
		ft_printf("%10.1s<--\n", str); //
		printf("%10.1s<--\n\n", str); //
		ft_printf("%10.1s<--\n", str); //
		printf("%10.1s<--\n\n", str); //
		ft_printf("%10.3s<--\n", str); //
		printf("%10.3s<--\n\n", str); //
		ft_printf("%10.0s<--\n", str); //
		printf("%10.0s<--\n\n", str); //
		ft_printf("%10.1s<--\n", str); //
		printf("%10.1s<--\n\n", str); //
		ft_printf("%10.s<--\n", str); //
		printf("%10.s<--\n\n", str); //
		ft_printf("%10.0s<--\n", str); //
		printf("%10.0s<--\n\n", str); //

	//	ft_printf("%2.10lls<--\n", INT_MIN);
	//	printf("%2.10lls<--\n\n", INT_MIN);


		ft_printf("%10.15s<--\n", str);
		printf("%10.15s<--\n\n", str);

		ft_printf("%10.15s<--\n", str);
		printf("%10.15s<--\n\n", str);

		ft_printf("%10.0s<--\n", str);
		printf("%10.0s<--\n\n", str);

		ft_printf("%10.0s<--\n", str); //
		printf("%10.0s<--\n\n", str);

		ft_printf("%10.1s<--\n", str);
		printf("%10.1s<--\n\n", str);

		ft_printf("%#10.10s<--\n", str);
		printf("%#10.10s<--\n\n", str);
		ft_printf("% 10.10s<--\n", str);
		printf("% 10.10s<--\n\n", str);
		ft_printf("%+10.10s<--\n", str);
		printf("%+10.10s<--\n\n", str);
		ft_printf("%-10.10s<--\n", str);
		printf("%-10.10s<--\n\n", str);

		ft_putendl("x");
		ft_printf("%10s<--\n", str);
		printf("%10s<--\n\n", str);
		ft_printf("%2s<--\n", str);
		printf("%2s<--\n\n", str);
		ft_printf("%1s<--\n", str);
		printf("%1s<--\n\n", str);
		ft_printf("%3s<--\n", str);
		printf("%3s<--\n\n", str);
		ft_printf("%4s<--\n", str);
		printf("%4s<--\n\n", str);
		ft_printf("%2s<--\n", str);
		printf("%2s<--\n\n", str);
		ft_printf("%2s<--\n", str);
		printf("%2s<--\n\n", str);
		ft_printf("%1s<--\n", str);
		printf("%1s<--\n\n", str);
		ft_printf("%10s<--\n", str);
		printf("%10s<--\n\n", str);
		ft_printf("%10s<--\n", str);
		printf("%10s<--\n\n", str);

		ft_printf("%15s<--\n", str);
		printf("%15s<--\n\n", str);
		ft_printf("%1s<--\n", str);
		printf("%1s<--\n\n", str);

		ft_printf("%30s<--\n", str);
		printf("%30s<--\n\n", str);
		ft_printf("%50s<--\n", str);
		printf("%50s<--\n\n", str);
		ft_printf("%1s<--\n", str);
		printf("%1s<--\n\n", str);
		ft_printf("%2s<--\n", str);
		printf("%2s<--\n\n", str);
		ft_printf("%2s<--\n", str);
		printf("%2s<--\n\n", str);
		ft_printf("%4s<--\n", str);
		printf("%4s<--\n\n", str);

		ft_printf("%10s<--\n", str);
		printf("%10s<--\n\n", str);
		ft_printf("%10s<--\n", str);
		printf("%10s<--\n\n", str);
		ft_printf("%10s<--\n", str);
		printf("%10s<--\n\n", str);
		ft_printf("%10s<--\n", str);
		printf("%10s<--\n\n", str);
		ft_printf("%10s<--\n", str);
		printf("%10s<--\n\n", str);
		ft_printf("%10s<--\n", str);
		printf("%10s<--\n\n", str);

		ft_printf("%10s<--\n", str);
		printf("%10s<--\n\n", str);

		ft_printf("%#10s<--\n", str);
		printf("%#10s<--\n\n", str);
		ft_printf("% 10s<--\n", str);
		printf("% 10s<--\n\n", str);
		ft_printf("%+10s<--\n", str);
		printf("%+10s<--\n\n", str);

		ft_printf("%.25s<--\n", str);
		printf("%.25s<--\n\n", str);
		ft_printf("%.25s<--\n", str);
		printf("%.25s<--\n\n", str);
		ft_printf("%.25s<--\n", str);
		printf("%.25s<--\n\n", str);
		ft_printf("%.s<--\n", str);
		printf("%.s<--\n\n", str);
		ft_printf("%.1s<--\n", str);
		printf("%.1s<--\n\n", str);
		ft_printf("%.0s<--\n", str);
		printf("%.0s<--\n\n", str);
		ft_printf("%.1s<--\n", str);
		printf("%.1s<--\n\n", str);
		ft_printf("%.10s<--\n", str);
		printf("%.10s<--\n\n", str);
		ft_printf("%.2s<--\n", str);
		printf("%.2s<--\n\n", str);
		ft_printf("%.3s<--\n", str);
		printf("%.3s<--\n\n", str);
		ft_printf("%.15s<--\n", str);
		printf("%.15s<--\n\n", str);

			printf("-->###<--\n\n");

			ft_printf("-->Width_Precision<--\n\n");
			ft_printf("%#10.10s<--\n", 42);
			printf("%#10.10s<--\n\n", 42);

			ft_printf("%#10.10s<--\n", 4242);
			printf("%#10.10s<--\n\n", 4242);

			ft_printf("%#10.15s<--\n", 0);
			printf("%#10.15s<--\n\n", 0);

			ft_printf("%#10.8s<--\n", 42);
			printf("%#10.8s<--\n\n", 42);

			ft_printf("%#10.8s<--\n", 20);
			printf("%#10.8s<--\n\n", 20);

			ft_printf("%#10.4s<--\n", 20);
			printf("%#10.4s<--\n\n", 20);

			ft_printf("%#10.6s<--\n", 120);
			printf("%#10.6s<--\n\n", 120);

			ft_printf("%#10.8s<--\n", 1200);
			printf("%#10.8s<--\n\n", 1200);

			ft_printf("%#10.1s<--\n", 120);
			printf("%#10.1s<--\n\n", 120);

			ft_printf("%#10.6s<--\n", 242);
			printf("%#10.6s<--\n\n", 242);

			ft_printf("%#10.6s<--\n", 4242);
			printf("%#10.6s<--\n\n", 4242);

			ft_printf("%#10.2s<--\n", 4242);
			printf("%#10.2s<--\n\n", 4242);

			ft_printf("%#10.0s<--\n", 4242);
			printf("%#10.0s<--\n\n", 4242);

			ft_printf("%#10.5s<--\n", 4242);
			printf("%#10.5s<--\n\n", 4242);

			ft_printf("%#10.2s<--\n", 20);
			printf("%#10.2s<--\n\n", 20);

			ft_putendl("ok");
			ft_printf("%#10.2s<--\n", 0);
			printf("%#10.2s<--\n\n", 0);

			ft_printf("%#10.4s<--\n", 0);
			printf("%#10.4s<--\n\n", 0);

			ft_printf("%10.2s<--\n", 0);
			printf("%10.2s<--\n\n", 0);
			ft_printf("%.2s<--\n", 0);
			printf("%.2s<--\n\n", 0);
			ft_printf("%10s<--\n", 0);
			printf("%10s<--\n\n", 0);
			ft_printf("%#10.5s<--\n", ULLONG_MAX);
			printf("%#10.5s<--\n\n", ULLONG_MAX);
			ft_printf("%10.5s<--\n", LLONG_MAX);
			printf("%10.5s<--\n\n", LLONG_MAX);

			ft_printf("%#10.12s<--\n", 20);
			printf("%#10.12s<--\n\n", 20);
			ft_printf("%#10.12s<--\n", 120);
			printf("%#10.12s<--\n\n", 120);
			ft_printf("%#10.12s<--\n", 20);
			printf("%#10.12s<--\n\n", 20);

			ft_printf("%#10.12s<--\n", 0);
			printf("%#10.12s<--\n\n", 0);

			ft_printf("-->Width<--\n\n");
			ft_printf("%#10s<--\n", 42);
			printf("%#10s<--\n\n", 42);
			ft_printf("%#10s<--\n", 142);
			printf("%#10s<--\n\n", 142);
			ft_printf("%#10s<--\n", 14200);
			printf("%#10s<--\n\n", 14200);
			ft_printf("%#10s<--\n", 42);
			printf("%#10s<--\n\n", 42);
			ft_printf("%#10s<--\n", 142);
			printf("%#10s<--\n\n", 142);
			ft_printf("%#10s<--\n", 20);
			printf("%#10s<--\n\n", 20);
			ft_printf("%#10s<--\n", 0);
			printf("%#10s<--\n\n", 0);
			ft_printf("%#1s<--\n", 42);
			printf("%#1s<--\n\n", 42);

			ft_printf("-->Precision<--\n\n");
			ft_printf("%#.8s<--\n", 42);
			printf("%#.8s<--\n\n", 42);

			ft_printf("%#.8s<--\n", 142);
			printf("%#.8s<--\n\n", 142);

			ft_printf("%#.8s<--\n", 42);
			printf("%#.8s<--\n\n", 42);

			ft_printf("%#.2s<--\n", 142);
			printf("%#.2s<--\n\n", 142);

			ft_printf("%#.8s<--\n", 0);
			printf("%#.8s<--\n\n", 0);

			ft_printf("%#10.5lls<--\n", ULLONG_MAX);
			printf("%#10.5lls<--\n\n", ULLONG_MAX);
			ft_printf("%10.5lls<--\n", LLONG_MAX);
			printf("%10.5lls<--\n\n", LLONG_MAX);


			printf("-->---<--\n\n");

			ft_printf("-->Width_Precision<--\n\n");
			ft_printf("%-10.10s<--\n", str);
			printf("%-10.10s<--\n\n", str);
			ft_printf("%-10.8s<--\n", str);
			printf("%-10.8s<--\n\n", str);
			ft_printf("%-10.15s<--\n", str);
			printf("%-10.15s<--\n\n", str);
			ft_printf("%-10.8s<--\n", str);
			printf("%-10.8s<--\n\n", str);
			ft_printf("%-10.8s<--\n", str);
			printf("%-10.8s<--\n\n", str);
			ft_printf("%-10.6s<--\n", str);
			printf("%-10.6s<--\n\n", str);
			ft_printf("%-10.6s<--\n", str);
			printf("%-10.6s<--\n\n", str);
			ft_printf("%-10.6s<--\n", str);
			printf("%-10.6s<--\n\n", str);
			ft_printf("%-10.2s<--\n", str);
			printf("%-10.2s<--\n\n", str);

			ft_printf("%-10.2s<--\n", str);
			printf("%-10.2s<--\n\n", str);

			ft_printf("%-10.4s<--\n", str);
			printf("%-10.4s<--\n\n", str);

			ft_printf("%10.2s<--\n", str);
			printf("%10.2s<--\n\n", str);
			ft_printf("%-10.5s<--\n", str);
			printf("%-10.5s<--\n\n", str);
			ft_printf("%-10.2s<--\n", str);
			printf("%-10.2s<--\n\n", str);
			ft_printf("%-10.1s<--\n", str);
			printf("%-10.1s<--\n\n", str);
			ft_printf("%-10.0s<--\n", str);
			printf("%-10.0s<--\n\n", str);
		//			ft_printf("%10.5s<--\n", LLONG_MAX);
		//			printf("%10.5s<--\n\n", LLONG_MAX);

			ft_printf("%-10.12s<--\n", str);
			printf("%-10.12s<--\n\n", str);
			ft_printf("%-10.12s<--\n", str);
			printf("%-10.12s<--\n\n", str);
			ft_printf("%-10.12s<--\n", str);
			printf("%-10.12s<--\n\n", str);

			ft_printf("%-10.12s<--\n", str);
			printf("%-10.12s<--\n\n", str);

			ft_printf("%-10.7s<--\n", str);
			printf("%-10.7s<--\n\n", str);
			ft_printf("%-10.1s<--\n", str);
			printf("%-10.1s<--\n\n", str);
			ft_printf("%-10.1s<--\n", str);
			printf("%-10.1s<--\n\n", str);
			ft_printf("%-10.2s<--\n", str);
			printf("%-10.2s<--\n\n", str);
			ft_printf("%-10.2s<--\n", str);
			printf("%-10.2s<--\n\n", str);

			ft_printf("-->Width<--\n\n");
			ft_printf("%-10s<--\n", str);
			printf("%-10s<--\n\n", str);
			ft_printf("%-10s<--\n", str);
			printf("%-10s<--\n\n", str);
			ft_printf("%-10s<--\n", str);
			printf("%-10s<--\n\n", str);
			ft_printf("%-10s<--\n", str);
			printf("%-10s<--\n\n", str);
			ft_printf("%-10s<--\n", str);
			printf("%-10s<--\n\n", str);
			ft_printf("%-10s<--\n", str);
			printf("%-10s<--\n\n", str);
			ft_printf("%-10s<--\n", str);
			printf("%-10s<--\n\n", str);
			ft_printf("%-10s<--\n", str);
			printf("%-10s<--\n\n", str);
			ft_printf("%-1s<--\n", str);
			printf("%-1s<--\n\n", str);
			ft_printf("%-2s<--\n", str);
			printf("%-2s<--\n\n", str);
			ft_printf("%-4s<--\n", str);
			printf("%-4s<--\n\n", str);
			ft_printf("%-1s<--\n", str);
			printf("%-1s<--\n\n", str);

			ft_printf("%#10.5lls<--\n", str);
			printf("%#10.5lls<--\n\n", str);
			ft_printf("%10.5lls<--\n", str);
			printf("%10.5lls<--\n\n", str);

			ft_printf("-->Precision<--\n\n");
			ft_printf("%-.8s<--\n", str);
			printf("%-.8s<--\n\n", str);
			ft_printf("%-.8s<--\n", str);
			printf("%-.8s<--\n\n", str);
			ft_printf("%-.8s<--\n", str);
			printf("%-.8s<--\n\n", str);
			ft_printf("%-.2s<--\n", str);
			printf("%-.2s<--\n\n", str);
			ft_printf("%-.8s<--\n", str);
			printf("%-.8s<--\n\n", str);
			ft_printf("%-.s<--\n", str);
			printf("%-.s<--\n\n", str);
			ft_printf("%-.0s<--\n", str);
			printf("%-.0s<--\n\n", str);
			ft_printf("%.s<--\n", str);
			printf("%.s<--\n\n", str);
			ft_printf("%-.1s<--\n", str);
			printf("%-.1s<--\n\n", str);
			ft_printf("%-.3s<--\n", str);
			printf("%-.3s<--\n\n", str);
			ft_printf("%-.4s<--\n", str);
			printf("%-.4s<--\n\n", str);

			printf("-->   <--\n\n");

			ft_printf("-->Width_Precision<--\n\n");
			ft_printf("% 10.10s<--\n", 42);
			printf("% 10.10s<--\n\n", 42);
			ft_printf("% 10.8s<--\n", 42);
			printf("% 10.8s<--\n\n", 42);
			ft_printf("% 10.15s<--\n", 0);
			printf("% 10.15s<--\n\n", 0);
			ft_printf("% 10.8s<--\n", 20);
			printf("% 10.8s<--\n\n", 20);
			ft_printf("% 10.8s<--\n", 20);
			printf("% 10.8s<--\n\n", 20);
			ft_printf("% 10.6s<--\n", 120);
			printf("% 10.6s<--\n\n", 120);
			ft_printf("% 10.2s<--\n", 20);
			printf("% 10.2s<--\n\n", 20);

			ft_printf("% 10.2s<--\n", 0);
			printf("% 10.2s<--\n\n", 0);

			ft_printf("% 10.4s<--\n", 0);
			printf("% 10.4s<--\n\n", 0);

			//			ft_printf("%10.2s<--\n", 0);
			//			printf("%10.2s<--\n\n", 0);
			ft_printf("% 10.5s<--\n", ULLONG_MAX);
			printf("% 10.5s<--\n\n", ULLONG_MAX);
			ft_printf("% 10.2s<--\n", 100000);
			printf("% 10.2s<--\n\n", 100000);
			ft_printf("% 10.1s<--\n", 100);
			printf("% 10.1s<--\n\n", 100);
			ft_printf("% 10.0s<--\n", 10);
			printf("% 10.0s<--\n\n", 10);
			//			ft_printf("%10.5s<--\n", LLONG_MAX);
			//			printf("%10.5s<--\n\n", LLONG_MAX);

			ft_printf("% 10.12s<--\n", 20);
			printf("% 10.12s<--\n\n", 20);
			ft_printf("% 10.12s<--\n", 120);
			printf("% 10.12s<--\n\n", 120);
			ft_printf("% 10.12s<--\n", 20);
			printf("% 10.12s<--\n\n", 20);

			ft_printf("% 10.12s<--\n", 0);
			printf("% 10.12s<--\n\n", 0);

			ft_printf("-->Width<--\n\n");
			ft_printf("% 10s<--\n", 42);
			printf("% 10s<--\n\n", 42);
			ft_printf("% 10s<--\n", -142);
			printf("% 10s<--\n\n", -142);
			ft_printf("% 10s<--\n", 142);
			printf("% 10s<--\n\n", 142);
			ft_printf("% 10s<--\n", 14200);
			printf("% 10s<--\n\n", 14200);
			ft_printf("% 10s<--\n", 42);
			printf("% 10s<--\n\n", 42);
			ft_printf("% 10s<--\n", 142);
			printf("% 10s<--\n\n", 142);
			ft_printf("% 10s<--\n", 20);
			printf("% 10s<--\n\n", 20);
			ft_printf("% 10s<--\n", 0);
			printf("% 10s<--\n\n", 0);
			ft_printf("% 1s<--\n", 42);
			printf("% 1s<--\n\n", 42);

			ft_printf("-->Precision<--\n\n");
			ft_printf("% .8s<--\n", 42);
			printf("% .8s<--\n\n", 42);
			ft_printf("% .8s<--\n", 142);
			printf("% .8s<--\n\n", 142);
			ft_printf("% .8s<--\n", 42);
			printf("% .8s<--\n\n", 42);
			ft_printf("% .2s<--\n", 142);
			printf("% .2s<--\n\n", 142);
			ft_printf("% .8s<--\n", 0);
			printf("% .8s<--\n\n", 0);

		ft_printf("-->##--x--##<--\n\n");

		ft_printf("-->Width_Precision<--\n\n");
		ft_printf("%#-10.12s<--\n", 42);
		printf("%#-10.12s<--\n\n", 42);
		ft_printf("%#-10.10s<--\n", 42);
		printf("%#-10.10s<--\n\n", 42);
		ft_printf("%#-10.8s<--\n", 42);
		printf("%#-10.8s<--\n\n", 42);
		ft_printf("%#-10.15s<--\n", 0);
		printf("%#-10.15s<--\n\n", 0);

		ft_printf("%#-10.12s<--\n", -142);
		printf("%#-10.12s<--\n\n", -142);
		ft_printf("%#-10.10s<--\n", -142);
		printf("%#-10.10s<--\n\n", -142);
		ft_printf("%#-10.8s<--\n", -142);
		printf("%#-10.8s<--\n\n", -142);
		ft_printf("%#-10.2s<--\n", -10);
		printf("%#-10.2s<--\n\n", -10);
		ft_printf("%#-10.s<--\n", -10);
		printf("%#-10.s<--\n\n", -10);

		ft_printf("%#-10.8s<--\n", 20);
		printf("%#-10.8s<--\n\n", 20);
		ft_printf("%#-10.8s<--\n", 20);
		printf("%#-10.8s<--\n\n", 20);
		ft_printf("%#-10.6s<--\n", 120);
		printf("%#-10.6s<--\n\n", 120);
		ft_printf("%#-10.2s<--\n", 20);
		printf("%#-10.2s<--\n\n", 20);

		ft_printf("%#-10.1s<--\n", 120);
		printf("%#-10.1s<--\n\n", 120);
		ft_printf("%#-10.1s<--\n", 20);
		printf("%#-10.1s<--\n\n", 20);

		ft_printf("%#10.12s<--\n", 20);
		printf("%#10.12s<--\n\n", 20);
		ft_printf("%#10.12s<--\n", 120);
		printf("%#10.12s<--\n\n", 120);
		ft_printf("%#10.12s<--\n", 20);
		printf("%#10.12s<--\n\n", 20);

		ft_printf("%#10.12s<--\n", 0);
		printf("%#10.12s<--\n\n", 0);

		ft_printf("%#-10.2s<--\n", 0);
		printf("%#-10.2s<--\n\n", 0);
		ft_printf("%#-10.0s<--\n", 0);
		printf("%#-10.0s<--\n\n", 0);
		ft_printf("%#-10.1s<--\n", 0);
		printf("%#-10.1s<--\n\n", 0);
		//	ft_printf("%-10.2s<--\n", 0);
		//	printf("%-10.2s<--\n\n", 0);
		//	ft_printf("%#10.2s<--\n", 0);
		//	printf("%#10.2s<--\n\n", 0);

		ft_printf("%#-10.12s<--\n", 20);
		printf("%#-10.12s<--\n\n", 20);
		ft_printf("%#-10.12s<--\n", 120);
		printf("%#-10.12s<--\n\n", 120);
		ft_printf("%#-10.13s<--\n", 1200);
		printf("%#-10.13s<--\n\n", 1200);
		ft_printf("%#-10.12s<--\n", 1200);
		printf("%#-10.12s<--\n\n", 1200);
		ft_printf("%#-10.12s<--\n", 20);
		printf("%#-10.12s<--\n\n", 20);
		ft_printf("%#-10.12s<--\n", 0);
		printf("%#-10.12s<--\n\n", 0);

		ft_printf("%10.1s<--\n", 0);
		printf("%10.1s<--\n\n", 0);

		ft_printf("%10.2s<--\n", 16);
		printf("%10.2s<--\n\n", 16);

		ft_printf("%10.s<--\n", 0);
		printf("%10.s<--\n\n", 0);

		ft_printf("-->Precision<--\n\n");
		ft_printf("%#-.8s<--\n", 42);
		printf("%#-.8s<--\n\n", 42);
		ft_printf("%#-.8s<--\n", 142);
		printf("%#-.8s<--\n\n", 142);
		ft_printf("%#-.8s<--\n", 42);
		printf("%#-.8s<--\n\n", 42);
		ft_printf("%#-.2s<--\n", 142);
		printf("%#-.2s<--\n\n", 142);
		ft_printf("%#-.8s<--\n", 0);
		printf("%#-.8s<--\n\n", 0);

		ft_printf("-->Width<--\n\n");
		ft_printf("%#-10s<--\n", 42);
		printf("%#-10s<--\n\n", 42);
		ft_printf("%#-10s<--\n", 142);
		printf("%#-10s<--\n\n", 142);
		ft_printf("%#-10s<--\n", 42);
		printf("%#-10s<--\n\n", 42);
		ft_printf("%#-10s<--\n", 142);
		printf("%#-10s<--\n\n", 142);
		ft_printf("%#-10s<--\n", 20);
		printf("%#-10s<--\n\n", 20);
		ft_printf("%#-10s<--\n", 0);
		printf("%#-10s<--\n\n", 0);
		ft_printf("%#-1s<--\n", 42);
		printf("%#-1s<--\n\n", 42);
		ft_printf("%#-1s<--\n", 424242);
		printf("%#-1s<--\n\n", 424242);
		ft_printf("%#-25s<--\n", 424242);
		printf("%#-25s<--\n\n", 424242);
		ft_printf("%#-7s<--\n", 424242);
		printf("%#-7s<--\n\n", 424242);
		ft_printf("%#-8s<--\n", 424242);
		printf("%#-8s<--\n\n", 424242);
		ft_printf("%#-s<--\n", 424242);
		printf("%#-s<--\n\n", 424242);
		ft_printf("-->Width<--\n\n");
		ft_printf("%-10s<--\n", 42);
		printf("%-10s<--\n\n", 42);
		ft_printf("%-10s<--\n", 142);
		printf("%-10s<--\n\n", 142);
		ft_printf("%-10s<--\n", 14200);
		printf("%-10s<--\n\n", 14200);
		ft_printf("%-10s<--\n", 42);
		printf("%-10s<--\n\n", 42);
		ft_printf("%-10s<--\n", 142);
		printf("%-10s<--\n\n", 142);
		ft_printf("%-10s<--\n", 20);
		printf("%-10s<--\n\n", 20);
		ft_printf("%-10s<--\n", 0);
		printf("%-10s<--\n\n", 0);
		ft_printf("%-1s<--\n", 42);
		printf("%-1s<--\n\n", 42);

		ft_printf("-->##--  x  --##<--\n\n");

		ft_printf("%#- 10.12s<--\n", str);
		printf("%#- 10.12s<--\n\n", str);

		ft_printf("-->Width_Precision<--\n\n");
		ft_printf("%#- 10.12s<--\n", str);
		printf("%#- 10.12s<--\n\n", str);
		ft_printf("%#- 10.10s<--\n", str);
		printf("%#- 10.10s<--\n\n", str);
		ft_printf("%#- 10.8s<--\n", str);
		printf("%#- 10.8s<--\n\n", str);
		ft_printf("%#- 10.15s<--\n", str);
		printf("%#- 10.15s<--\n\n", str);

		ft_printf("%#- 10.8s<--\n", 20);
		printf("%#- 10.8s<--\n\n", 20);
		ft_printf("%#- 10.8s<--\n", 20);
		printf("%#- 10.8s<--\n\n", 20);
		ft_printf("%#- 10.6s<--\n", 120);
		printf("%#- 10.6s<--\n\n", 120);
		ft_printf("%#- 10.2s<--\n", 20);
		printf("%#- 10.2s<--\n\n", 20);

		ft_printf("%#- 10.1s<--\n", 120);
		printf("%#- 10.1s<--\n\n", 120);
		ft_printf("%#- 10.1s<--\n", 20);
		printf("%#- 10.1s<--\n\n", 20);

		ft_printf("%#- 10.2s<--\n", 0);
		printf("%#- 10.2s<--\n\n", 0);
		ft_printf("%#-10.2s<--\n", 0);
		printf("%#-10.2s<--\n\n", 0);
		ft_printf("%- 10.2s<--\n", 0);
		printf("%- 10.2s<--\n\n", 0);
		ft_printf("%-010.2s<--\n", 0);
		printf("%-010.2s<--\n\n", 0);
		ft_printf("%#10.2s<--\n", 0);
		printf("%#10.2s<--\n\n", 0);

		ft_printf("%#- 10.12s<--\n", 20);
		printf("%#- 10.12s<--\n\n", 20);
		ft_printf("%#- 10.12s<--\n", 120);
		printf("%#- 10.12s<--\n\n", 120);
		ft_printf("%#- 10.12s<--\n", 20);
		printf("%#- 10.12s<--\n\n", 20);
		ft_printf("%#- 10.12s<--\n", 0);
		printf("%#- 10.12s<--\n\n", 0);
		ft_printf("%#- 10.0s<--\n", 0);
		printf("%#- 10.0s<--\n\n", 0);
		ft_printf("%#- 10.1s<--\n", 10);
		printf("%#- 10.1s<--\n\n", 10);


		ft_printf("-->Width<--\n\n");
		ft_printf("%#- 10s<--\n", 42);
		printf("%#- 10s<--\n\n", 42);
		ft_printf("%#- 10s<--\n", 142);
		printf("%#- 10s<--\n\n", 142);
		ft_printf("%#- 10s<--\n", 42);
		printf("%#- 10s<--\n\n", 42);
		ft_printf("%#- 10s<--\n", 142);
		printf("%#- 10s<--\n\n", 142);
		ft_printf("%#- 10s<--\n", 20);
		printf("%#- 10s<--\n\n", 20);
		ft_printf("%#- 10s<--\n", 0);
		printf("%#- 10s<--\n\n", 0);
		ft_printf("%#- 1s<--\n", 42);
		printf("%#- 1s<--\n\n", 42);

		ft_printf("-->Precision<--\n\n");
		ft_printf("%#- .8s<--\n", 42);
		printf("%#- .8s<--\n\n", 42);
		ft_printf("%#- .8s<--\n", 142);
		printf("%#- .8s<--\n\n", 142);
		ft_printf("%#- .8s<--\n", 42);
		printf("%#- .8s<--\n\n", 42);
		ft_printf("%#- .2s<--\n", 142);
		printf("%#- .2s<--\n\n", 142);
		ft_printf("%#- .1s<--\n", 42);
		printf("%#- .1s<--\n\n", 42);
		ft_printf("%#- .s<--\n", 42);
		printf("%#- .s<--\n\n", 42);
		ft_printf("%.s<--\n", 42);
		printf("%.s<--\n\n", 42);
		ft_printf("%#.s<--\n", 42);
		printf("%#.s<--\n\n", 42);
		ft_printf("%#- .0s<--\n", 42);
		printf("%#- .0s<--\n\n", 42);
		ft_printf("%#- .8s<--\n", 0);
		printf("%#- .8s<--\n\n", 0);

		ft_printf("-->##++x++##<--\n\n");

		ft_printf("-->Width_Precision<--\n\n");
		ft_printf("%#-+10.12s<--\n", str);
		printf("%#-+10.12s<--\n\n", str);

		ft_printf("%#-+10.10s<--\n", 42);
		printf("%#-+10.10s<--\n\n", 42);
		ft_printf("%#-+10.8s<--\n", 42);
		printf("%#-+10.8s<--\n\n", 42);
		ft_printf("%#-+10.15s<--\n", 0);
		printf("%#-+10.15s<--\n\n", 0);

		ft_printf("%#-+10.8s<--\n", 20);
		printf("%#-+10.8s<--\n\n", 20);
		ft_printf("%#-+10.8s<--\n", 20);
		printf("%#-+10.8s<--\n\n", 20);
		ft_printf("%#-+10.6s<--\n", 120);
		printf("%#-+10.6s<--\n\n", 120);
		ft_printf("%#-+10.2s<--\n", 20);
		printf("%#-+10.2s<--\n\n", 20);

		ft_printf("%#-+10.1s<--\n", 120);
		printf("%#-+10.1s<--\n\n", 120);
		ft_printf("%#-+10.1s<--\n", 20);
		printf("%#-+10.1s<--\n\n", 20);

		ft_printf("%#-+10.2s<--\n", 0);
		printf("%#-+10.2s<--\n\n", 0);
		ft_printf("%#-+10.2s<--\n", 0);
		printf("%#-+10.2s<--\n\n", 0);
		ft_printf("%-+10.2s<--\n", 0);
		printf("%-+10.2s<--\n\n", 0);
		ft_printf("%-010.2s<--\n", 0);
		printf("%-010.2s<--\n\n", 0);
		ft_printf("%#10.2s<--\n", 0);
		printf("%#10.2s<--\n\n", 0);

		ft_printf("%#-+10.12s<--\n", 20);
		printf("%#-+10.12s<--\n\n", 20);
		ft_printf("%#-+10.12s<--\n", 120);
		printf("%#-+10.12s<--\n\n", 120);
		ft_printf("%#-+10.12s<--\n", 20);
		printf("%#-+10.12s<--\n\n", 20);
		ft_printf("%#-+10.12s<--\n", 0);
		printf("%#-+10.12s<--\n\n", 0);

		ft_printf("-->Width<--\n\n");
		ft_printf("%#-+10s<--\n", 42);
		printf("%#-+10s<--\n\n", 42);
		ft_printf("%#-+1s<--\n", 42);
		printf("%#-+1s<--\n\n", 42);
		ft_printf("%#-+2s<--\n", 42);
		printf("%#-+2s<--\n\n", 42);
		ft_printf("%#-+3s<--\n", 42);
		printf("%#-+3s<--\n\n", 42);
		ft_printf("%#-+4s<--\n", 42);
		printf("%#-+4s<--\n\n", 42);
		ft_printf("%#-+10s<--\n", 142);
		printf("%#-+10s<--\n\n", 142);
		ft_printf("%#-+10s<--\n", 42);
		printf("%#-+10s<--\n\n", 42);
		ft_printf("%#-+2s<--\n", 142);
		printf("%#-+1s<--\n\n", 142);
		ft_printf("%#-+2s<--\n", 20);
		printf("%#-+2s<--\n\n", 20);
		ft_printf("%#-+1s<--\n", 0);
		printf("%#-+1s<--\n\n", 0);
		ft_printf("%#-+1s<--\n", 42);
		printf("%#-+1s<--\n\n", 42);

		ft_printf("-->Precision<--\n\n");
		ft_printf("%#-+.8s<--\n", 42);
		printf("%#-+.8s<--\n\n", 42);
		ft_printf("%#-+.0s<--\n", 42);
		printf("%#-+.0s<--\n\n", 42);
		ft_printf("%#-+.s<--\n", 0);
		printf("%#-+.s<--\n\n", 0);
		ft_printf("%#-+.1s<--\n", 0);
		printf("%#-+.1s<--\n\n", 0);
		ft_printf("%#-+.8s<--\n", 142);
		printf("%#-+.8s<--\n\n", 142);
		ft_printf("%#-+.8s<--\n", 42);
		printf("%#-+.8s<--\n\n", 42);
		ft_printf("%#-+.2s<--\n", 142);
		printf("%#-+.2s<--\n\n", 142);
		ft_printf("%#-+.1s<--\n", 42);
		printf("%#-+.1s<--\n\n", 42);
		ft_printf("%#-+.s<--\n", 42);
		printf("%#-+.s<--\n\n", 42);
		ft_printf("%+.s<--\n", 42);
		printf("%+.s<--\n\n", 42);
		ft_printf("%#.s<--\n", 42);
		printf("%#.s<--\n\n", 42);
		ft_printf("%#-+.0s<--\n", 42);
		printf("%#-+.0s<--\n\n", 42);
		ft_printf("%#-+.8s<--\n", 0);
		printf("%#-+.8s<--\n\n", 0);

		ft_printf("%-.0s<--\n", 0);
		printf("%-.0s<--\n\n", 0);
		ft_printf("%-.0s<--\n", 0);
		printf("%-.0s<--\n\n", 0);
		ft_printf("%-.1s<--\n", 0);
		printf("%-.1s<--\n\n", 0);
		ft_printf("%10.0s<--\n", 0);
		printf("%10.0s<--\n\n", 0);
		ft_printf("%1.0s<--\n", 0);
		printf("%1.0s<--\n\n", 0);

		ft_printf("%#10.5lls<--\n", ULLONG_MAX);
		printf("%#10.5lls<--\n\n", ULLONG_MAX);

		ft_printf("%#10.5lls<--\n", LLONG_MIN);
		printf("%#10.5lls<--\n\n", LLONG_MIN);

		ft_printf("%#10.5ls<--\n", LONG_MAX);
		printf("%#10.5ls<--\n\n", LONG_MAX);

		ft_printf("%#10.5s<--\n", INT_MAX);
		printf("%#10.5s<--\n\n", INT_MAX);

		ft_putendl("Ok");
		ft_printf("%#10.5s<--\n", 42);
		printf("%#10.5s<--\n\n", 42);

		ft_printf("#10.0x %#10.0s<--\n", 42);
		printf("#10.0x %#10.0s<--\n\n", 42);

		ft_printf("#10.1x %#10.1s<--\n", 42);
		printf("#10.1x %#10.1s<--\n\n", 42);

		ft_printf("10.0x %10.0s<--\n", 42);
		printf("10.0x %10.0s<--\n\n", 42);

		ft_printf("10.1x %10.1s<--\n", 42);
		printf("10.1x %10.1s<--\n\n", 42);

		ft_printf("%#10.2s<--\n", 20);
		printf("%#10.2s<--\n\n", 20);

		ft_printf("%10.5s<--\n", LLONG_MAX);
		printf("%10.5s<--\n\n", LLONG_MAX);

		ft_printf("%lls<--\n", ULLONG_MAX);
		printf("%lls<--\n", ULLONG_MAX);

		ft_printf("%#-+.0s<--\n", 0);
		printf("%#-+.0s<--\n\n", 0);
		ft_printf("%#-+.0s<--\n", 0);
		printf("%#-+.0s<--\n\n", 0);
		ft_printf("%#.0s<--\n", 0);
		printf("%#.0s<--\n\n", 0);

		ft_putendl("OK");
		ft_printf("%#-+.1s<--\n", 0);
		printf("%#-+.1s<--\n\n", 0);
		ft_printf("%#-+.s<--\n", 0);
		printf("%#-+.s<--\n\n", 0);
		ft_printf("%#- .1s<--\n", 0);
		printf("%#- .1s<--\n\n", 0);
		ft_printf("%#-.1s<--\n", 0);
		printf("%#-.1s<--\n\n", 0);
		ft_printf("%#.1s<--\n", 0);
		printf("%#.1s<--\n\n", 0);
		ft_printf("%.1s<--\n", 0);
		printf("%.1s<--\n\n", 0);
		ft_printf("#-+.8o %#-+.8s<--\n", 0);
		printf("#-+.8o %#-+.8s<--\n\n", 0);
		ft_printf("#-.8o %#-.8s<--\n", 0);
		printf("#-.8o %#-.8s<--\n\n", 0);
		ft_printf("#.8 %#.8s<--\n", 0);
		printf("#.8 %#.8s<--\n\n", 0);
		ft_printf("-+.8o %-+.8s<--\n", 0);
		printf("-+.8o %-+.8s<--\n\n", 0);
		ft_printf("-.8o %-.8s<--\n", 0);
		printf("-.8o %-.8s<--\n\n", 0);
		ft_printf(".8 %.8s<--\n", 0);
		printf(".8 %.8s<--\n\n", 0);
		ft_putendl("/");
		ft_printf("#-+.1o %#-+.1s<--\n", 0);
		printf("#-+.1o %#-+.1s<--\n\n", 0);
		ft_printf("#-+.2o %#-+.2s<--\n", 0);
		printf("#-+.2o %#-+.2s<--\n\n", 0);
		ft_printf("#-+.1o %#-+.1s<--\n", 0);
		printf("#-+.1o %#-+.1s<--\n\n", 0);
		ft_printf("#-.8o %#-.8s<--\n", 0);
		printf("#-.8o %#-.8s<--\n\n", 0);
		ft_printf("#.8 %#.8s<--\n", 0);
		printf("#.8 %#.8s<--\n\n", 0);
		ft_printf("-+.8o %-+.8s<--\n", 0);
		printf("-+.8o %-+.8s<--\n\n", 0);
		ft_printf("-.8o %-.8s<--\n", 0);
		printf("-.8o %-.8s<--\n\n", 0);
		ft_printf(".8 %.8s<--\n", 0);
		printf(".8 %.8s<--\n\n", 0);
		ft_putendl("OK");
		ft_printf("%#-+.s<--\n", 0);
		printf("%#-+.s<--\n\n", 0);
		ft_printf("%#- .s<--\n", 0);
		printf("%#- .s<--\n\n", 0);
		ft_printf("%#-.s<--\n", 0);
		printf("%#-.s<--\n\n", 0);
		ft_printf("%#.s<--\n", 0);
		printf("%#.s<--\n\n", 0);
		ft_printf("%.s<--\n", 0);
		printf("%.s<--\n\n", 0);
		ft_putendl("OK");
		ft_printf("%#-+10.0s<--\n", 0);
		printf("%#-+10.0s<--\n\n", 0);
		ft_printf("%#-+10.0s<--\n", 0);
		printf("%#-+10.0s<--\n\n", 0);
		ft_printf("%#10.0s<--\n", 0);
		printf("%#10.0s<--\n\n", 0);

		ft_printf("%#10.5lls<--\n", ULLONG_MAX);
		printf("%#10.5lls<--\n\n", ULLONG_MAX);

		ft_printf("%#10.5lls<--\n", LLONG_MIN);
		printf("%#10.5lls<--\n\n", LLONG_MIN);

		ft_printf("%#10.25ls<--\n", LONG_MAX);
		printf("%#10.25ls<--\n\n", LONG_MAX);

		ft_printf("%#10.25ls<--\n", LONG_MAX - 150);
		printf("%#10.25ls<--\n\n", LONG_MAX - 150);

		ft_printf("%#10.25ls<--\n", LONG_MAX - 10000);
		printf("%#10.25ls<--\n\n", LONG_MAX - 10000);

		ft_printf("%#10.5s<--\n", INT_MAX);
		printf("%#10.5s<--\n\n", INT_MAX);

		ft_printf("%#10.5lls<--\n", LLONG_MAX);
		printf("%#10.5lls<--\n\n", LLONG_MAX);

		ft_printf("%#10.5s<--\n", -1);
		printf("%#10.5s<--\n\n", -1);
		ft_printf("%#10.5s<--\n", -10);
		printf("%#10.5s<--\n\n", -10);
		ft_printf("%#10.5s<--\n", -100);
		printf("%#10.5s<--\n\n", -100);
		ft_printf("%#10.5s<--\n", -1000);
		printf("%#10.5s<--\n\n", -1000);
		ft_printf("%#10.5s<--\n", -10000);
		printf("%#10.5s<--\n\n", -10000);
		ft_printf("%#10.5s<--\n", -42);
		printf("%#10.5s<--\n\n", -42);

		ft_printf("%010.12s<--\n", str);
		printf("%010.12s<--\n\n", str);

		ft_printf("%030.6s<--\n", str);
		printf("%030.6s<--\n\n", str);

		ft_printf("% 30.6s<--\n", str);
		printf("% 30.6s<--\n\n", str);

		ft_printf("%030.2s<--\n", str);
		printf("%030.2s<--\n\n", str);

		ft_printf("% 30.2s<--\n", str);
		printf("% 30.2s<--\n\n", str);

		ft_printf("%0.6s<--\n", str);
		printf("%0.6s<--\n\n", str);

		ft_printf("%04.6s<--\n", str);
		printf("%04.6s<--\n\n", str);

		ft_printf("%4.2s<--\n", NULL);
		printf("%4.2s<--\n\n", NULL);

		ft_printf("%4.s<--\n", NULL);
		printf("%4.s<--\n\n", NULL);

		ft_printf("%10.3s<--\n", NULL);
		printf("%10.3s<--\n\n", NULL);

*/
/*		ft_printf("%010.3c<--\n", 0);
		printf("%010.3c<--\n\n", 0);

		ft_printf("%10.3c<--\n", 0);
		printf("%10.3c<--\n\n", 0);

				ft_putendl("Check char");
				ft_printf("%llc<--\n", ULLONG_MAX);
				printf("%llc<--\n\n", ULLONG_MAX);
				ft_printf("%llc<--\n", LLONG_MAX);
				printf("%llc<--\n\n", LLONG_MAX);
				ft_printf("%llc<--\n", LLONG_MAX);
				printf("%llc<--\n\n", LLONG_MAX);
				ft_printf("%lc<--\n", LONG_MAX);
				printf("%lc<--\n\n", LONG_MAX);
				ft_printf("%c<--\n", INT_MAX);
				printf("%c<--\n\n", INT_MAX);
				ft_printf("%c<--\n", 150150);
				printf("%c<--\n\n", 150150);
				ft_printf("%llc<--\n", LLONG_MIN);
				printf("%llc<--\n\n", LLONG_MIN);
				ft_printf("%llc<--\n", LLONG_MIN);
				printf("%llc<--\n\n", LLONG_MIN);
				ft_printf("%lc<--\n", LONG_MIN);
				printf("%lc<--\n\n", LONG_MIN);
				ft_printf("%c<--\n", INT_MIN);
				printf("%c<--\n\n", INT_MIN);
				ft_printf("%c<--\n", SHRT_MIN);
				printf("%c<--\n\n", SHRT_MIN);
				ft_printf("%c<--\n", -150150);
				printf("%c<--\n\n", -150150);

				ft_putendl("x.x");
				ft_printf("%10.10c<--\n", 20);
				printf("%10.10c<--\n\n", 20);
				ft_printf("%2.10c<--\n", -142);
				printf("%2.10c<--\n\n", -142);
				ft_printf("%2.10c<--\n", 142);
				printf("%2.10c<--\n\n", 142);
				ft_printf("%1.10c<--\n", 142);
				printf("%1.10c<--\n\n", 142);

				ft_printf("%10.5c<--\n", 20);
				printf("%10.5c<--\n\n", 20);

				ft_printf("%10.2c<--\n", 20);
				printf("%10.2c<--\n\n", 20);
				ft_printf("%10.1c<--\n", 20); //
				printf("%10.1c<--\n\n", 20); //
				ft_printf("%10.1c<--\n", 142); //
				printf("%10.1c<--\n\n", 142); //
				ft_printf("%10.1c<--\n", 1420); //
				printf("%10.1c<--\n\n", 1420); //
				ft_printf("%10.3c<--\n", 1420); //
				printf("%10.3c<--\n\n", 1420); //
				ft_printf("%10.0c<--\n", 42); //
				printf("%10.0c<--\n\n", 42); //
				ft_printf("%10.1c<--\n", 0); //
				printf("%10.1c<--\n\n", 0); //
				ft_printf("%10.c<--\n", 0); //
				printf("%10.c<--\n\n", 0); //
				ft_printf("%10.0c<--\n", 0); //
				printf("%10.0c<--\n\n", 0); //

			//	ft_printf("%2.10llc<--\n", INT_MIN);
			//	printf("%2.10llc<--\n\n", INT_MIN);


				ft_printf("%10.15c<--\n", 142);
				printf("%10.15c<--\n\n", 142);

				ft_printf("%10.15c<--\n", -142);
				printf("%10.15c<--\n\n", -142);

				ft_printf("%10.0c<--\n", 0);
				printf("%10.0c<--\n\n", 0);

				ft_printf("%10.0c<--\n", 1); //
				printf("%10.0c<--\n\n", 1);

				ft_printf("%10.1c<--\n", 0);
				printf("%10.1c<--\n\n", 0);

				ft_printf("%#10.10c<--\n", 0);
				printf("%#10.10c<--\n\n", 0);
				ft_printf("% 10.10c<--\n", 0);
				printf("% 10.10c<--\n\n", 0);
				ft_printf("%+10.10c<--\n", 0);
				printf("%+10.10c<--\n\n", 0);
				ft_printf("%-10.10c<--\n", 0);
				printf("%-10.10c<--\n\n", 0);

				ft_putendl("x");
				ft_printf("%10c<--\n", -20);
				printf("%10c<--\n\n", -20);
				ft_printf("%2c<--\n", -20);
				printf("%2c<--\n\n", -20);
				ft_printf("%1c<--\n", -20);
				printf("%1c<--\n\n", -20);
				ft_printf("%3c<--\n", -20);
				printf("%3c<--\n\n", -20);
				ft_printf("%4c<--\n", -20);
				printf("%4c<--\n\n", -20);
				ft_printf("%2c<--\n", -142);
				printf("%2c<--\n\n", -142);
				ft_printf("%2c<--\n", 142);
				printf("%2c<--\n\n", 142);
				ft_printf("%1c<--\n", 142);
				printf("%1c<--\n\n", 142);
				ft_printf("%10c<--\n", 20);
				printf("%10c<--\n\n", 20);
				ft_printf("%10c<--\n", 20);
				printf("%10c<--\n\n", 20);

				ft_printf("%15c<--\n", 142);
				printf("%15c<--\n\n", 142);
				ft_printf("%1c<--\n", 0);
				printf("%1c<--\n\n", 0);

				ft_printf("%30c<--\n", 1);
				printf("%30c<--\n\n", 1);
				ft_printf("%50c<--\n", 0);
				printf("%50c<--\n\n", 0);
				ft_printf("%1c<--\n", 0);
				printf("%1c<--\n\n", 0);
				ft_printf("%2c<--\n", 20);
				printf("%2c<--\n\n", 20);
				ft_printf("%2c<--\n", 200);
				printf("%2c<--\n\n", 200);
				ft_printf("%4c<--\n", 200);
				printf("%4c<--\n\n", 200);

				ft_printf("%10c<--\n", -20);
				printf("%10c<--\n\n", -20);
				ft_printf("%10c<--\n", -142);
				printf("%10c<--\n\n", -142);
				ft_printf("%10c<--\n", 20);
				printf("%10c<--\n\n", 20);
				ft_printf("%10c<--\n", 142);
				printf("%10c<--\n\n", 142);
				ft_printf("%10c<--\n", 0);
				printf("%10c<--\n\n", 0);
				ft_printf("%10c<--\n", -1);
				printf("%10c<--\n\n", -1);

				ft_printf("%10c<--\n", -150);
				printf("%10c<--\n\n", -150);

				ft_printf("%#10c<--\n", -150);
				printf("%#10c<--\n\n", -150);
				ft_printf("% 10c<--\n", -150);
				printf("% 10c<--\n\n", -150);
				ft_printf("%+10c<--\n", -150);
				printf("%+10c<--\n\n", -150);

				ft_printf("%.25c<--\n", -20);
				printf("%.25c<--\n\n", -20);
				ft_printf("%.25c<--\n", 20);
				printf("%.25c<--\n\n", 20);
				ft_printf("%.25c<--\n", 0);
				printf("%.25c<--\n\n", 0);
				ft_printf("%.c<--\n", -20);
				printf("%.c<--\n\n", -20);
				ft_printf("%.1c<--\n", 20);
				printf("%.1c<--\n\n", 20);
				ft_printf("%.0c<--\n", 0);
				printf("%.0c<--\n\n", 0);
				ft_printf("%.1c<--\n", 0);
				printf("%.1c<--\n\n", 0);
				ft_printf("%.10c<--\n", -20);
				printf("%.10c<--\n\n", -20);
				ft_printf("%.2c<--\n", 20);
				printf("%.2c<--\n\n", 20);
				ft_printf("%.3c<--\n", 20);
				printf("%.3c<--\n\n", 20);
				ft_printf("%.15c<--\n", 0);
				printf("%.15c<--\n\n", 0);
					printf("-->###<--\n\n");

					ft_printf("-->Width_Precision<--\n\n");
					ft_printf("%#10.10c<--\n", 42);
					printf("%#10.10c<--\n\n", 42);

					ft_printf("%#10.10c<--\n", 4242);
					printf("%#10.10c<--\n\n", 4242);

					ft_printf("%#10.15c<--\n", 0);
					printf("%#10.15c<--\n\n", 0);

					ft_printf("%#10.8c<--\n", 42);
					printf("%#10.8c<--\n\n", 42);

					ft_printf("%#10.8c<--\n", 20);
					printf("%#10.8c<--\n\n", 20);

					ft_printf("%#10.4c<--\n", 20);
					printf("%#10.4c<--\n\n", 20);

					ft_printf("%#10.6c<--\n", 120);
					printf("%#10.6c<--\n\n", 120);

					ft_printf("%#10.8c<--\n", 1200);
					printf("%#10.8c<--\n\n", 1200);

					ft_printf("%#10.1c<--\n", 120);
					printf("%#10.1c<--\n\n", 120);

					ft_printf("%#10.6c<--\n", 242);
					printf("%#10.6c<--\n\n", 242);

					ft_printf("%#10.6c<--\n", 4242);
					printf("%#10.6c<--\n\n", 4242);

					ft_printf("%#10.2c<--\n", 4242);
					printf("%#10.2c<--\n\n", 4242);

					ft_printf("%#10.0c<--\n", 4242);
					printf("%#10.0c<--\n\n", 4242);

					ft_printf("%#10.5c<--\n", 4242);
					printf("%#10.5c<--\n\n", 4242);

					ft_printf("%#10.2c<--\n", 20);
					printf("%#10.2c<--\n\n", 20);

					ft_putendl("ok");
					ft_printf("%#10.2c<--\n", 0);
					printf("%#10.2c<--\n\n", 0);

					ft_printf("%#10.4c<--\n", 0);
					printf("%#10.4c<--\n\n", 0);

					ft_printf("%10.2c<--\n", 0);
					printf("%10.2c<--\n\n", 0);
					ft_printf("%.2c<--\n", 0);
					printf("%.2c<--\n\n", 0);
					ft_printf("%10c<--\n", 0);
					printf("%10c<--\n\n", 0);
					ft_printf("%#10.5c<--\n", ULLONG_MAX);
					printf("%#10.5c<--\n\n", ULLONG_MAX);
					ft_printf("%10.5c<--\n", LLONG_MAX);
					printf("%10.5c<--\n\n", LLONG_MAX);

					ft_printf("%#10.12c<--\n", 20);
					printf("%#10.12c<--\n\n", 20);
					ft_printf("%#10.12c<--\n", 120);
					printf("%#10.12c<--\n\n", 120);
					ft_printf("%#10.12c<--\n", 20);
					printf("%#10.12c<--\n\n", 20);

					ft_printf("%#10.12c<--\n", 0);
					printf("%#10.12c<--\n\n", 0);

					ft_printf("-->Width<--\n\n");
					ft_printf("%#10c<--\n", 42);
					printf("%#10c<--\n\n", 42);
					ft_printf("%#10c<--\n", 142);
					printf("%#10c<--\n\n", 142);
					ft_printf("%#10c<--\n", 14200);
					printf("%#10c<--\n\n", 14200);
					ft_printf("%#10c<--\n", 42);
					printf("%#10c<--\n\n", 42);
					ft_printf("%#10c<--\n", 142);
					printf("%#10c<--\n\n", 142);
					ft_printf("%#10c<--\n", 20);
					printf("%#10c<--\n\n", 20);
					ft_printf("%#10c<--\n", 0);
					printf("%#10c<--\n\n", 0);
					ft_printf("%#1c<--\n", 42);
					printf("%#1c<--\n\n", 42);

					ft_printf("-->Precision<--\n\n");
					ft_printf("%#.8c<--\n", 42);
					printf("%#.8c<--\n\n", 42);

					ft_printf("%#.8c<--\n", 142);
					printf("%#.8c<--\n\n", 142);

					ft_printf("%#.8c<--\n", 42);
					printf("%#.8c<--\n\n", 42);

					ft_printf("%#.2c<--\n", 142);
					printf("%#.2c<--\n\n", 142);

					ft_printf("%#.8c<--\n", 0);
					printf("%#.8c<--\n\n", 0);

					ft_printf("%#10.5llc<--\n", ULLONG_MAX);
					printf("%#10.5llc<--\n\n", ULLONG_MAX);
					ft_printf("%10.5llc<--\n", LLONG_MAX);
					printf("%10.5llc<--\n\n", LLONG_MAX);


					printf("-->---<--\n\n");

					ft_printf("-->Width_Precision<--\n\n");
					ft_printf("%-10.10c<--\n", 42);
					printf("%-10.10c<--\n\n", 42);
					ft_printf("%-10.8c<--\n", 42);
					printf("%-10.8c<--\n\n", 42);
					ft_printf("%-10.15c<--\n", 0);
					printf("%-10.15c<--\n\n", 0);
					ft_printf("%-10.8c<--\n", 20);
					printf("%-10.8c<--\n\n", 20);
					ft_printf("%-10.8c<--\n", 20);
					printf("%-10.8c<--\n\n", 20);
					ft_printf("%-10.6c<--\n", 120);
					printf("%-10.6c<--\n\n", 120);
					ft_printf("%-10.6c<--\n", 1200);
					printf("%-10.6c<--\n\n", 1200);
					ft_printf("%-10.6c<--\n", 1);
					printf("%-10.6c<--\n\n", 1);
					ft_printf("%-10.2c<--\n", 20);
					printf("%-10.2c<--\n\n", 20);

					ft_printf("%-10.2c<--\n", 0);
					printf("%-10.2c<--\n\n", 0);

					ft_printf("%-10.4c<--\n", 0);
					printf("%-10.4c<--\n\n", 0);

					ft_printf("%10.2c<--\n", 0);
					printf("%10.2c<--\n\n", 0);
					ft_printf("%-10.5c<--\n", ULLONG_MAX);
					printf("%-10.5c<--\n\n", ULLONG_MAX);
					ft_printf("%-10.2c<--\n", 100000);
					printf("%-10.2c<--\n\n", 100000);
					ft_printf("%-10.1c<--\n", 100);
					printf("%-10.1c<--\n\n", 100);
					ft_printf("%-10.0c<--\n", 10);
					printf("%-10.0c<--\n\n", 10);
				//			ft_printf("%10.5c<--\n", LLONG_MAX);
				//			printf("%10.5c<--\n\n", LLONG_MAX);

					ft_printf("%-10.12c<--\n", 20);
					printf("%-10.12c<--\n\n", 20);
					ft_printf("%-10.12c<--\n", 120);
					printf("%-10.12c<--\n\n", 120);
					ft_printf("%-10.12c<--\n", 20);
					printf("%-10.12c<--\n\n", 20);

					ft_printf("%-10.12c<--\n", 0);
					printf("%-10.12c<--\n\n", 0);

					ft_printf("%-10.7c<--\n", -20);
					printf("%-10.7c<--\n\n", -20);
					ft_printf("%-10.1c<--\n", 20);
					printf("%-10.1c<--\n\n", 20);
					ft_printf("%-10.1c<--\n", -20);
					printf("%-10.1c<--\n\n", -20);
					ft_printf("%-10.2c<--\n", -12);
					printf("%-10.2c<--\n\n", -12);
					ft_printf("%-10.2c<--\n", -1242);
					printf("%-10.2c<--\n\n", -1242);

					ft_printf("-->Width<--\n\n");
					ft_printf("%-10c<--\n", 42);
					printf("%-10c<--\n\n", 42);
					ft_printf("%-10c<--\n", -142);
					printf("%-10c<--\n\n", -142);
					ft_printf("%-10c<--\n", 142);
					printf("%-10c<--\n\n", 142);
					ft_printf("%-10c<--\n", 14200);
					printf("%-10c<--\n\n", 14200);
					ft_printf("%-10c<--\n", 42);
					printf("%-10c<--\n\n", 42);
					ft_printf("%-10c<--\n", 142);
					printf("%-10c<--\n\n", 142);
					ft_printf("%-10c<--\n", 20);
					printf("%-10c<--\n\n", 20);
					ft_printf("%-10c<--\n", 0);
					printf("%-10c<--\n\n", 0);
					ft_printf("%-1c<--\n", 42);
					printf("%-1c<--\n\n", 42);
					ft_printf("%-2c<--\n", 10);
					printf("%-2c<--\n\n", 10);
					ft_printf("%-4c<--\n", 424);
					printf("%-4c<--\n\n", 424);
					ft_printf("%-1c<--\n", 0);
					printf("%-1c<--\n\n", 0);

					ft_printf("%#10.5llc<--\n", ULLONG_MAX);
					printf("%#10.5llc<--\n\n", ULLONG_MAX);
					ft_printf("%10.5llc<--\n", LLONG_MAX);
					printf("%10.5llc<--\n\n", LLONG_MAX);

					ft_printf("-->Precision<--\n\n");
					ft_printf("%-.8c<--\n", 42);
					printf("%-.8c<--\n\n", 42);
					ft_printf("%-.8c<--\n", 142);
					printf("%-.8c<--\n\n", 142);
					ft_printf("%-.8c<--\n", 42);
					printf("%-.8c<--\n\n", 42);
					ft_printf("%-.2c<--\n", 142);
					printf("%-.2c<--\n\n", 142);
					ft_printf("%-.8c<--\n", 0);
					printf("%-.8c<--\n\n", 0);
					ft_printf("%-.c<--\n", 0);
					printf("%-.c<--\n\n", 0);
					ft_printf("%-.0c<--\n", 0);
					printf("%-.0c<--\n\n", 0);
					ft_printf("%.c<--\n", 0);
					printf("%.c<--\n\n", 0);
					ft_printf("%-.1c<--\n", 0);
					printf("%-.1c<--\n\n", 0);
					ft_printf("%-.3c<--\n", 142);
					printf("%-.3c<--\n\n", 142);
					ft_printf("%-.4c<--\n", 142);
					printf("%-.4c<--\n\n", 142);

					printf("-->   <--\n\n");

					ft_printf("-->Width_Precision<--\n\n");
					ft_printf("% 10.10c<--\n", 42);
					printf("% 10.10c<--\n\n", 42);
					ft_printf("% 10.8c<--\n", 42);
					printf("% 10.8c<--\n\n", 42);
					ft_printf("% 10.15c<--\n", 0);
					printf("% 10.15c<--\n\n", 0);
					ft_printf("% 10.8c<--\n", 20);
					printf("% 10.8c<--\n\n", 20);
					ft_printf("% 10.8c<--\n", 20);
					printf("% 10.8c<--\n\n", 20);
					ft_printf("% 10.6c<--\n", 120);
					printf("% 10.6c<--\n\n", 120);
					ft_printf("% 10.2c<--\n", 20);
					printf("% 10.2c<--\n\n", 20);

					ft_printf("% 10.2c<--\n", 0);
					printf("% 10.2c<--\n\n", 0);

					ft_printf("% 10.4c<--\n", 0);
					printf("% 10.4c<--\n\n", 0);

					//			ft_printf("%10.2c<--\n", 0);
					//			printf("%10.2c<--\n\n", 0);
					ft_printf("% 10.5c<--\n", ULLONG_MAX);
					printf("% 10.5c<--\n\n", ULLONG_MAX);
					ft_printf("% 10.2c<--\n", 100000);
					printf("% 10.2c<--\n\n", 100000);
					ft_printf("% 10.1c<--\n", 100);
					printf("% 10.1c<--\n\n", 100);
					ft_printf("% 10.0c<--\n", 10);
					printf("% 10.0c<--\n\n", 10);
					//			ft_printf("%10.5c<--\n", LLONG_MAX);
					//			printf("%10.5c<--\n\n", LLONG_MAX);

					ft_printf("% 10.12c<--\n", 20);
					printf("% 10.12c<--\n\n", 20);
					ft_printf("% 10.12c<--\n", 120);
					printf("% 10.12c<--\n\n", 120);
					ft_printf("% 10.12c<--\n", 20);
					printf("% 10.12c<--\n\n", 20);

					ft_printf("% 10.12c<--\n", 0);
					printf("% 10.12c<--\n\n", 0);

					ft_printf("-->Width<--\n\n");
					ft_printf("% 10c<--\n", 42);
					printf("% 10c<--\n\n", 42);
					ft_printf("% 10c<--\n", -142);
					printf("% 10c<--\n\n", -142);
					ft_printf("% 10c<--\n", 142);
					printf("% 10c<--\n\n", 142);
					ft_printf("% 10c<--\n", 14200);
					printf("% 10c<--\n\n", 14200);
					ft_printf("% 10c<--\n", 42);
					printf("% 10c<--\n\n", 42);
					ft_printf("% 10c<--\n", 142);
					printf("% 10c<--\n\n", 142);
					ft_printf("% 10c<--\n", 20);
					printf("% 10c<--\n\n", 20);
					ft_printf("% 10c<--\n", 0);
					printf("% 10c<--\n\n", 0);
					ft_printf("% 1c<--\n", 42);
					printf("% 1c<--\n\n", 42);

					ft_printf("-->Precision<--\n\n");
					ft_printf("% .8c<--\n", 42);
					printf("% .8c<--\n\n", 42);
					ft_printf("% .8c<--\n", 142);
					printf("% .8c<--\n\n", 142);
					ft_printf("% .8c<--\n", 42);
					printf("% .8c<--\n\n", 42);
					ft_printf("% .2c<--\n", 142);
					printf("% .2c<--\n\n", 142);
					ft_printf("% .8c<--\n", 0);
					printf("% .8c<--\n\n", 0);

				ft_printf("-->##--x--##<--\n\n");

				ft_printf("-->Width_Precision<--\n\n");
				ft_printf("%#-10.12c<--\n", 42);
				printf("%#-10.12c<--\n\n", 42);
				ft_printf("%#-10.10c<--\n", 42);
				printf("%#-10.10c<--\n\n", 42);
				ft_printf("%#-10.8c<--\n", 42);
				printf("%#-10.8c<--\n\n", 42);
				ft_printf("%#-10.15c<--\n", 0);
				printf("%#-10.15c<--\n\n", 0);

				ft_printf("%#-10.12c<--\n", -142);
				printf("%#-10.12c<--\n\n", -142);
				ft_printf("%#-10.10c<--\n", -142);
				printf("%#-10.10c<--\n\n", -142);
				ft_printf("%#-10.8c<--\n", -142);
				printf("%#-10.8c<--\n\n", -142);
				ft_printf("%#-10.2c<--\n", -10);
				printf("%#-10.2c<--\n\n", -10);
				ft_printf("%#-10.c<--\n", -10);
				printf("%#-10.c<--\n\n", -10);

				ft_printf("%#-10.8c<--\n", 20);
				printf("%#-10.8c<--\n\n", 20);
				ft_printf("%#-10.8c<--\n", 20);
				printf("%#-10.8c<--\n\n", 20);
				ft_printf("%#-10.6c<--\n", 120);
				printf("%#-10.6c<--\n\n", 120);
				ft_printf("%#-10.2c<--\n", 20);
				printf("%#-10.2c<--\n\n", 20);

				ft_printf("%#-10.1c<--\n", 120);
				printf("%#-10.1c<--\n\n", 120);
				ft_printf("%#-10.1c<--\n", 20);
				printf("%#-10.1c<--\n\n", 20);

				ft_printf("%#10.12c<--\n", 20);
				printf("%#10.12c<--\n\n", 20);
				ft_printf("%#10.12c<--\n", 120);
				printf("%#10.12c<--\n\n", 120);
				ft_printf("%#10.12c<--\n", 20);
				printf("%#10.12c<--\n\n", 20);

				ft_printf("%#10.12c<--\n", 0);
				printf("%#10.12c<--\n\n", 0);

				ft_printf("%#-10.2c<--\n", 0);
				printf("%#-10.2c<--\n\n", 0);
				ft_printf("%#-10.0c<--\n", 0);
				printf("%#-10.0c<--\n\n", 0);
				ft_printf("%#-10.1c<--\n", 0);
				printf("%#-10.1c<--\n\n", 0);
				//	ft_printf("%-10.2c<--\n", 0);
				//	printf("%-10.2c<--\n\n", 0);
				//	ft_printf("%#10.2c<--\n", 0);
				//	printf("%#10.2c<--\n\n", 0);

				ft_printf("%#-10.12c<--\n", 20);
				printf("%#-10.12c<--\n\n", 20);
				ft_printf("%#-10.12c<--\n", 120);
				printf("%#-10.12c<--\n\n", 120);
				ft_printf("%#-10.13c<--\n", 1200);
				printf("%#-10.13c<--\n\n", 1200);
				ft_printf("%#-10.12c<--\n", 1200);
				printf("%#-10.12c<--\n\n", 1200);
				ft_printf("%#-10.12c<--\n", 20);
				printf("%#-10.12c<--\n\n", 20);
				ft_printf("%#-10.12c<--\n", 0);
				printf("%#-10.12c<--\n\n", 0);

				ft_printf("%10.1c<--\n", 0);
				printf("%10.1c<--\n\n", 0);

				ft_printf("%10.2c<--\n", 16);
				printf("%10.2c<--\n\n", 16);

				ft_printf("%10.c<--\n", 0);
				printf("%10.c<--\n\n", 0);

				ft_printf("-->Precision<--\n\n");
				ft_printf("%#-.8c<--\n", 42);
				printf("%#-.8c<--\n\n", 42);
				ft_printf("%#-.8c<--\n", 142);
				printf("%#-.8c<--\n\n", 142);
				ft_printf("%#-.8c<--\n", 42);
				printf("%#-.8c<--\n\n", 42);
				ft_printf("%#-.2c<--\n", 142);
				printf("%#-.2c<--\n\n", 142);
				ft_printf("%#-.8c<--\n", 0);
				printf("%#-.8c<--\n\n", 0);

				ft_printf("-->Width<--\n\n");
				ft_printf("%#-10c<--\n", 42);
				printf("%#-10c<--\n\n", 42);
				ft_printf("%#-10c<--\n", 142);
				printf("%#-10c<--\n\n", 142);
				ft_printf("%#-10c<--\n", 42);
				printf("%#-10c<--\n\n", 42);
				ft_printf("%#-10c<--\n", 142);
				printf("%#-10c<--\n\n", 142);
				ft_printf("%#-10c<--\n", 20);
				printf("%#-10c<--\n\n", 20);
				ft_printf("%#-10c<--\n", 0);
				printf("%#-10c<--\n\n", 0);
				ft_printf("%#-1c<--\n", 42);
				printf("%#-1c<--\n\n", 42);
				ft_printf("%#-1c<--\n", 424242);
				printf("%#-1c<--\n\n", 424242);
				ft_printf("%#-25c<--\n", 424242);
				printf("%#-25c<--\n\n", 424242);
				ft_printf("%#-7c<--\n", 424242);
				printf("%#-7c<--\n\n", 424242);
				ft_printf("%#-8c<--\n", 424242);
				printf("%#-8c<--\n\n", 424242);
				ft_printf("%#-c<--\n", 424242);
				printf("%#-c<--\n\n", 424242);
				ft_printf("-->Width<--\n\n");
				ft_printf("%-10c<--\n", 42);
				printf("%-10c<--\n\n", 42);
				ft_printf("%-10c<--\n", 142);
				printf("%-10c<--\n\n", 142);
				ft_printf("%-10c<--\n", 14200);
				printf("%-10c<--\n\n", 14200);
				ft_printf("%-10c<--\n", 42);
				printf("%-10c<--\n\n", 42);
				ft_printf("%-10c<--\n", 142);
				printf("%-10c<--\n\n", 142);
				ft_printf("%-10c<--\n", 20);
				printf("%-10c<--\n\n", 20);
				ft_printf("%-10c<--\n", 0);
				printf("%-10c<--\n\n", 0);
				ft_printf("%-1c<--\n", 42);
				printf("%-1c<--\n\n", 42);

				ft_printf("-->##--  x  --##<--\n\n");

				ft_printf("-->Width_Precision<--\n\n");
				ft_printf("%#- 10.12c<--\n", 42);
				printf("%#- 10.12c<--\n\n", 42);
				ft_printf("%#- 10.10c<--\n", 42);
				printf("%#- 10.10c<--\n\n", 42);
				ft_printf("%#- 10.8c<--\n", 42);
				printf("%#- 10.8c<--\n\n", 42);
				ft_printf("%#- 10.15c<--\n", 0);
				printf("%#- 10.15c<--\n\n", 0);

				ft_printf("%#- 10.8c<--\n", 20);
				printf("%#- 10.8c<--\n\n", 20);
				ft_printf("%#- 10.8c<--\n", 20);
				printf("%#- 10.8c<--\n\n", 20);
				ft_printf("%#- 10.6c<--\n", 120);
				printf("%#- 10.6c<--\n\n", 120);
				ft_printf("%#- 10.2c<--\n", 20);
				printf("%#- 10.2c<--\n\n", 20);

				ft_printf("%#- 10.1c<--\n", 120);
				printf("%#- 10.1c<--\n\n", 120);
				ft_printf("%#- 10.1c<--\n", 20);
				printf("%#- 10.1c<--\n\n", 20);

				ft_printf("%#- 10.2c<--\n", 0);
				printf("%#- 10.2c<--\n\n", 0);
				ft_printf("%#-10.2c<--\n", 0);
				printf("%#-10.2c<--\n\n", 0);
				ft_printf("%- 10.2c<--\n", 0);
				printf("%- 10.2c<--\n\n", 0);
				ft_printf("%-010.2c<--\n", 0);
				printf("%-010.2c<--\n\n", 0);
				ft_printf("%#10.2c<--\n", 0);
				printf("%#10.2c<--\n\n", 0);

				ft_printf("%#- 10.12c<--\n", 20);
				printf("%#- 10.12c<--\n\n", 20);
				ft_printf("%#- 10.12c<--\n", 120);
				printf("%#- 10.12c<--\n\n", 120);
				ft_printf("%#- 10.12c<--\n", 20);
				printf("%#- 10.12c<--\n\n", 20);
				ft_printf("%#- 10.12c<--\n", 0);
				printf("%#- 10.12c<--\n\n", 0);
				ft_printf("%#- 10.0c<--\n", 0);
				printf("%#- 10.0c<--\n\n", 0);
				ft_printf("%#- 10.1c<--\n", 10);
				printf("%#- 10.1c<--\n\n", 10);


				ft_printf("-->Width<--\n\n");
				ft_printf("%#- 10c<--\n", 42);
				printf("%#- 10c<--\n\n", 42);
				ft_printf("%#- 10c<--\n", 142);
				printf("%#- 10c<--\n\n", 142);
				ft_printf("%#- 10c<--\n", 42);
				printf("%#- 10c<--\n\n", 42);
				ft_printf("%#- 10c<--\n", 142);
				printf("%#- 10c<--\n\n", 142);
				ft_printf("%#- 10c<--\n", 20);
				printf("%#- 10c<--\n\n", 20);
				ft_printf("%#- 10c<--\n", 0);
				printf("%#- 10c<--\n\n", 0);
				ft_printf("%#- 1c<--\n", 42);
				printf("%#- 1c<--\n\n", 42);

				ft_printf("-->Precision<--\n\n");
				ft_printf("%#- .8c<--\n", 42);
				printf("%#- .8c<--\n\n", 42);
				ft_printf("%#- .8c<--\n", 142);
				printf("%#- .8c<--\n\n", 142);
				ft_printf("%#- .8c<--\n", 42);
				printf("%#- .8c<--\n\n", 42);
				ft_printf("%#- .2c<--\n", 142);
				printf("%#- .2c<--\n\n", 142);
				ft_printf("%#- .1c<--\n", 42);
				printf("%#- .1c<--\n\n", 42);
				ft_printf("%#- .c<--\n", 42);
				printf("%#- .c<--\n\n", 42);
				ft_printf("%.c<--\n", 42);
				printf("%.c<--\n\n", 42);
				ft_printf("%#.c<--\n", 42);
				printf("%#.c<--\n\n", 42);
				ft_printf("%#- .0c<--\n", 42);
				printf("%#- .0c<--\n\n", 42);
				ft_printf("%#- .8c<--\n", 0);
				printf("%#- .8c<--\n\n", 0);

				ft_printf("-->##++x++##<--\n\n");

				ft_printf("-->Width_Precision<--\n\n");
				ft_printf("%#-+10.12c<--\n", 42);
				printf("%#-+10.12c<--\n\n", 42);
				ft_printf("%#-+10.10c<--\n", 42);
				printf("%#-+10.10c<--\n\n", 42);
				ft_printf("%#-+10.8c<--\n", 42);
				printf("%#-+10.8c<--\n\n", 42);
				ft_printf("%#-+10.15c<--\n", 0);
				printf("%#-+10.15c<--\n\n", 0);

				ft_printf("%#-+10.8c<--\n", 20);
				printf("%#-+10.8c<--\n\n", 20);
				ft_printf("%#-+10.8c<--\n", 20);
				printf("%#-+10.8c<--\n\n", 20);
				ft_printf("%#-+10.6c<--\n", 120);
				printf("%#-+10.6c<--\n\n", 120);
				ft_printf("%#-+10.2c<--\n", 20);
				printf("%#-+10.2c<--\n\n", 20);

				ft_printf("%#-+10.1c<--\n", 120);
				printf("%#-+10.1c<--\n\n", 120);
				ft_printf("%#-+10.1c<--\n", 20);
				printf("%#-+10.1c<--\n\n", 20);

				ft_printf("%#-+10.2c<--\n", 0);
				printf("%#-+10.2c<--\n\n", 0);
				ft_printf("%#-+10.2c<--\n", 0);
				printf("%#-+10.2c<--\n\n", 0);
				ft_printf("%-+10.2c<--\n", 0);
				printf("%-+10.2c<--\n\n", 0);
				ft_printf("%-010.2c<--\n", 0);
				printf("%-010.2c<--\n\n", 0);
				ft_printf("%#10.2c<--\n", 0);
				printf("%#10.2c<--\n\n", 0);

				ft_printf("%#-+10.12c<--\n", 20);
				printf("%#-+10.12c<--\n\n", 20);
				ft_printf("%#-+10.12c<--\n", 120);
				printf("%#-+10.12c<--\n\n", 120);
				ft_printf("%#-+10.12c<--\n", 20);
				printf("%#-+10.12c<--\n\n", 20);
				ft_printf("%#-+10.12c<--\n", 0);
				printf("%#-+10.12c<--\n\n", 0);

				ft_printf("-->Width<--\n\n");
				ft_printf("%#-+10c<--\n", 42);
				printf("%#-+10c<--\n\n", 42);
				ft_printf("%#-+1c<--\n", 42);
				printf("%#-+1c<--\n\n", 42);
				ft_printf("%#-+2c<--\n", 42);
				printf("%#-+2c<--\n\n", 42);
				ft_printf("%#-+3c<--\n", 42);
				printf("%#-+3c<--\n\n", 42);
				ft_printf("%#-+4c<--\n", 42);
				printf("%#-+4c<--\n\n", 42);
				ft_printf("%#-+10c<--\n", 142);
				printf("%#-+10c<--\n\n", 142);
				ft_printf("%#-+10c<--\n", 42);
				printf("%#-+10c<--\n\n", 42);
				ft_printf("%#-+2c<--\n", 142);
				printf("%#-+1c<--\n\n", 142);
				ft_printf("%#-+2c<--\n", 20);
				printf("%#-+2c<--\n\n", 20);
				ft_printf("%#-+1c<--\n", 0);
				printf("%#-+1c<--\n\n", 0);
				ft_printf("%#-+1c<--\n", 42);
				printf("%#-+1c<--\n\n", 42);

				ft_printf("-->Precision<--\n\n");
				ft_printf("%#-+.8c<--\n", 42);
				printf("%#-+.8c<--\n\n", 42);
				ft_printf("%#-+.0c<--\n", 42);
				printf("%#-+.0c<--\n\n", 42);
				ft_printf("%#-+.c<--\n", 0);
				printf("%#-+.c<--\n\n", 0);
				ft_printf("%#-+.1c<--\n", 0);
				printf("%#-+.1c<--\n\n", 0);
				ft_printf("%#-+.8c<--\n", 142);
				printf("%#-+.8c<--\n\n", 142);
				ft_printf("%#-+.8c<--\n", 42);
				printf("%#-+.8c<--\n\n", 42);
				ft_printf("%#-+.2c<--\n", 142);
				printf("%#-+.2c<--\n\n", 142);
				ft_printf("%#-+.1c<--\n", 42);
				printf("%#-+.1c<--\n\n", 42);
				ft_printf("%#-+.c<--\n", 42);
				printf("%#-+.c<--\n\n", 42);
				ft_printf("%+.c<--\n", 42);
				printf("%+.c<--\n\n", 42);
				ft_printf("%#.c<--\n", 42);
				printf("%#.c<--\n\n", 42);
				ft_printf("%#-+.0c<--\n", 42);
				printf("%#-+.0c<--\n\n", 42);
				ft_printf("%#-+.8c<--\n", 0);
				printf("%#-+.8c<--\n\n", 0);

				ft_printf("%-.0c<--\n", 0);
				printf("%-.0c<--\n\n", 0);
				ft_printf("%-.0c<--\n", 0);
				printf("%-.0c<--\n\n", 0);
				ft_printf("%-.1c<--\n", 0);
				printf("%-.1c<--\n\n", 0);
				ft_printf("%10.0c<--\n", 0);
				printf("%10.0c<--\n\n", 0);
				ft_printf("%1.0c<--\n", 0);
				printf("%1.0c<--\n\n", 0);

				ft_printf("%#10.5llc<--\n", ULLONG_MAX);
				printf("%#10.5llc<--\n\n", ULLONG_MAX);

				ft_printf("%#10.5llc<--\n", LLONG_MIN);
				printf("%#10.5llc<--\n\n", LLONG_MIN);

				ft_printf("%#10.5lc<--\n", LONG_MAX);
				printf("%#10.5lc<--\n\n", LONG_MAX);

				ft_printf("%#10.5c<--\n", INT_MAX);
				printf("%#10.5c<--\n\n", INT_MAX);

				ft_putendl("Ok");
				ft_printf("%#10.5c<--\n", 42);
				printf("%#10.5c<--\n\n", 42);

				ft_printf("#10.0x %#10.0c<--\n", 42);
				printf("#10.0x %#10.0c<--\n\n", 42);

				ft_printf("#10.1x %#10.1c<--\n", 42);
				printf("#10.1x %#10.1c<--\n\n", 42);

				ft_printf("10.0x %10.0c<--\n", 42);
				printf("10.0x %10.0c<--\n\n", 42);

				ft_printf("10.1x %10.1c<--\n", 42);
				printf("10.1x %10.1c<--\n\n", 42);

				ft_printf("%#10.2c<--\n", 20);
				printf("%#10.2c<--\n\n", 20);

				ft_printf("%10.5c<--\n", LLONG_MAX);
				printf("%10.5c<--\n\n", LLONG_MAX);

				ft_printf("%llc<--\n", ULLONG_MAX);
				printf("%llc<--\n", ULLONG_MAX);

				ft_printf("%#-+.0c<--\n", 0);
				printf("%#-+.0c<--\n\n", 0);
				ft_printf("%#-+.0c<--\n", 0);
				printf("%#-+.0c<--\n\n", 0);
				ft_printf("%#.0c<--\n", 0);
				printf("%#.0c<--\n\n", 0);

				ft_putendl("OK");
				ft_printf("%#-+.1c<--\n", 0);
				printf("%#-+.1c<--\n\n", 0);
				ft_printf("%#-+.c<--\n", 0);
				printf("%#-+.c<--\n\n", 0);
				ft_printf("%#- .1c<--\n", 0);
				printf("%#- .1c<--\n\n", 0);
				ft_printf("%#-.1c<--\n", 0);
				printf("%#-.1c<--\n\n", 0);
				ft_printf("%#.1c<--\n", 0);
				printf("%#.1c<--\n\n", 0);
				ft_printf("%.1c<--\n", 0);
				printf("%.1c<--\n\n", 0);
				ft_printf("#-+.8o %#-+.8c<--\n", 0);
				printf("#-+.8o %#-+.8c<--\n\n", 0);
				ft_printf("#-.8o %#-.8c<--\n", 0);
				printf("#-.8o %#-.8c<--\n\n", 0);
				ft_printf("#.8 %#.8c<--\n", 0);
				printf("#.8 %#.8c<--\n\n", 0);
				ft_printf("-+.8o %-+.8c<--\n", 0);
				printf("-+.8o %-+.8c<--\n\n", 0);
				ft_printf("-.8o %-.8c<--\n", 0);
				printf("-.8o %-.8c<--\n\n", 0);
				ft_printf(".8 %.8c<--\n", 0);
				printf(".8 %.8c<--\n\n", 0);
				ft_putendl("/");
				ft_printf("#-+.1o %#-+.1c<--\n", 0);
				printf("#-+.1o %#-+.1c<--\n\n", 0);
				ft_printf("#-+.2o %#-+.2c<--\n", 0);
				printf("#-+.2o %#-+.2c<--\n\n", 0);
				ft_printf("#-+.1o %#-+.1c<--\n", 0);
				printf("#-+.1o %#-+.1c<--\n\n", 0);
				ft_printf("#-.8o %#-.8c<--\n", 0);
				printf("#-.8o %#-.8c<--\n\n", 0);
				ft_printf("#.8 %#.8c<--\n", 0);
				printf("#.8 %#.8c<--\n\n", 0);
				ft_printf("-+.8o %-+.8c<--\n", 0);
				printf("-+.8o %-+.8c<--\n\n", 0);
				ft_printf("-.8o %-.8c<--\n", 0);
				printf("-.8o %-.8c<--\n\n", 0);
				ft_printf(".8 %.8c<--\n", 0);
				printf(".8 %.8c<--\n\n", 0);
				ft_putendl("OK");
				ft_printf("%#-+.c<--\n", 0);
				printf("%#-+.c<--\n\n", 0);
				ft_printf("%#- .c<--\n", 0);
				printf("%#- .c<--\n\n", 0);
				ft_printf("%#-.c<--\n", 0);
				printf("%#-.c<--\n\n", 0);
				ft_printf("%#.c<--\n", 0);
				printf("%#.c<--\n\n", 0);
				ft_printf("%.c<--\n", 0);
				printf("%.c<--\n\n", 0);
				ft_putendl("OK");
				ft_printf("%#-+10.0c<--\n", 0);
				printf("%#-+10.0c<--\n\n", 0);
				ft_printf("%#-+10.0c<--\n", 0);
				printf("%#-+10.0c<--\n\n", 0);
				ft_printf("%#10.0c<--\n", 0);
				printf("%#10.0c<--\n\n", 0);

				ft_printf("%#10.5llc<--\n", ULLONG_MAX);
				printf("%#10.5llc<--\n\n", ULLONG_MAX);

				ft_printf("%#10.5llc<--\n", LLONG_MIN);
				printf("%#10.5llc<--\n\n", LLONG_MIN);

				ft_printf("%#10.25lc<--\n", LONG_MAX);
				printf("%#10.25lc<--\n\n", LONG_MAX);
				ft_putendl("1");
				ft_printf("%#10.25lc<--\n", LONG_MAX - 150);
				printf("%#10.25lc<--\n\n", LONG_MAX - 150);

				ft_printf("%#10.25lc<--\n", LONG_MAX - 10000);
				printf("%#10.25lc<--\n\n", LONG_MAX - 10000);

				ft_printf("%#10.5c<--\n", INT_MAX);
				printf("%#10.5c<--\n\n", INT_MAX);

				ft_printf("%#10.5llc<--\n", LLONG_MAX);
				printf("%#10.5llc<--\n\n", LLONG_MAX);

				ft_putendl("1");
				ft_printf("%#10.5c<--\n", -1);
				printf("%#10.5c<--\n\n", -1);
				ft_printf("%#10.5c<--\n", -10);
				printf("%#10.5c<--\n\n", -10);
				ft_printf("%#10.5c<--\n", -100);
				printf("%#10.5c<--\n\n", -100);
				ft_printf("%#10.5c<--\n", -1000);
				printf("%#10.5c<--\n\n", -1000);
				ft_printf("%#10.5c<--\n", -10000);
				printf("%#10.5c<--\n\n", -10000);
				ft_printf("%#10.5c<--\n", -42);
				printf("%#10.5c<--\n\n", -42);

				ft_printf("%#10.5llc<--\n", ULLONG_MAX);
				printf("%#10.5llc<--\n\n", ULLONG_MAX);

	ft_printf("%#10.5c<--\n", INT_MAX);
	printf("%#10.5c<--\n\n", INT_MAX);

	ft_printf("%#10.25lc<--\n", LONG_MAX - 10000);
	printf("%#10.25lc<--\n\n", LONG_MAX - 10000);

	//ft_printf("%s : %C<--\n", "Hello", -1);
	//printf("%s : %C<--\n\n", "Hello", -1);
	ft_printf("%s : %25.10C<--\n", "Hello", 0xF8FF);
	printf("%s : %25.10C<--\n\n", "Hello", 0xF8FF);
	ft_printf("%25.10C<--\n", 0xF8FF);
	printf("%25.10C<--\n\n", 0xF8FF);
	ft_printf("%025.10C<--\n", 0xF8FF);
	printf("%025.10C<--\n\n", 0xF8FF);
	ft_printf("%#05C<--\n", 0xF8FF);
	printf("%#05C<--\n\n", 0xF8FF);
	ft_printf("%#01C<--\n", 0xF8FF);
	printf("%#01C<--\n\n", 0xF8FF);

	ft_putendl("SSSSSS\n");
	wchar_t *S = L"Привет ☕  ⚔  ⚒  ⚓  ⑨ ";
	ft_printf("%10S<--\n", S);
	printf("%10S<--\n\n", S);

	ft_printf("%10S<--\n", NULL);
	printf("%10S<--\n\n", NULL);

	ft_printf("%40S<--\n", S);
	printf("%40S<--\n\n", S);

	ft_printf("%040S<--\n", S);
	printf("%040S<--\n\n", S);

	ft_printf("%-40S<--\n", S);
	printf("%-40S<--\n\n", S);

	ft_printf("%-40.60S<--\n", S);
	printf("%-40.60S<--\n\n", S);

	ft_printf("-%# -80S<--\n", S);
	printf("-%# -80S<--\n\n", S);

	ft_putendl("PPPPPP\n");

	unsigned long long int my_ptr = LLONG_MIN;

//	my_ptr = LLONG_MIN;
	ft_printf("-%25p<--\n", &my_ptr);
	printf("-%25p<--\n\n", &my_ptr);

	ft_printf("-%60p<--\n", &my_ptr);
	printf("-%60p<--\n\n", &my_ptr);

	ft_printf("-%060p<--\n", &my_ptr);
	printf("-%060p<--\n\n", &my_ptr);

	ft_printf("-%-60p<--\n", &my_ptr);
	printf("-%-60p<--\n\n", &my_ptr);

	ft_printf("-%-060p<--\n", &my_ptr);
	printf("-%-060p<--\n\n", &my_ptr);
	ft_printf("-%-0p<--\n", &my_ptr);
	printf("-%-0p<--\n\n", &my_ptr);
	ft_printf("-%-014llp<--\n", &my_ptr);
	printf("-%-014llp<--\n\n", &my_ptr);
	ft_printf("-%015d<--\n", &my_ptr);
	printf("-%015d<--\n\n", &my_ptr);
	ft_printf("-%015x<--\n", 1459886744);
	printf("-%015x<--\n\n", 1459886744);
	ft_printf("-%015o<--\n", 1459886744);
	printf("-%015o<--\n\n", 1459886744);
	ft_printf("-%15o<--\n", 1459886744);
	printf("-%15o<--\n\n", 1459886744);
	ft_printf("-%0-15o<--\n", 1459886744);
	printf("-%0-15o<--\n\n", 1459886744);
*/

//	ft_printf("my: %d\n", ft_printf("%10s : %25.10C<--\n", "Hello", -10));
//	printf("original: %d\n", printf("%10s : %25.10C<--\n", "Hello", -10));

/*
	int i = -100;
	while (i++ < 300)
	{
		ft_printf("%c<--\n", i);
		printf("%c<--\n\n", i);
	}
*/
//	printf("%llp<--\n", ULLONG_MAX);
//	printf("%+llp<--\n\n", LLONG_MIN);
//	printf("% llp<--\n\n", LLONG_MIN);
//	printf("%#llp<--\n\n", LLONG_MIN);
//	printf("%0llp<--\n\n", LLONG_MIN);

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
