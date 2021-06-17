/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurky <emurky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:12:11 by emurky            #+#    #+#             */
/*   Updated: 2021/04/05 22:46:57 by emurky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
