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

static void			swap(struct dirent *arr, int left, int right)
{
	struct dirent	tmp;

	tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}

static void	get_buf(t_content *cont, int pointer, struct stat *statbuf, struct dirent *arr)
{
	char			*tmp;

	tmp = get_path(cont->location, arr[pointer].d_name);
	stat(tmp, statbuf);
	SMART_FREE(tmp);
}

static void			partition(t_content *cont, struct dirent *arr, int size)
{
	struct stat		statbuf;
	int				i;
	int				j;
	long long		pivot;

	i = 0;
	j = size - 1;
	get_buf(cont, size / 2, &statbuf, arr);
	pivot = statbuf.st_mtime;
	if (size < 2)
		return ;
	while (42)
	{
		get_buf(cont, i, &statbuf, arr);
		while (statbuf.st_mtime < pivot)
		{
			i++;
			get_buf(cont, i, &statbuf, arr);
		}
		get_buf(cont, j, &statbuf, arr);
		while (statbuf.st_mtime > pivot)
		{
			j--;
			get_buf(cont, j, &statbuf, arr);
		}
		if (i >= j)
			break ;
		swap(arr, i, j);
		i++;
		j--;
	}
	partition(cont, arr, i);
	partition(cont, arr + i, size - i);
}

static void			q_sort(t_content *cont)
{
	partition(cont, cont->arr, cont->size);
}

void				sort_dirent_array_rev(char *options, t_content *cont)
{
	if (has_option(options, 'u'))
		sort_dirent_array_rev_u(cont);
	if (has_option(options, 'c'))
		sort_dirent_array_rev_c(cont);
	else
		q_sort(cont);
}
