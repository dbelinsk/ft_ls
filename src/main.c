/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:20:12 by dbelinsk          #+#    #+#             */
/*   Updated: 2025/01/10 12:33:28 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <errno.h>

static void 	clean_arr(char **arr)
{
	if (!arr)
		return ;
	for (int i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}

static int		clean_and_exit(t_opt *opt, char **arr, char **arr2, char **arr3, int ret)
{
	clean_arr(arr);
	clean_arr(arr2);
	clean_arr(arr3);
	if (opt)
		free(opt);
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
	char	**err_arr;
	char	**reg_arr;
	char	**dir_arr;
	
	int 	err_size;
	int		reg_size;
	int		dir_size;
	int 	i;
	int		f_type;
	
	opt = init_opt();
	err_arr = NULL;
	reg_arr = NULL;
	dir_arr = NULL;
	err_size = 0;
	reg_size = 0;
	dir_size = 0;
	i = 1;
	/* if (ac == 1)
	{
		insert(&dir_arr, &dir_size, ".", ".", opt);
		print_dir_arr(dir_arr, "", opt);
		return (clean_and_exit(opt, NULL, NULL, NULL, errno));
	}
	else
	{
		 */
		while (av[i] && ft_strlen(av[i]) > 1 && av[i][0] == '-' )
			set_opt(&opt, av[i++]);
		while (av[i])
		{
			f_type = get_file_type("./", av[i], NULL);
			if (f_type == ERR_FILE)
				insert(&err_arr, &err_size, av[i], ".", opt);
			else if (f_type == REG_FILE)
				insert(&reg_arr, &reg_size, av[i], ".", opt);
			else if (f_type == DIR_FILE)
				insert(&dir_arr, &dir_size, av[i], ".", opt);
			i++;
		}
	//	if (!reg_arr && !dir_arr)
	//		insert(&dir_arr, &dir_size, ".", ".", opt);
	//}
	if (!dir_arr && !reg_arr && !err_arr)
		insert(&dir_arr, &dir_size, ".", ".", opt);
	print_ls(opt, "./", err_arr, reg_arr, dir_arr);
	return (clean_and_exit(opt,err_arr, reg_arr, dir_arr, errno));
}