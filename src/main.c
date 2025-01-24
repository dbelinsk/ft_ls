/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:20:12 by dbelinsk          #+#    #+#             */
/*   Updated: 2025/01/24 11:46:54 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <errno.h>

static int		clean_and_exit(t_opt *opt, char **arr, int ret)
{
	if (opt)
		free(opt);
	if (!arr)
		return (ret);
	for (int i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
	return (ret);
}

int		main(int ac, char **av)
{
	t_opt 	*opt;
	char	**arr;
	int		arr_size;
	int 	i;
	
	(void)ac;
	opt = init_opt();
	arr = NULL;
	arr_size = 0;
	i = 1;
	while (av[i] && ft_strlen(av[i]) > 1 && av[i][0] == '-' )
	{
		if (!set_opt(&opt, av[i++]))
			return (clean_and_exit(opt,arr, errno));
	}
	while (av[i])
		insert(&arr, &arr_size, av[i++], opt, 1);
	if (!arr)
		insert(&arr, &arr_size, ".", opt, 1);
	ft_ls(opt, arr, arr_size);
	return (clean_and_exit(opt,arr, errno));
}