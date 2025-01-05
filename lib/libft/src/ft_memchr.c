/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:44:34 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/11 13:23:52 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if ((unsigned char)c == *(unsigned char*)s)
			return ((unsigned char*)s);
		s++;
	}
	return (NULL);
}
