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

void	dirent_to_array(char *location, t_content *cont, char *options)
{
	DIR *dir;
	struct dirent *d;
	int i;

	i = 0;
	dir = opendir(location);
	if (!dir)
	{
		ft_printf("ft_ls: %s ", location);
		perror("");
		exit(1);
	}
	while ((d = readdir(dir)) != NULL)
	{
		if (d->d_name[0] != '.' || has_option(options, 'a'))
			cont->arr[i++] = *d;
	}
	closedir(dir);
	cont->size = i;
}