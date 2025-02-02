/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:32:15 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/11 13:24:07 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*end;
	t_list		*start;

	if (!lst)
		return (NULL);
	if (!(end = ft_lstnew(f(lst->content))))
		ft_lstdelone(lst, del);
	lst = lst->next;
	start = end;
	while (lst)
	{
		if (!(end->next = ft_lstnew(f(lst->content))))
			ft_lstdelone(lst, del);
		end = end->next;
		lst = lst->next;
	}
	return (start);
}
