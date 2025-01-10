/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:26:41 by dbelinsk          #+#    #+#             */
/*   Updated: 2025/01/08 14:16:16 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>


static char	*get_file(char *path, char *fname)
{
	struct stat	st;
	char		*tmp;

	tmp = ft_strjoin(path, fname);
	if (lstat(tmp, &st) == -1)
	{
		free(tmp);
		path_error(fname);
		return (NULL);
	}
	free(tmp);
	return (ft_strdup(fname));
}

/* static int			desc_cmp(char *cmp1, char *cmp2, int tcmp)
{
	if (!tcmp)
		return (ft_strcmp(cmp1, cmp2) > 0);
	return (0);
}

static int			asc_cmp(char *cmp1, char *cmp2, int tcmp)
{
	if (!tcmp)
		return (ft_strcmp(cmp1, cmp2) < 0);
	return (0);
} */

static void		insert_second(char ***arr, char **tmp, int *size, char *f)
{
	
	if (ft_strcmp(f, (*arr)[0]) < 0)
		{
			tmp[0] = f;
			tmp[1] = (*arr)[0];
		}
		else
		{
			tmp[0] = (*arr)[0];
			tmp[1] = f;
		}
		free(*arr);
		*arr = (tmp);
		(*arr)[++(*size)] = NULL;
}

static int	get_mid(char **arr, int size, int mid, char *f)
{
	if (ft_strcmp(f, arr[mid]) < 0)
			while (mid >= 0 && ft_strcmp(f, arr[mid]) < 0)
				mid--;
	else
		while (mid < (size - 1) && ft_strcmp(f, arr[mid]) > 0)
			mid++;
	if (mid < size && ft_strcmp(f, arr[mid]) > 0 )
		mid++;
	return (mid);
}

static void	insert_asc(char ***arr, char *fname, char *path, int *size)
{
	char	**tmp;
	char	*f;
	int		mid;

	if (!(f = get_file(path, fname)))
		return ;
	if (!(tmp = (char**)malloc(sizeof(char**) * (*size + 2))))
			return ;
			
	mid = (*size) / 2;
	if (!mid)
		insert_second(arr, tmp, size, f);
	else
	{
		mid = get_mid(*arr, *size, mid, f);
		ft_memcpy(tmp, *arr, sizeof(char**) * mid);
		tmp[mid] = f;
		ft_memcpy(tmp + mid + 1, *arr + mid, sizeof(char**) * (*size - mid));
		free(*arr);
		*arr = tmp;
		(*arr)[++(*size)] = NULL;
	}
}

/* static void	insert(char ***arr, char *fname, char *path, int *size, int (*cmp)(char*, char*, int))
{
	char	**tmp;
	char	*f;
	int		mid;

	if (!(f = get_file(path, fname)))
		return ;
	if (!(tmp = (char**)malloc(sizeof(char**) * (*size + 2))))
			return ;
			
	mid = (*size) / 2;
	if (!mid)
	{
		if (cmp(f, (*arr)[0], 0))//ft_strcmp(f, (*arr)[0]) < 0)
		{
			tmp[0] = f;
			tmp[1] = (*arr)[0];
		}
		else
		{
			tmp[0] = (*arr)[0];
			tmp[1] = f;
		}
		free(*arr);
		*arr = (tmp);
		(*arr)[++(*size)] = NULL;
	}
	else
	{
		if (cmp(f, (*arr)[0], 0))
			while (mid >= 0 && cmp(f, (*arr)[0], 0))
				mid--;
		else
			while (mid < ((*size) - 1) && !cmp(f, (*arr)[0], 0))
				mid++;
		if (mid < (*size) && !cmp(f, (*arr)[0], 0))
			mid++;
		ft_memcpy(tmp, *arr, sizeof(char**) * mid);
		tmp[mid] = f;
		ft_memcpy(tmp + mid + 1, *arr + mid, sizeof(char**) * ((*size )- mid));
		free(*arr);
		*arr = tmp;
		(*arr)[++(*size)] = NULL;
	}
} */

char		**init_arr(int *size)
{
	char	**arr;


	*size = 0;
	if (!(arr = (char**)malloc(sizeof(char**) + 2)))
		return (NULL);
	arr[0] = NULL;
	return (arr);
}



void	insert_file(char ***arr, char *fname, char *path, int *size, t_opt *opt)
{
	char	*f;
	
	if (!*size)
	{
		if ( !(f = get_file(path, fname)))
			return ;
		int x = *size;
		(*arr)[x] = f;
		(*arr)[++x] = NULL;
		*size = x;
	}
	else
	{
		if (!opt->r)
			insert_asc(arr, fname, path, size);
			//insert(arr, fname, path, size, asc_cmp);
		//else
		//	insert(arr, fname, path, size, desc_cmp);
	}
}