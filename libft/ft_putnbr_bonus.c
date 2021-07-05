#include "libft.h"

void	ft_putnbr(int n)
{
	int		sign;

	sign = 1;
	if (n < 0)
	{
		ft_putchar('-');
		sign = -1;
	}
	if (n >= 10 || n <= -10)
	{
		ft_putnbr(n / 10 * sign);
		ft_putnbr(n % 10 * sign);
	}
	else
		ft_putchar(n * sign + '0');
}
