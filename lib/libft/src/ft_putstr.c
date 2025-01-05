/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 07:35:52 by mpernia-          #+#    #+#             */
/*   Updated: 2024/12/11 13:23:00 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char const *s)
{
	int len;

	len = (int)ft_strlen(s);
	if (!s)
		return (0);
	write(1, s, len);
	return (len);
}
