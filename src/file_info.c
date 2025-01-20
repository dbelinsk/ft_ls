/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:47:09 by dbelinsk          #+#    #+#             */
/*   Updated: 2025/01/20 12:28:52 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <pwd.h>
#include <grp.h>

void		set_permisions(char *perm, mode_t mode)
{
	if (S_ISDIR(mode))
		perm[0] = 'd';
	else if (S_ISLNK(mode))
		perm[0] = 'l';	
	else
		perm[0] = '-';
	perm[1] = (mode & S_IRUSR) ? 'r' : '-';
	perm[2] = (mode & S_IWUSR) ? 'w' : '-';
	perm[3] = (mode & S_IXUSR) ? 'x' : '-';
	perm[4] = (mode & S_IRGRP) ? 'r' : '-';
	perm[5] = (mode & S_IWGRP) ? 'w' : '-';
	perm[6] = (mode & S_IXGRP) ? 'x' : '-';
	perm[7] = (mode & S_IROTH) ? 'r' : '-';
	perm[8] = (mode & S_IWOTH) ? 'w' : '-';
	perm[9] = (mode & S_IXOTH) ? 'x' : '-';
	perm[10] = '\0';
}

void			set_paddings(int *paddings, char *path, char **arr)
{
	struct stat				st;
	int						len;
	struct passwd			*uid;
	struct group			*gid;

	ft_bzero(paddings, sizeof(int) * 5);
	while (arr && *arr)
	{
		if (!lstat(*arr, &st))
		{
			if (!path && S_ISDIR(st.st_mode))
				break;
			if (get_nb_length(st.st_nlink) > paddings[N_LINK_PAD])
				paddings[N_LINK_PAD] = get_nb_length(st.st_nlink);
			if (!(uid = getpwuid(st.st_uid)))
			{
				if ((len = get_nb_length(st.st_uid)) > paddings[UID_PAD])
					paddings[UID_PAD] = len;
			}
			else if((len = ft_strlen(getpwuid(st.st_uid)->pw_name)) > paddings[UID_PAD])
				paddings[UID_PAD] = len;

			if (!(gid = getgrgid(st.st_gid)))
			{
				if ((len = get_nb_length(st.st_gid)) > paddings[GID_PAD])
					paddings[GID_PAD] = len;
			}
			else if ((len = ft_strlen(getgrgid(st.st_gid)->gr_name)) > paddings[GID_PAD])
				paddings[GID_PAD] = len;
			if (get_nb_length(st.st_size) > paddings[SIZE_PAD])
				paddings[SIZE_PAD] = get_nb_length(st.st_size);
			paddings[TOTAL_BLOCK] += st.st_blocks;
		}
		arr++;
	}
}