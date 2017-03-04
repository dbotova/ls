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

void	ft_ls(char *location, char *options)
{
	int size;
	struct dirent arr[ARR_SIZE];

	size =  dirent_to_array(location, arr, options);
	if (ft_strchr(options, 't'))
		sort_dirent_array(arr, size);
	listfiles(location, options, arr, size);
	exit(0);
}
