/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:58:30 by dbelinsk          #+#    #+#             */
/*   Updated: 2025/01/09 13:26:55 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

static int			desc_cmp(char *cmp1, char *cmp2, char *path, int tcmp)
{
	if (!tcmp)
		return (ft_strcmp(cmp1, cmp2) > 0 ? 1 : 0);
	struct stat		st1;
	struct stat		st2;
	char			*tmp1;
	char			*tmp2;
	char			*aux;
	int				scmp;
	
	//printf("comparing %s and %s\n", cmp1, cmp2);
	scmp = ft_strcmp(cmp1, cmp2);
	if (!tcmp)
		return (scmp > 0 ? 1 : 0);
	aux = ft_strjoin(path, "/");
	tmp1 = ft_strjoin(aux, cmp1);
	tmp2 = ft_strjoin(aux, cmp2);
	if ( lstat(tmp1, &st1) < 0 || stat(tmp2, &st2) < 0)
	{
		free(tmp1);
		free(tmp2);
		free(aux);
		return (scmp < 0 ? 1 : 0);
	}
	free(tmp1);
	free(tmp2);
	free(aux);
	if (st1.st_mtime == st2.st_mtime)
		return (scmp > 0 ? 1 : 0);
	return (st1.st_mtime < st2.st_mtime ? 1 : 0);
}

static int			asc_cmp(char *cmp1, char *cmp2, char *path, int tcmp)
{
	if (!tcmp)
		return (ft_strcmp(cmp1, cmp2) < 0 ? 1 : 0);
	struct stat		st1;
	struct stat		st2;
	char			*tmp1;
	char			*tmp2;
	char			*aux;
	int				scmp;
	
	//printf("comparing %s and %s\n", cmp1, cmp2);
	scmp = ft_strcmp(cmp1, cmp2);
	if (!tcmp)
		return (scmp < 0 ? 1 : 0);
	aux = ft_strjoin(path, "/");
	tmp1 = ft_strjoin(aux, cmp1);
	tmp2 = ft_strjoin(aux, cmp2);
	if ( lstat(tmp1, &st1) < 0 || stat(tmp2, &st2) < 0)
	{
		free(tmp1);
		free(tmp2);
		free(aux);
		return (scmp < 0 ? 1 : 0);
	}
	if (st1.st_mtime == st2.st_mtime)
		return (scmp < 0 ? 1 : 0);
	return (st1.st_mtime > st2.st_mtime ? 1 : 0);
}

static int	get_in_point(char **arr, int size, char *f, int tcmp, char *path, int(*cmp)(char*, char*, char *, int))
{
	int		in_point;

	if (!arr)
		return (0);
	in_point = size / 2;
	if (cmp(f, arr[in_point], path, tcmp))
		while (in_point >= 0 && cmp(f, arr[in_point], path, tcmp))
			in_point--;
	else
		while (in_point < (size - 1) && !cmp(f, arr[in_point], path, tcmp))
			in_point++;
	if (in_point < 0 || (in_point < size && !cmp(f, arr[in_point], path, tcmp)))
		in_point++;
	return (in_point);
}

void			insert(char ***arr, int *size, char *fname, char *path, t_opt *opt)
{
	char 	**tmp;
	int		in_point;

	if (!(tmp = (char**)malloc(sizeof(char**) * (*size + 2))))
			return ;
	if (!opt->r)
		in_point = get_in_point(*arr, *size, fname,opt->t, path, asc_cmp);
	else
		in_point = get_in_point(*arr, *size, fname,opt->t, path, desc_cmp);
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