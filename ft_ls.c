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

static void get_path(char *path, char *name, char *d_name)
{
    ft_memset(path, 0, 1024);
    ft_strcpy(path, name);
    ft_strcat(path, "/");
    ft_strcat(path, d_name);
}

static int	is_dir(char *path)
{
	struct stat statbuf;
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

void	ft_ls(char *location, char *options)
{
	int size;
	t_content *cont;
	cont = malloc(sizeof(t_content));
	int i;

	i = 0;
	dirent_to_array(location, cont, options);
	if (ft_strchr(options, 't'))
		sort_dirent_array(cont);
	listfiles(location, options, cont);
	if (ft_strchr(options, 'R'))
	{
		while (i < cont->size)
		{
			get_path(cont->path, location, cont->arr[i].d_name);
			if (is_dir(cont->arr[i].d_name))
			{
				ft_printf("\n%s:\n", cont->path);
				if (*location == '.' && ft_strlen(location) == 1)
					ft_ls(cont->arr[i].d_name, options);
				else
					ft_ls(cont->path, options);
			}
			i++;
		}
	}
	SMART_FREE(cont);
	exit(0);
}
