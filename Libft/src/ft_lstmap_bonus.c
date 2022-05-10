#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;

	if (lst == NULL)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (new_list == NULL)
		return (NULL);
	current = new_list;
	lst = lst->next;
	while (lst != NULL)
	{
		current->next = ft_lstnew(f(lst->content));
		if (current == NULL)
		{
			ft_lstclear(new_list, del);
			return (NULL);
		}
		current = current->next;
		lst = lst->next;
	}
	return (new_list);
}
