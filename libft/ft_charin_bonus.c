/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charin_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurky <emurky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 21:17:06 by emurky            #+#    #+#             */
/*   Updated: 2021/04/05 22:26:20 by emurky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charin(char c, const char *str)
{
	int		i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(str) + 1;
	while (slen--)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
