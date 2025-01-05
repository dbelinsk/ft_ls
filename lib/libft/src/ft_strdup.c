/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:46:37 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/11 13:22:28 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s1)
{
	size_t		len;
	char		*mem;

	len = ft_strlen(s1);
	if (!(mem = ft_calloc(len + 1, sizeof(*mem))))
		return (NULL);
	return ((char*)ft_memcpy(mem, s1, len));
}
