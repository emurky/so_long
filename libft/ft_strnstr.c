#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t ln)
{
	unsigned long int	i;
	long long int		intlen;

	intlen = ln;
	if (!(*needle))
		return ((char *)hay);
	while (*hay && intlen > 0)
	{
		while (*hay && *hay != *needle && intlen-- > 0)
			hay++;
		i = 0;
		while (hay[i] && needle[i] && hay[i] == needle[i] && intlen-- > 0)
		{
			i++;
			if (!(needle[i]))
				return ((char *)hay);
		}
		intlen += i - 1;
		if (*hay)
			hay++;
	}
	return (NULL);
}
