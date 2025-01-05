/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:40:58 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/31 13:32:27 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <errno.h>

static void		set_short_opt(t_opt **opt, char *arg)
{
	int i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] == 'l')
			(*opt)->l = 1;
		else if (arg[i] == 'R')
			(*opt)->R = 1;
		else if (arg[i] == 'a')
			(*opt)->a = 1;
		else if (arg[i] == 'r')
			(*opt)->r = 1;
		else if (arg[i] == 't')
			(*opt)->t = 1;
		else
			return (short_opt_error(arg[i]));
		i++;
	}
}

static void		set_long_opt(t_opt **opt, char *arg)
{
	if (ft_strcmp(arg, "--all") == 0)
		(*opt)->a = 1;
	else if (ft_strcmp(arg, "--recursive") == 0)
		(*opt)->R = 1;
	else if (ft_strcmp(arg, "--reverse") == 0)
		(*opt)->r = 1;
	else if (ft_strcmp(arg, "--time") == 0)
		(*opt)->t = 1;
	else
		return (long_opt_error(arg));
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

static t_opt	*init_opt()
{
	t_opt *opt;
	
	if (!(opt = (t_opt*)malloc(sizeof(*opt))))
		return (NULL);
	opt->l = 0;
	opt->a = 0;
	opt->r = 0;
	opt->R = 0;
	opt->t = 0;
	return (opt);
}

void	set_opt(t_opt **opt, char **arg)
{
	if (!(*opt))
		if (!((*opt) = init_opt()))
			return ;
	for (int i = 0; arg[i] && !errno; i++)
	{
		if (ft_strcmp(arg[i], "--help") == 0)
			 return help();
		if (is_opt(arg[i]))
		{
			if (arg[i][0] == '-' && arg[i][1] != '-')
				set_short_opt(opt, arg[i]);
			else if (arg[i][0] == '-' && arg[i][1] == '-')
				set_long_opt(opt, arg[i]);
		}	
	}
}
	