/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dirent_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:58:59 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/01 20:59:00 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	sort_dirent_array(struct dirent arr[], int size)
{
	int i;
	int j;
	struct dirent tmp;
	struct stat istatbuf;
	struct stat jstatbuf;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		stat(arr[i].d_name, &istatbuf);
		while (i < j)
		{
			stat(arr[i + 1].d_name, &jstatbuf);
			if(istatbuf.st_mtime < jstatbuf.st_mtime)
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
			i++;
		}
		i = 0;
		j--;
	}
}
