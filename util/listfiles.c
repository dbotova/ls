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

void	listfiles(char *location, char *oprtions, struct dirent arr[], int count)
{
	int i;

	i = 0;
	if (!oprtions || ft_strchr(oprtions, 't'))
	{
		while (i < count)
		{
			if (arr[i].d_name[0] != '.')
				ft_printf("%s\n", arr[i].d_name);
			i++;
		}
	}
	else if (*oprtions == 'a')
	{
		while (i < count)
			ft_printf("%s\n", arr[i++].d_name);
	}
	else
		printf("ADD CODE HERE\n");
	// DIR *dir;
	// struct dirent *d;

	// dir = opendir(location);
	// if (!dir)
	// {
	// 	ft_printf("ft_ls: %s ", location);
	// 	perror("");
	// 	exit(1);
	// }
	// else if (!oprtions)
	// {
	// 	while ((d = readdir(dir)) != NULL)
	// 	{
	// 		if (d->d_name[0] != '.')
	// 			ft_printf("%s\n", d->d_name);
	// 	}
	// }
	// else if (*oprtions == 'a')
	// {
	// 	while ((d = readdir(dir)) != NULL)
	// 		ft_printf("%s\n", d->d_name);
	// }
	// else
	// 	printf("ADD CODE HERE\n");
	// closedir(dir);
	exit(0);
}
