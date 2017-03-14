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
# include "./libft/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <grp.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# define OPTINOS "alrRtguc"
# define ARR_SIZE 10000

typedef struct		s_content
{
	int				max;
	int				rows;
	struct dirent	arr[ARR_SIZE];
	int				size;
	int				w_size;
	char			*location;
}					t_content;

int					ft_ls(char *location, char *oprtions);
void				sort_dirent_array(char *options, t_content *cont);
void				sort_dirent_array_rev(char *options, t_content *cont);
void				sort_dirent_array_u(t_content *cont);
void				sort_dirent_array_rev_u(t_content *cont);
void				sort_dirent_array_c(t_content *cont);
void				sort_dirent_array_rev_c(t_content *cont);
void				sort_by_name(t_content *cont);
void				sort_by_name_rev(t_content *cont);
void				create_cont(t_content **cont, char *location);
void				free_cont(t_content *cont);
void				print_long_format(char *location, char *options,
					t_content *cont);
int					has_option(char *options, char c);
char				*get_path(char *name, char *d_name);
void				listfiles(char *location, char *oprtions, t_content *cont);
void				take_args(char *arg1, char *arg2, char **location,
					char **options);
void				dirent_to_array(char *location, t_content *cont,
					char *options);

#endif
