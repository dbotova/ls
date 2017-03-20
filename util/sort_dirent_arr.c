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
		while (statbuf.st_mtime > pivot)
		{
			i++;
			get_buf(cont, i, &statbuf, arr);
		}
		get_buf(cont, j, &statbuf, arr);
		while (statbuf.st_mtime < pivot)
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

// static int			partition(int left, int right, long long pivot,
// 					t_content *cont)
// {
// 	struct stat		statbuf;
// 	int				left_pointer;
// 	int				right_pointer;

// 	left_pointer = left - 1;
// 	right_pointer = right;
// 	while (42)
// 	{
// 		get_buf(cont, left_pointer, &statbuf);
// 		while (statbuf.st_mtime > pivot)
// 			get_buf(cont, ++left_pointer, &statbuf);
// 		get_buf(cont, right_pointer, &statbuf);
// 		while (right_pointer > 0 && statbuf.st_mtime < pivot)
// 			get_buf(cont, --right_pointer, &statbuf);
// 		if (left_pointer >= right_pointer)
// 			break ;
// 		swap(cont, left_pointer, right_pointer);
// 	}
// 	swap(cont, left_pointer, right);
// 	return (left_pointer);
// }

// static void			q_sort(int left, int right, t_content *cont)
// {
// 	int				partition_point;
// 	long long		pivot;
// 	struct stat		statbuf;

// 	if (right - left <= 0)
// 		return ;
// 	else
// 	{
// 		get_buf(cont, right, &statbuf);
// 		pivot = statbuf.st_mtime;
// 		partition_point = partition(left, right, pivot, cont);
// 		q_sort(left, partition_point - 1, cont);
// 		q_sort(partition_point + 1, right, cont);
// 	}
// }

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
		//q_sort(0, cont->size - 1, cont);
}
