#include "libft.h"

void	ft_putchar_fd(wchar_t c, int fd)
{
	write(fd, &c, 1);
}
