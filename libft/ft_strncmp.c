#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n)
	{
		while (*s1 == *s2 && *s1 && --n)
		{
			s1++;
			s2++;
		}
		return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
	}
	return (0);
}
