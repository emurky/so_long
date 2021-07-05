#include "libft.h"

void	ft_lstdelone(t_list *lst)
{
	free(lst->content);
	free(lst);
}
