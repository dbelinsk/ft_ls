/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:27:05 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/11 13:23:46 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;

	if (n == 0 || dst == src)
		return (dst);
	i = -1;
	while (++i < n)
		((unsigned char *)dst)[i] = ((unsigned const char *)src)[i];
	return (dst);
}
