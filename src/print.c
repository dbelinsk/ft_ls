/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:15:54 by dbelinsk          #+#    #+#             */
/*   Updated: 2025/01/10 12:34:24 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <uuid/uuid.h>
#include <pwd.h>
#include <grp.h>


void			print_err_arr(char **arr)
{
	while (*arr)
		path_error(*(arr++));
}

void		print_short(char *fname)
{
	ft_putstr(fname);
	ft_putchar(' ');
}

void		print_long(char *path, char *fname)
{
	ft_putstr(fname);
	ft_putchar(' ');
}














static int	skip(t_opt *opt, struct stat sb, char *fname)
{
	if ((!opt->a && fname[0] == '.') || !S_ISDIR(sb.st_mode))
		return (1);
	if (ft_strlen(fname) == 1 && fname[0] == '.')
		return (1);
	if (ft_strlen(fname) == 2 && fname[0] == '.' && fname[1] == '.')
		return (1);
	return (0);
}

static void		print_ls_short(char *fname)
{
	ft_putstr(fname);
	ft_putchar(' ');
}

static void		print_ls_long(char *fname, char *path)
{
	struct stat	st;
	char		*tmp;
	char		*tmp2;
	char		fprot[11];
	char		ftime[13];
	char		lname[1024];

	tmp = ft_strjoin(path, "/");
	tmp2 = ft_strjoin(tmp, fname);
	if (lstat(tmp2, &st) == -1)
		return permission_error(fname);
	bzero(lname, 1024);
	readlink(tmp2, lname, 1024);
	free(tmp);
	free(tmp2);
	
	get_protection(fprot, st.st_mode);
	ft_putstr(fprot);
	ft_putchar(' ');
	ft_putnbr_fd(st.st_nlink, STDIN_FILENO);
	ft_putchar(' ');/* 
	ft_putnbr_fd(st.st_blocks, STDIN_FILENO);
	ft_putchar(' '); */
	ft_putstr(getpwuid(st.st_uid)->pw_name);
	ft_putchar(' ');
	ft_putstr(getgrgid(st.st_gid)->gr_name);
	ft_putchar(' ');
	ft_putnbr_fd(st.st_size, STDIN_FILENO);
	ft_putchar(' ');
	format_time(ftime, st.st_mtime);
	ft_putstr(ftime);
	ft_putchar(' ');
	ft_putstr(fname);
	if (fprot[0] == 'l')
	{
		ft_putstr(" -> ");
		ft_putstr(lname);
	}
		ft_putchar('\n');
}

static void			reset_arr(char ***arr, int *size)
{
	if (!*arr)
		return ;
	for(int i = 0; i < *size; i++)
		free((*arr)[i]);
	free(*arr);
	*arr = NULL;
	*size = 0;
}


void			print_reg_arr(char **arr, char *path, t_opt *opt)
{
	while (*arr)
	{
		if (!opt->l)
			print_ls_short(*(arr++));
		else
			print_ls_long(*(arr++), path);
	}
	//ft_putchar('\n');
}

static void		print_subdir_arr(char **arr, char *path, t_opt *opt)
{
	while (*arr)
	{
		if (!opt->l)
			print_ls_short(*(arr++));
		else
			print_ls_long(*(arr++), path);
	}
	//ft_putchar('\n');
}

void			print_dir_arr(char **arr, char *path, t_opt *opt)
{
	DIR				*dir;
	struct dirent	*entry;
	struct stat		st;
	char			**dir_arr;
	char			**reg_arr;
	
	int		dir_size;
	int		reg_size;
	int		f_type;
	
	char	*tmp;
	dir_arr = NULL;
	reg_arr = NULL;	
	dir_size = 0;
	reg_size = 0;
	while (arr && *arr)
	{
		tmp = ft_strjoin(path, *arr);
		lstat(tmp, &st);
		/* if (!S_ISDIR(st.st_mode))
		{
			arr++;
			free(tmp);
			continue;
		} */
		ft_putchar('\n');
		if (opt->R)
			ft_putstr(tmp);
		else
			ft_putstr(*arr);
		ft_putstr(":\n");
		//ft_putstr("total ");
		//ft_putnbr_fd(st.st_size, STDIN_FILENO);
		//ft_putchar('\n');
		if (!(dir = opendir(tmp)))
		{

			permission_error(*arr);
			free(tmp);
			arr++;
			continue ;
		}

		while ((entry  = readdir(dir)))
		{
			if (entry->d_name[0] == '.' && !opt->a)
				continue ;
			//f_type = get_file_type(tmp, entry->d_name, "/");
			//if (f_type == REG_FILE)
			//	insert(&reg_arr, &reg_size, entry->d_name, tmp, opt);
		//if (f_type == DIR_FILE)
			/* if (!opt->R) 
				insert(&dir_arr, &dir_size, entry->d_name, tmp, opt);
			else */
				insert(&dir_arr, &dir_size, entry->d_name, tmp, opt);
			
				
		}

		//if (reg_arr)
		//	print_reg_arr(reg_arr, tmp, opt);
		if (dir_arr)
			print_subdir_arr(dir_arr, tmp, opt);
		if (opt->R)
		{

			char *tmp2 = ft_strjoin(tmp, "/");
			if (!skip(opt, st, tmp2))
				print_dir_arr(dir_arr, tmp2, opt);
			free(tmp2);
		}
		
		free(tmp);
		reset_arr(&dir_arr, &dir_size);

		reset_arr(&reg_arr, &reg_size);
		closedir(dir);
		//if (opt->R)
		arr++;
	}
}

void		print_ls(t_opt *opt, char *path, char **err, char **reg, char **dir)
{
	if (err)
		print_err_arr(err);
	if (reg)
		print_reg_arr(reg, path, opt);
	if (dir)
		print_dir_arr(dir, path, opt);
}