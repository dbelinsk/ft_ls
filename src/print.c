/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:15:54 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/31 14:23:05 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void		print_ls_short(char *fname)
{
	ft_putstr(fname);
	ft_putstr("  ");
}

static void		print_ls_long(t_ls *node)
{
	ft_putstr(node->permissions);
	ft_putchar(' ');
	ft_putnbr_fd(node->hlinks, STDOUT_FILENO);
	ft_putchar(' ');
	ft_putstr(node->owner);
	ft_putchar(' ');
	ft_putstr(node->group);
	ft_putchar(' ');
	ft_putnbr_fd(node->size, STDOUT_FILENO);
	ft_putchar(' ');
	ft_putstr(node->ftime);
	ft_putchar(' ');
	ft_putstr(node->fname);
	ft_putchar('\n');
}

void		print_ls(t_ls *ls, t_opt *opt)
{
	t_ls *tmp;
	
	tmp = ls;
	while (tmp)
	{
		if (opt->l)
			print_ls_long(tmp);
		else
			print_ls_short(tmp->fname);
		tmp = tmp->next;
	}
	if (!opt->l)
		ft_putchar('\n');
}