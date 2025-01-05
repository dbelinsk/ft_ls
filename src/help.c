/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:43:33 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/31 13:15:42 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "help.h"
#include "libft.h"

int		is_help(char *s)
{
	if (ft_strcmp(s, "--help") == 0)
		return (1);
	return (0);
}

void	help(void)
{
	ft_putstr(HELP_USAGE);
	ft_putstr(HELP_INFO);
	ft_putstr(HELP_OPTIONS);
	ft_putstr(HELP_EXAMPLES);
	ft_putstr(HELP_EXIT_STATUS);
}