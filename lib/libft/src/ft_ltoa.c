/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:08:56 by mpernia-          #+#    #+#             */
/*   Updated: 2024/12/11 13:23:58 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(unsigned long n)
{
	int size;

	size = 0;
	if (n <= 0)
		++size;
	while (n)
	{
		n = n / 10;
		++size;
	}
	return (size);
}

char		*ft_ltoa(long long n)
{
	long long	nb;
	char		*number;
	int			size;

	nb = n;
	size = get_size(n);
	if (!(number = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	if (nb == 0)
		*(number) = '0';
	if (nb < 0)
	{
		*(number) = '-';
		nb = nb * (-1);
	}
	while (size && nb > 0)
	{
		--size;
		*(number + size) = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (number);
}
