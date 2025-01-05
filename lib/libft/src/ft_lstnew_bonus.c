/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:51:35 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/11 13:24:05 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void *content)
{
	t_list		*node;

	if (!(node = (t_list*)malloc(sizeof(*node))))
		return (NULL);
	if (!content)
		node->content = NULL;
	else
		node->content = content;
	node->next = NULL;
	return (node);
}
