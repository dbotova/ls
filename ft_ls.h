/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:34:09 by dbotova           #+#    #+#             */
/*   Updated: 2017/02/27 15:34:11 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <grp.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# define OPTINOS "alrRt"
# define ARR_SIZE 1000

typedef struct	s_content
{
	int			max;
	char 		path[1024];
	int 		rows;
	struct 		dirent arr[ARR_SIZE];
	int 		size;
	int			total;
	int			w_size;
}				t_content;

int		ft_ls(char *location, char *oprtions);
void	sort_dirent_array(t_content *cont);
void	create_cont(t_content *cont); //fix
void	print_long_format(t_content *cont);
void	listfiles(char *location, char *oprtions, t_content *cont);
void	take_args(char *arg1, char *arg2, char **location, char **options);
void	dirent_to_array(char *location, t_content *cont, char *options);

#endif
