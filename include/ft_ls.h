/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:16:29 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/31 14:22:01 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
#include <stdio.h>
#include <time.h>

#define OK 0
#define KO 1

typedef struct s_opt{
	int l; //1
	int a;
	int r;
	int R;
	int t;
} t_opt;

typedef struct s_ls{				
	char			*fpath;
	char			*path;
	char			permissions[11];
	int				hlinks;
	char			*owner;
	char			*group;
	int				size;
	time_t			mtime;
	char			*fname;
	char			ftime[13];
	struct s_ls		*next;
	struct s_ls		*prev;
} t_ls;

void		help(void);

void		path_error(char *dir);
void		permission_error(char *dir);
void		short_opt_error(char opt);
void		long_opt_error(char *opt);

void		set_opt(t_opt **opt, char **arg);

void		insert_node(t_ls **node, t_opt *opt, char *path, char *fname);


void		print_ls(t_ls *ls, t_opt *opt);

void		format_time(char *ftime, time_t mtime);

#endif