/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:40:58 by dbelinsk          #+#    #+#             */
/*   Updated: 2025/01/20 14:06:51 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>

static int		add_opt(t_opt **opt, char *arg)
{
	if (!ft_strcmp(arg, "--"))
		return (1);
	while (*(++arg))
	{
		if (*arg == 'l')
			(*opt)->l = 1;
		else if (*arg == 'R')
			(*opt)->R = 1;
		else if (*arg == 'a')
			(*opt)->a = 1;
		else if (*arg == 'r')
			(*opt)->r = 1;
		else if (*arg == 't')
			(*opt)->t = 1;
		else if (*arg == '-')
		{
			if (!*(arg + 1))
				return (usage_error());
			else
				return (unrecognized_option_error(arg));
		}
		else
			return (invalid_option_error(*arg));
	}
	return (1);
}

t_opt	*init_opt()
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

int	set_opt(t_opt **opt, char *arg)
{
	if (!(*opt))
		if (!((*opt) = init_opt()))
			return 0;
	return (add_opt(opt, arg));
}
	