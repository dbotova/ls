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

int main (int argc, char **argv)
{
	char *location;
	char *options;

	if (argc == 1)
		take_args(NULL, NULL, &location, &options);
	else if (argc == 2)
		take_args(argv[1], NULL, &location, &options);
	else if (argc == 3)
		take_args(argv[1], argv[2], &location, &options);
	else
		exit(1);
	
	ft_ls(location, options);
	SMART_FREE(location);
	if (options)
		SMART_FREE(options);
	return (0);
}
