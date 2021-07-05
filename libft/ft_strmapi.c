#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fstr;
	unsigned int	i;

	if (!s)
		return (NULL);
	fstr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!fstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		fstr[i] = (*f)(i, s[i]);
		i++;
	}
	fstr[i] = '\0';
	return (fstr);
}
