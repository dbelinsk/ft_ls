/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:51:00 by dbelinsk          #+#    #+#             */
/*   Updated: 2025/01/23 12:59:38 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

static void			clean_arr(char **arr, int size)
{
	int i;
	if (!arr)
		return;
	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}

static int				set_stat(struct stat *st, char *fname)
{
	if (lstat(fname, st) == -1)
	{
		path_error(fname);
		return (0);
	}
	return (1);
}

static DIR				*get_dir(char *fname, int l, int size)
{
	DIR		*dir;

	if (!(dir = opendir(fname)))
	{
		print_header(fname, 0, l, size);
		permission_error(fname);
		return (NULL);
	}
	return (dir);
}

static void			recursive(t_opt *opt, char **arr, int size)
{
	DIR				*dir;
	struct dirent	*entry;
	struct stat		st;
	char			**aux;
	int				aux_size;
	char			*new_path;
	char			*fname;
	int				paddings[5];

	for (int i = 0; i < size; i++)
	{
		aux = NULL;
		aux_size = 0;
		if (!set_stat(&st, arr[i]) || !S_ISDIR(st.st_mode) || S_ISLNK(st.st_mode))
			continue;
		fname = ft_strrchr(arr[i], '/');
		fname ? fname++ : fname;
		if (fname && (!ft_strcmp(fname, ".") || !ft_strcmp(fname, "..")))
			continue;
		ft_putchar('\n');
		if (!(dir = opendir(arr[i])))
		{
			print_header(arr[i], 0, opt->l, size);
			permission_error(arr[i]);
			continue;
		}
		while ((entry = readdir(dir)))
		{
			if (entry->d_name[0] == '.' && !opt->a)
				continue;
			
			new_path = ft_strjoin(arr[i], "/");
			new_path = ft_strappend(new_path, entry->d_name);
			insert(&aux, &aux_size, new_path, opt, 0);
			free(new_path);
		}
		closedir(dir);
		set_paddings(paddings, arr[i], aux);
		print_header(arr[i], paddings[TOTAL_BLOCK], opt->l, 2);
		print_dir(aux, aux_size, paddings, opt);
		recursive(opt, aux, aux_size);
		clean_arr(aux, aux_size);
	}
}

static int				list_dir_v2(t_opt *opt, char *name, int *paddings, int size)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**arr;
	int				arr_size;
	char			*fpath;

	if (!(dir = get_dir(name, opt->l, size)))
		return 0;
	arr = NULL;
	arr_size = 0;
	while ((entry = readdir(dir)))
	{
		if (entry->d_name[0] == '.' && !opt->a)
			continue;
		fpath = ft_strjoin(name, "/");
		fpath = ft_strappend(fpath, entry->d_name);
		if (fpath[0] && fpath[0] == '/' && fpath[1] && fpath[1] == '/')
			insert(&arr, &arr_size, fpath + 1, opt, 0);
		else
			insert(&arr, &arr_size, fpath, opt, 0);
		free(fpath);
	}
	set_paddings(paddings, name, arr);
	print_header(name, paddings[TOTAL_BLOCK], opt->l, size);
	print_dir(arr, arr_size, paddings, opt);
	closedir(dir);
	if (opt->R)
		recursive(opt, arr, arr_size);
	clean_arr(arr, arr_size);
	return (arr_size);
}

void					ft_ls(t_opt *opt, char **arr, int size)
{
	struct stat		st;
	struct stat		st2;
	int				paddings[5];
	int				i;
	int				nl;

	set_paddings(paddings, NULL, arr);
	i = 0;
	nl = 0;
	while (arr && arr[i])
	{
		if (set_stat(&st, arr[i]))
		{
			
			if (S_ISDIR(st.st_mode))
				break;
			print_reg_file(arr[i++], paddings, opt->l);
			if (arr[i] && !lstat(arr[i], &st2) && !S_ISDIR(st2.st_mode))
				!opt->l ? ft_putchar(' ') : ft_putchar('\n');
			nl = 1;
			continue ;
		}	
		i++;
	}
	nl ? ft_putchar('\n') : 0;
	nl && opt->R && arr[i]? ft_putchar('\n') : 0;
	while (arr && arr[i])
	{
		nl && !opt->R ? ft_putchar('\n') : 0;
		if (list_dir_v2(opt, arr[i++], paddings, size) && !opt->R)
			ft_putchar('\n');
		opt->R && size > 1 && arr[i] ? ft_putchar('\n') : 0;
		nl = 1;
	}
		
}