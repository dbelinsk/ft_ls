/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:51:51 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/31 13:26:10 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"

void		path_error(char *dir)
{
	errno = ENOENT;
	ft_putstr_fd("ls: cannot access '", 2);
	ft_putstr_fd(dir, 2);
	ft_putstr_fd("': No such file or directory\n", 2);
}

void		permission_error(char *dir)
{
	errno = EACCES;
	ft_putstr_fd("ls: cannot open directory '", 2);
	ft_putstr_fd(dir, 2);
	ft_putstr_fd("': Permission denied\n", 2);
}

void		short_opt_error(char opt)
{
	errno = ENOENT;
	ft_putstr_fd("ls: invalid option -- '", 2);
	ft_putchar_fd(opt, 2);
	ft_putstr_fd("'\nTry 'ls --help' for more information.\n", 2);
}

void		long_opt_error(char *opt)
{
	errno = ENOENT;
	ft_putstr_fd("ls: unrecognized option'", 2);
	ft_putstr_fd(opt, 2);
	ft_putstr_fd("'\nTry 'ls --help' for more information.\n", 2);
}