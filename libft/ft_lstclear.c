#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*clear;

	while (*lst)
	{
		clear = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(clear);
	}
	*lst = NULL;
}
