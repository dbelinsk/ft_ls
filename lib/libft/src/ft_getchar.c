/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:28:21 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/11 13:25:02 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int				ft_getchar(void)
{
	char		buf[2];
	int			br;

	br = read(STDOUT_FILENO, buf, 1);
	if (br <= 0)
		return (EOF);
	return ((int)buf[0]);
}
