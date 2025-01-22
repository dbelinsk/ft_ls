/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:50:42 by dbelinsk          #+#    #+#             */
/*   Updated: 2025/01/22 14:50:59 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>


static void		put_nb(int nb, int maxLen)
{
	int		len;
	
	len = get_nb_length(nb);
	while (len++ < maxLen)
		ft_putchar(' ');
	ft_putnbr_fd(nb, 1);
	ft_putchar(' ');
}

static void		put_str(char *str, int maxLen)
{
	int		len;
	
	len = ft_putstr(str);
	while (len++ < maxLen)
		ft_putchar(' ');
	ft_putchar(' ');
}

static void		put_perm(mode_t mode)
{
	char		perm[11];

	set_permisions(perm, mode);
	ft_putstr(perm);
	ft_putchar(' ');
}

static void		put_uid(uid_t uid, int maxLen)
{
	struct passwd	*pwd;

	if (!(pwd = getpwuid(uid)))
		put_nb(uid, maxLen);
	else
		put_str(pwd->pw_name, maxLen);
}

static void		put_gid(gid_t gid, int maxLen)
{
	struct group	*grp;
	
	if (!(grp = getgrgid(gid)))
		put_nb(gid, maxLen);
	else
		put_str(grp->gr_name, maxLen);
}

static void		put_time(time_t time)
{
	char		ftime[13];

	format_time(ftime, time);
	ft_putstr(ftime);
	ft_putchar(' ');
}

static void		put_fname(char *fpath, mode_t mode)
{
	char		lname[1024];
	char		*name;

	name = ft_strrchr(fpath, '/');
	name ? ft_putstr(name + 1) : ft_putstr(fpath);
	if (S_ISLNK(mode))
	{
		ft_bzero(lname, 1024);
		readlink(fpath, lname, 1024);
		ft_putstr(" -> ");
		ft_putstr(lname);
	}
}

static void		plong(char *path, int *paddings)
{
	struct stat	st;

	lstat(path, &st);
	put_perm(st.st_mode);
	put_nb(st.st_nlink, paddings[N_LINK_PAD]);
	put_uid(st.st_uid, paddings[UID_PAD]);
	put_gid(st.st_gid, paddings[GID_PAD]);
	put_nb(st.st_size, paddings[SIZE_PAD]);
	put_time(st.st_mtime);
	put_fname(path, st.st_mode);
	//ft_putchar('\n');
}

static void		pshort(char *fname)
{
	char	*name;

	name = ft_strrchr(fname, '/');
	name ? ft_putstr(name + 1) : ft_putstr(fname);
	//ft_putchar(' ');
}

void		print_header(char *fname, int total, int l, int size)
{
	if (size > 1)
	{
		ft_putstr(fname);
		ft_putstr(":\n");
	}
	if (l)
	{
		ft_putstr("total ");
		ft_putnbr_fd(total, 1);
		ft_putchar('\n');
	}
}

void		print_reg_file(char *fname, int *paddings, int l)
{
	if (l)
		plong(fname, paddings);
	else
		pshort(fname);
}

void		print_dir(char **arr, int size, int *paddings, t_opt *opt)
{
	char	c;
	while (arr && *arr)
	{
		print_reg_file(*(arr++), paddings, opt->l);
		opt->l ? (c = '\n') : (c = ' ');
		if (*arr)
			ft_putchar(c);
	}
	opt->R && size ? ft_putstr("\n") : 0;
}