#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dstptr;
	const char	*srcptr;

	dstptr = dst;
	srcptr = src;
	if (dstptr == srcptr)
		return (dst);
	else if (dstptr < srcptr)
		while (len--)
			*dstptr++ = *srcptr++;
	else
	{
		dstptr += len;
		srcptr += len;
		while (len--)
			*(--dstptr) = *(--srcptr);
	}
	return (dst);
}
