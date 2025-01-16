/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:16:29 by dbelinsk          #+#    #+#             */
/*   Updated: 2025/01/16 14:44:27 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
#include <stdio.h>
#include <time.h>
#include <sys/types.h>

#define N_LINK_PAD 0
#define UID_PAD 1
#define GID_PAD 2
#define SIZE_PAD 3
#define TOTAL_BLOCK 4

typedef struct s_opt{
	int l; 
	int a;
	int r;
	int R;
	int t;
} t_opt;

//OPTIONS
t_opt			*init_opt();
int				set_opt(t_opt **opt, char *arg);

//INSERT
void			insert(char ***arr, int *size, char *fname, t_opt *opt, int sub_dir);

//LS
void			ft_ls(t_opt *opt, char **arr, int size);

//INFO
void			set_permisions(char *perm, mode_t mode);
void			set_paddings(int *paddings, char *path, char **arr);

//PRINT
void			print_reg_file(char *path, int *paddings, int l);
void			print_dir(char **arr, int size, int *paddings, t_opt *opt);
void			print_header(char *fname, int total, int l, int size);

//ERRORS
void			path_error(char *dir);
void			permission_error(char *dir);
int				unrecognized_option_error(char *opt);
int				invalid_option_error(char opt);
int				usage_error();

//UTILS
void			format_time(char *ftime, time_t mtime);
int				get_nb_length(int nb);
char			*ft_strappend(char *dst, char *src);

#endif