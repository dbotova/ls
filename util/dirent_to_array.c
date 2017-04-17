/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirent_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 19:59:24 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/01 19:59:25 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static	void		take_time(char *location, char *path, t_content *cont,
					int i)
{
	char			*full_path;
	struct stat		statbuf;

	full_path = get_path(location, path);
	stat(full_path, &statbuf);
	cont->arr[i].mtime = statbuf.st_mtimespec;
	cont->arr[i].atime = statbuf.st_atimespec;
	cont->arr[i].ctime = statbuf.st_ctimespec;
	SMART_FREE(full_path);

}

int					dir_stat(char *location, char *path, struct stat *buf)
{
	int				result;
	char			*full_path;

	full_path = get_path(location, path);
	result = stat(full_path, buf);
	if (result == -1)
		perror(full_path);
	SMART_FREE(full_path);
	return (result);
}

void				dirent_to_array(char *location, t_content *cont,
					char *options)
{
	DIR				*dir;
	struct dirent	*d;
	int				i;
	struct stat		buf;

	i = 0;
	dir = opendir(location);
	if (!dir)
	{
		ft_printf("ft_ls: %s: ", location);
		perror("");
		exit(1);
	}
	while ((d = readdir(dir)) != NULL)
	{
		if (dir_stat(location, d->d_name, &buf) == -1)
			exit(1);
		if (d->d_name[0] != '.' || has_option(options, 'a'))
		{
			cont->arr[i].item = *d;
			cont->total += buf.st_blocks;
			take_time(location, d->d_name, cont, i++);
		}
	}
	closedir(dir);
	cont->size = i;
}
