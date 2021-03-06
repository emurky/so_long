#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dstptr;
	const unsigned char	*srcptr;

	if (!dst && !src)
		return (NULL);
	dstptr = dst;
	srcptr = src;
	while (n--)
		*dstptr++ = *srcptr++;
	return (dst);
}
