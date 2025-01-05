/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:47:38 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/11 13:22:20 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t n;

	i = ft_strlen(dst);
	if (dstsize > i)
	{
		n = 0;
		while (--dstsize - i && *(src + n))
		{
			*(dst + i + n) = *(src + n);
			++n;
		}
		*(dst + i + n) = '\0';
		return (i + ft_strlen(src));
	}
	return (dstsize + ft_strlen(src));
}
