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
