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

void	ft_ls(t_args *args)
{
	struct dirent *d;
	
	if (!*args->options)
	{
		while ((d = readdir(args->dir)) != NULL)
		{
			if (d->d_name[0] != '.')
				ft_printf("%s\n", d->d_name);
		}
	}

	closedir(args->dir);
	exit(0);
}
