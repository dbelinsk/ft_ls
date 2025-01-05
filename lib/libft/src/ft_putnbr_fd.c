/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:05:15 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/11 13:23:07 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		put_next_nbr(unsigned int n, int fd)
{
	if (n > 10)
		put_next_nbr(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		nb *= (-1);
		ft_putchar_fd('-', fd);
	}
	put_next_nbr(nb, fd);
}
