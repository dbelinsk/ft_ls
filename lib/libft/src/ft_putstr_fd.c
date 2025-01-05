/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:04:23 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/11 13:23:04 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putstr_fd(char const *s, int fd)
{
	if (s)
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
}
