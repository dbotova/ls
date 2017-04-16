/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:34:02 by dbotova           #+#    #+#             */
/*   Updated: 2017/02/27 15:34:04 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		is_dir(char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) == -1)
	{
		perror(path);
		exit(1);
	}
	if (S_ISDIR(statbuf.st_mode))
		return (1);
	else
		return (0);
}

static void		listdir(char *location, char *options, t_content *cont)
{
	int			i;
	char		*path;

	i = 0;
	path = (char*)malloc(sizeof(char) * 1024);
	while (i < cont->size)
	{
		path = ft_strdup(get_path(location, cont->arr[i].item.d_name));
		if (is_dir(path) && ft_strcmp(cont->arr[i].item.d_name, ".") != 0 &&
			ft_strcmp(cont->arr[i].item.d_name, "..") != 0)
		{
			ft_printf("\n%s/%s:\n", location, cont->arr[i].item.d_name);
			if (ft_strcmp(location, ".") == 0)
				ft_ls(cont->arr[i].item.d_name, options);
			else
				ft_ls(path, options);
		}
		i++;
	}
}

int				ft_ls(char *location, char *options)
{
	t_content	*cont;

	create_cont(&cont, location);
	dirent_to_array(location, cont, options);
	if (cont->size == 0)
		return (0);
	if (has_option(options, 't'))
		sort_dirent_array(options, cont);
	else
		sort_by_name(options, cont);
	if (has_option(options, 'l') || has_option(options, 'g'))
		print_long_format(location, options, cont);
	else
		listfiles(cont);
	if (has_option(options, 'R'))
		listdir(location, options, cont);
	free_cont(cont);
	return (0);
}
