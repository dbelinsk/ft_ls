/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharntimes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:32:00 by mpernia-          #+#    #+#             */
/*   Updated: 2024/12/11 13:23:20 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putcharntimes(char a, int n)
{
	int i;

	i = n;
	while (n-- > 0)
		write(1, &a, 1);
	return ((i > 0) ? i : 0);
}
