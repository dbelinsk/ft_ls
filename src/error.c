/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:51:51 by dbelinsk          #+#    #+#             */
/*   Updated: 2025/01/20 13:49:58 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

void		path_error(char *dir)
{
	errno = 1;
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(dir, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void		permission_error(char *dir)
{
	errno = 1;
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(dir, 2);
	ft_putstr_fd(": Permission denied\n", 2);
}

int			unrecognized_option_error(char *opt)
{
	errno = 1;
	ft_putstr_fd("ls: unrecognized option `-", 2);
	ft_putstr_fd(opt, 2);
	ft_putstr_fd("'\n", 2);
	ft_putstr_fd("usage: ls [-Ralrt] [file ...]\n", 2);
	return 0;
}

int			usage_error()
{
	errno = 1;
	ft_putstr_fd("usage: ls [-Ralrt] [file ...]\n", 2);
	return 0;
}

int			invalid_option_error(char opt)
{
	errno = 1;
	ft_putstr_fd("ls: invalid option -- ", 2);
	ft_putchar_fd(opt, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("usage: ls [-Ralrt] [file ...]\n", 2);
	return 0;
}