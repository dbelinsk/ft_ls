/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:51:51 by dbelinsk          #+#    #+#             */
/*   Updated: 2025/01/09 12:21:15 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"
#include <stdio.h>

void		path_error(char *dir)
{
	errno = ENOENT;
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(dir, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void		permission_error(char *dir)
{
	errno = EACCES;
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(dir, 2);
	ft_putstr_fd(": Permission denied\n", 2);
}

void		short_opt_error(char *opt)
{
	errno = ENOENT;
	ft_putstr_fd("ls: unrecognized option `", 2);
	ft_putstr_fd(opt, 2);
	ft_putstr_fd("'\n", 2);
}

void		unrecognized_option_error(char *opt)
{
	errno = ENOENT;
	ft_putstr_fd("ls: unrecognized option `-", 2);
	ft_putstr_fd(opt, 2);
	ft_putstr_fd("'\n", 2);
}

void		invalid_option_error(char opt)
{
	errno = ENOENT;
	ft_putstr_fd("ls: invalid option -- ", 2);
	ft_putchar_fd(opt, 2);
	ft_putstr_fd("\n", 2);
}