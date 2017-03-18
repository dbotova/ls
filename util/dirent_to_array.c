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
		if (stat(d->d_name, &buf) == -1)
		{
			perror(location);
			exit(1);
		}
		if (d->d_name[0] != '.' || has_option(options, 'a'))
		{
			cont->arr[i++] = *d;
			cont->total += buf.st_blocks;
		}
	}
	closedir(dir);
	cont->size = i;
}
