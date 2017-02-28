/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:05:38 by dbotova           #+#    #+#             */
/*   Updated: 2017/02/27 19:05:39 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	listfiles(char *location, char *oprtions)
{
	DIR *dir;
	struct dirent *d;

	dir = opendir(location);
	if (!dir)
	{
		ft_printf("ft_ls: %s ", location);
		perror("");
		exit(1);
	}
	else
	{
		while ((d = readdir(dir)) != NULL)
		{
			if (d->d_name[0] != '.')
				ft_printf("%s\n", d->d_name);
		}
	}
	closedir(dir);
	exit(0);
}
