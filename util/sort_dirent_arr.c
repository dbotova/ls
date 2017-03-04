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

void	sort_dirent_array(t_content *cont)
{
	int i;
	int j;
	struct dirent tmp;
	struct stat istatbuf;
	struct stat jstatbuf;

	i = 0;
	j = cont->size - 1;
	while (i < j)
	{
		stat(cont->arr[i].d_name, &istatbuf);
		while (i < j)
		{
			stat(cont->arr[i + 1].d_name, &jstatbuf);
			if(istatbuf.st_mtime < jstatbuf.st_mtime)
			{
				tmp = cont->arr[i];
				cont->arr[i] = cont->arr[i + 1];
				cont->arr[i + 1] = tmp;
			}
			i++;
		}
		i = 0;
		j--;
	}
}
