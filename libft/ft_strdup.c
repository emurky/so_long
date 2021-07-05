#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*strdup;

	s2 = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	strdup = s2;
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	return (strdup);
}
