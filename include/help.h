/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:49:26 by dbelinsk          #+#    #+#             */
/*   Updated: 2024/12/31 13:14:23 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_H
# define HELP_H


# define HELP_USAGE "Usage: ls [OPTION]... [FILE]...\n"
# define HELP_INFO "List information about the FILEs (the current directory by default).\n\n"
# define OPT_L "-l\t\t\tuse a long listing format\n"
# define OPT_A "-a, --all\t\tinclude directory entries whose names begin with a dot\n"
# define OPT_R "-r, --reverse\t\treverse order while sorting\n"
# define OPT_T "-t\t\t\tsort by modification time, newest first\n"
# define OPT_R_CAP "-R, --recursive\tlist subdirectories recursively\n"
# define HELP_OPTIONS "Options:\n  "OPT_L"  "OPT_A"  "OPT_R"  "OPT_T"  "OPT_R_CAP"\n"
# define HELP_EXAMPLES	"Examples:\n  ls -l /usr\n  ls -l /usr /bin\n\n"
# define STATUS_1	"0  if OK,\n"
# define STATUS_2	"1  if minor problems (e.g., cannot access subdirectory),\n"
# define STATUS_3	"2  if serious trouble (e.g., cannot access command-line argument)."
# define HELP_EXIT_STATUS	"Exit status:\n  "STATUS_1"  "STATUS_2"  "STATUS_3"\n"

#endif