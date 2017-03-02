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

int	dirent_to_array(char *location, struct dirent arr[])
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
		arr[i++] = *d;
	closedir(dir);
	return (i);
}