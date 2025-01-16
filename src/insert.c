/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:58:30 by dbelinsk          #+#    #+#             */
/*   Updated: 2025/01/16 14:36:59 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

static int			cmp(char *cmp1, char *cmp2, t_opt *opt, int sub_dir)
{
	struct stat		st1;
	struct stat		st2;
	int				rst1;
	int				rst2;
	
	if (sub_dir)
	{
		rst1 = lstat(cmp1, &st1);
		rst2 = lstat(cmp2, &st2);
		if ( rst1 < 0 || rst2 < 0)
		{
			if (rst1 < 0 && rst2 < 0)
				return (opt->r ? ft_strcmp(cmp2, cmp1) : ft_strcmp(cmp1, cmp2));
			return (opt->r ? rst2 : rst1);
		}
		if (!S_ISDIR(st1.st_mode) || !S_ISDIR(st2.st_mode))
		{
			if (!S_ISDIR(st1.st_mode) && !S_ISDIR(st2.st_mode))
				return (opt->r ? ft_strcmp(cmp2, cmp1) : ft_strcmp(cmp1, cmp2));
			return (opt->r ? (S_ISDIR(st2.st_mode) ? 0 : -1) : (S_ISDIR(st1.st_mode) ? 0 : -1));	
		}
	}
	if (!opt->t)
		return (opt->r ? ft_strcmp(cmp2, cmp1) : ft_strcmp(cmp1, cmp2));
	rst1 = lstat(cmp1, &st1);
	rst2 = lstat(cmp2, &st2);
	if (st1.st_mtime == st2.st_mtime)
		return (opt->r ? ft_strcmp(cmp2, cmp1) : ft_strcmp(cmp1, cmp2));
	return (opt->r ? st1.st_mtime - st2.st_mtime : st2.st_mtime - st1.st_mtime);
}

static int		get_in_point(char **arr, int size, char *fname, int sub_dir, t_opt *opt)
{
	int		low;
	int		high;
	int		mid;

	if (!arr)
		return 0;
	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);
		cmp(fname, arr[mid], opt, sub_dir) < 0 ? (high = mid - 1) : (low = mid + 1);
	}
	return low;
}

void			insert(char ***arr, int *size, char *fname, t_opt *opt, int sub_dir)
{
	char 	**tmp;
	int		in_point;

	if (!(tmp = (char**)malloc(sizeof(char**) * (*size + 2))))
			return ;
	in_point = get_in_point(*arr, *size, fname, sub_dir, opt);
	tmp[in_point] = ft_strdup(fname);
	if (*arr)
	{
		ft_memcpy(tmp, *arr, sizeof(char**) * in_point);
		ft_memcpy(tmp + in_point + 1, *arr + in_point, sizeof(char**) * (*size - in_point));
		free(*arr);
	}
	*arr = tmp;
	(*arr)[++(*size)] = NULL;
}