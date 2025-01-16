/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:51:19 by dbelinsk          #+#    #+#             */
/*   Updated: 2025/01/16 14:47:16 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <libft.h>

char				*ft_strappend(char *dst, char *src)
{
	char			*s;

	if (!dst)
		return (ft_strdup(src));
	s = ft_strjoin(dst, src);
	free(dst);
	return (s);
}

int		get_nb_length(int nb)
{
	int		len;

	len = 1;
	while (nb /= 10)
		len++;
	return (len);
}

void		format_time(char *ftime, time_t mtime)
{
	time_t		time_now;
	char		*str;
	
	ft_bzero(ftime, 13);
	time_now = time(NULL);
	str = ctime(&mtime);
	ft_memcpy(ftime, str + 4, 7);
	if (time_now - mtime > 15552000)
		ft_memcpy(ftime + 7, str + 19, 5);
	else
		ft_memcpy(ftime + 7, str + 11, 5);
}