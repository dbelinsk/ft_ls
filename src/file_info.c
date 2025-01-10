/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:47:09 by dbelinsk          #+#    #+#             */
/*   Updated: 2025/01/09 12:22:52 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>
#include <sys/types.h>

int			get_file_type(char *path, char *fname, char *sep)
{
	struct stat		st;
	char			*tmp;
	char			*tmp2;
	
	if (!sep)
		tmp = ft_strjoin(path, fname);
	else
	{
		tmp2 = ft_strjoin(path, sep);
		tmp = ft_strjoin(tmp2, fname);
		free(tmp2);	
	}
	if (lstat(tmp, &st) == -1)
	{
		printf("error: %s\n", tmp);
		free(tmp);
		return (ERR_FILE);
	}
	free(tmp);
	if (S_ISDIR(st.st_mode))
		return (DIR_FILE);
	return (REG_FILE);
}

void		get_protection(char *fprot, mode_t mode)
{
	if (S_ISDIR(mode))
		fprot[0] = 'd';
	else if (S_ISLNK(mode))
		fprot[0] = 'l';	
	else
		fprot[0] = '-';
	fprot[1] = (mode & S_IRUSR) ? 'r' : '-';
	fprot[2] = (mode & S_IWUSR) ? 'w' : '-';
	fprot[3] = (mode & S_IXUSR) ? 'x' : '-';
	fprot[4] = (mode & S_IRGRP) ? 'r' : '-';
	fprot[5] = (mode & S_IWGRP) ? 'w' : '-';
	fprot[6] = (mode & S_IXGRP) ? 'x' : '-';
	fprot[7] = (mode & S_IROTH) ? 'r' : '-';
	fprot[8] = (mode & S_IWOTH) ? 'w' : '-';
	fprot[9] = (mode & S_IXOTH) ? 'x' : '-';
	fprot[10] = '\0';
}