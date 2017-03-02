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
	int size;
	struct dirent arr[ARR_SIZE];

	if (ft_strchr(oprtions, 'R'))
		size = listdir(location, arr, 0);
	else
		size =  dirent_to_array(location, arr);
	if (ft_strchr(oprtions, 't'))
		sort_dirent_array(arr, size);
	listfiles(location, oprtions, arr, size);
	exit(0);
}
