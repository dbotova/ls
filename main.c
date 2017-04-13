/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:33:53 by dbotova           #+#    #+#             */
/*   Updated: 2017/02/27 15:33:55 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int argc, char **argv)
{
	char	**location;
	char	*options;
	int		i;

	i = 0;
	location = (char**)malloc(sizeof(char*) * PATH_MAX);
	take_args(argc, argv, location, &options);
	while (location[i] != NULL)
	{
		if (location[1])
			printf("%s:\n", location[i]);
		ft_ls(location[i], options);
		if (location[i + 1])
			printf("\n");
		i++;
	}
	while (location[i] != NULL)
		SMART_FREE(location[i++]);
	SMART_FREE(location);
	SMART_FREE(options);
	return (0);
}
