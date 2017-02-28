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

void	ft_ls(char *location, char *oprtions)
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
	if (ft_strchr(oprtions, 'R'))
		listdir(location, 0);
	else
		listfiles(location, oprtions);
	closedir(dir);
	exit(0);
}
