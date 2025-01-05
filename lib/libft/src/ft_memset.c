/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:54:38 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/11 13:23:35 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memset(void *b, int c, size_t len)
{
	size_t							count;
	unsigned char					*str;

	count = 0;
	str = (unsigned char*)b;
	while (count < len)
	{
		str[count] = (unsigned char)c;
		count++;
	}
	return (b);
}
