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
# include <fcntl.h>
# include <limits.h>
# define OPTINOS "alrRtguc"
# define ARR_SIZE 10000

typedef struct		s_items
{
	struct dirent 	item;
	time_t			mtime;
	time_t			ctime;
	time_t			atime;

}					t_items;

typedef struct		s_content
{
	int				max;
	int				rows;
	t_items			arr[ARR_SIZE];
	int				size;
	int				w_size;
	long long		total;
	char			*location;
}					t_content;

int					ft_ls(char *location, char *oprtions);
void				sort_dirent_array(char *options, t_content *cont);
void				sort_dirent_array_rev(char *options, t_content *cont);
void				sort_dirent_array_u(t_content *cont);
void				sort_dirent_array_rev_u(t_content *cont);
void				sort_dirent_array_c(t_content *cont);
void				sort_dirent_array_rev_c(t_content *cont);
void				sort_by_name(char *options, t_content *cont);
void				sort_by_nano_mtime(t_content *cont, int start, int end);
void				create_cont(t_content **cont, char *location);
void				free_cont(t_content *cont);
void				print_long_format(char *location, char *options,
					t_content *cont);
int					has_option(char *options, char c);
char				*get_path(char *name, char *d_name);
void				listfiles(t_content *cont);
void				take_args(int argc, char **argv, char **location,
					char **options);
void				dirent_to_array(char *location, t_content *cont,
					char *options);
void				swap(t_items *arr, int left, int right);

int					compare_name(t_items *arr, int pointer, t_items *pivot);
int					compare_name_rev(t_items *arr, int pointer, t_items *pivot);
int					compare_ctime_rev(t_items *arr, int pointer, t_items *pivot);
int					compare_mtime_rev(t_items *arr, int pointer, t_items *pivot);
int					compare_atime_rev(t_items *arr, int pointer, t_items *pivot);
int					compare_ctime(t_items *arr, int pointer, t_items *pivot);
int					compare_atime(t_items *arr, int pointer, t_items *pivot);
int					compare_mtime(t_items *arr, int pointer, t_items *pivot);
void				partition(int left, int right, t_content *cont,
					int(*compare)(t_items*, int, t_items*));
int					t_items_qsort(int left, int right, t_items *pivot,
					t_items *arr, int(*compare)(t_items*, int, t_items*));

#endif
