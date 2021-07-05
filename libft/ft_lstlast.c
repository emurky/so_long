#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ret;

	if (!lst)
		return (NULL);
	while (lst)
	{
		ret = lst;
		lst = lst->next;
	}
	return (ret);
}
