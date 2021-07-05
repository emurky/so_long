#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	offset;

	offset = ft_strlen(s) + 1;
	while (offset--)
		if (*(s + offset) == (char)c)
			return ((char *)s + offset);
	return (NULL);
}
