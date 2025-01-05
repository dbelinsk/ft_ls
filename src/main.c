/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:20:12 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/31 14:22:10 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <errno.h>

static int		clean_and_exit(t_opt *opt,t_ls *ls, int ret)
{
	t_ls *tmp;
	
	while (ls)
	{
		ft_free(ls->fpath);
		ft_free(ls->path);
		ft_free(ls->fname);
		ft_free(ls->owner);
		ft_free(ls->group);
		tmp = ls;
		ls = ls->next;
		ft_free(tmp);
	}
	if (opt)
		ft_free(opt);
	return (ret);
}

static int is_opt(char *arg)
{
	if (!arg || !ft_strlen(arg))
		return (0);
	if (ft_strlen(arg) == 1 && arg[0] == '-')
		return (0);
	if (arg[0] == '-')
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_opt 	*opt;
	t_ls	*ls;
	
	opt = NULL;
	ls = NULL;
	set_opt(&opt, av + 1);
	for (int i = 1; i < ac; i++)
	{
		if (is_opt(av[i]))
			continue ;
		insert_node(&ls, opt, "./", av[i]);
	}
	print_ls(ls, opt);
	return (clean_and_exit(opt,ls, errno));
}