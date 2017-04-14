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

static void			swap(t_items *arr, int left, int right)
{
	t_items	tmp;

	tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}

static void			partition(t_content *cont, t_items *arr, int size)
{
	int				i;
	int				j;
	long long		pivot;

	i = 0;
	j = size - 1;
	pivot = cont->arr[size / 2].mtime;
	if (size < 2)
		return ;
	while (42)
	{
		while (cont->arr[i].mtime > pivot) ++i;
		while (cont->arr[j].mtime < pivot) --j;
		if (i >= j)
			break ;
		swap(arr, i++, j--);
	}
	partition(cont, arr, i);
	partition(cont, arr + i, size - i);
}

void				sort_dirent_array(char *options, t_content *cont)
{
	if (has_option(options, 'r'))
		sort_dirent_array_rev(options, cont);
	else if (has_option(options, 'u'))
		sort_dirent_array_u(cont);
	else if (has_option(options, 'c'))
		sort_dirent_array_c(cont);
	else
		partition(cont, cont->arr, cont->size);
}
