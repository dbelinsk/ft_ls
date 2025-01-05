/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:59:07 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/31 15:03:27 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

static void		 set_permissions(char *permissions, const char *full_path, struct stat sb)
{
	ft_bzero(permissions, 11);
	if (S_ISDIR(sb.st_mode))
		permissions[0] = 'd';
	else if (S_ISLNK(sb.st_mode))
		permissions[0] = 'l';	
	else
		permissions[0] = '-';
	permissions[1] = (sb.st_mode & S_IRUSR) ? 'r' : '-';
	permissions[2] = (sb.st_mode & S_IWUSR) ? 'w' : '-';
	permissions[3] = (sb.st_mode & S_IXUSR) ? 'x' : '-';
	permissions[4] = (sb.st_mode & S_IRGRP) ? 'r' : '-';
	permissions[5] = (sb.st_mode & S_IWGRP) ? 'w' : '-';
	permissions[6] = (sb.st_mode & S_IXGRP) ? 'x' : '-';
	permissions[7] = (sb.st_mode & S_IROTH) ? 'r' : '-';
	permissions[8] = (sb.st_mode & S_IWOTH) ? 'w' : '-';
	permissions[9] = (sb.st_mode & S_IXOTH) ? 'x' : '-';
}

static void		set_file_info(t_ls *node, struct stat sb)
{
	set_permissions(node->permissions, node->path, sb);
	node->hlinks = sb.st_nlink;
	node->owner = ft_strdup(getpwuid(sb.st_uid)->pw_name);
	node->group = ft_strdup(getgrgid(sb.st_gid)->gr_name);
	node->size = sb.st_size;
	node->mtime = sb.st_mtime;
	format_time(node->ftime, sb.st_mtime);
}

static int			asc_abs(t_ls *cmp1, t_ls *cmp2, int tcmp)
{
	if (!tcmp)
		return (ft_strcmp(cmp1->fname, cmp2->fname) < 0);
	return (0);
}
static int			desc_abs(t_ls *cmp1, t_ls *cmp2, int tcmp)
{
	if (!tcmp)
		return (ft_strcmp(cmp1->fname, cmp2->fname) > 0);
	return (0);
}

static void			insert(t_ls **node, t_ls *new_node, int tcmp, int (*cmp)(t_ls*, t_ls*, int))
{
	t_ls	*tmp;

	tmp = *node;
	while (tmp && (*cmp)(tmp, new_node, tcmp))	
	{
		if (!tmp->next)
		{
			tmp->next = new_node;
			new_node->prev = tmp;
			new_node->next = NULL;
			return ;
		}
		tmp = tmp->next;
	}
	new_node->next = tmp;
	new_node->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = new_node;
	else
		*node = new_node;
	tmp->prev = new_node;
}

void		insert_node(t_ls **node, t_opt *opt, char *path, char *fname)
{
	struct stat		sb;
	t_ls			*new_node;
	t_ls			*tmp;
	char			*full_path;

	if (!(new_node = (t_ls*)malloc(sizeof(*new_node))))
			return ;
	
	full_path = ft_strjoin(path, fname);
	if (lstat(full_path, &sb) < 0)
		return (path_error(full_path));
	printf("block size: %ld\n", sb.st_blksize);
	printf("st block size: %ld\n", sb.st_blocks);
	new_node->fpath = full_path;
	new_node->path = ft_strdup(path);
	new_node->fname = ft_strdup(fname);
	set_file_info(new_node, sb);
	if (!(*node))
	{
		(*node) = new_node;
		(*node)->prev = NULL;
		(*node)->next = NULL;
		return ;
	}
	if (!opt->r)
		insert(node, new_node, opt->t, asc_abs);
	else
		insert(node, new_node, opt->t, desc_abs);
}