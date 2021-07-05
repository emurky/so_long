#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*start;

	start = b;
	while (len--)
		*start++ = (unsigned char)c;
	return (b);
}
