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

static void		get_path(char *path, char *name, char *d_name)
{
    ft_memset(path, 0, 1024);
	ft_strcpy(path, name);
	if (name[ft_strlen(name) -1] != '/')
		ft_strcat(path, "/");
    ft_strcat(path, d_name);
}

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

	i = 0;
	while (i < cont->size)
	{
		get_path(cont->path, location, cont->arr[i].d_name);
		if (is_dir(cont->path) && ft_strcmp(cont->arr[i].d_name, ".") != 0 &&
			ft_strcmp(cont->arr[i].d_name, "..") != 0)
		{
			ft_printf("\n%s/%s:\n", location, cont->arr[i].d_name); //FIX
			if (ft_strcmp(location, ".") == 0)
				ft_ls(cont->arr[i].d_name, options);
			else
				ft_ls(cont->path, options);
		}
		i++;
	}
}

int				ft_ls(char *location, char *options)
{
	int			size;
	t_content	*cont;
	
	cont = malloc(sizeof(t_content));
	dirent_to_array(location, cont, options);
	if (cont->size == 0)
		exit(0);
	if (has_option(options, 't'))
		sort_dirent_array(cont);
	if (has_option(options, 'r'))
		sort_by_name(cont);
	listfiles(location, options, cont);
	if (has_option(options, 'R'))
	{
		listdir(location, options, cont);
		// while (i < cont->size)
		// {
		// 	get_path(cont->path, location, cont->arr[i].d_name);
		// 	if (is_dir(cont->path) && ft_strcmp(cont->arr[i].d_name, ".") != 0 &&
		// 		ft_strcmp(cont->arr[i].d_name, "..") != 0)
		// 	{
		// 		ft_printf("\n%s/%s:\n", location, cont->arr[i].d_name); //FIX
		// 		if (ft_strcmp(location, ".") == 0)
		// 			ft_ls(cont->arr[i].d_name, options);
		// 		else
		// 			ft_ls(cont->path, options);
		// 	}
		// 	i++;
		// }
	}
	SMART_FREE(cont);
	return(0);
}
