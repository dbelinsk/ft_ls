/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:05:29 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/11 13:24:24 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list		*aux;

	if (!alst || !new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	aux = *alst;
	while (aux->next)
		aux = aux->next;
	aux->next = new;
}
