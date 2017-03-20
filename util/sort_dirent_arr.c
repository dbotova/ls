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

static void			swap(t_content *cont, int left, int right)
{
	struct dirent	tmp;

	tmp = cont->arr[left];
	cont->arr[left] = cont->arr[right];
	cont->arr[right] = tmp;
}

static void	get_buf(t_content *cont, int pointer, struct stat *statbuf)
{
	char			*tmp;

	tmp = get_path(cont->location, cont->arr[pointer].d_name);
	stat(tmp, statbuf);
	SMART_FREE(tmp);
}

static int			partition(int left, int right, long long pivot,
					t_content *cont)
{
	struct stat		statbuf;
	int				left_pointer;
	int				right_pointer;

	left_pointer = left - 1;
	right_pointer = right;
	while (42)
	{
		get_buf(cont, ++left_pointer, &statbuf);
		while (statbuf.st_mtime > pivot)
			get_buf(cont, ++left_pointer, &statbuf);
		get_buf(cont, --right_pointer, &statbuf);
		while (right_pointer > 0 && statbuf.st_mtime < pivot)
			get_buf(cont, --right_pointer, &statbuf);
		if (left_pointer >= right_pointer)
			break ;
		else
			swap(cont, left_pointer, right_pointer);
	}
	swap(cont, left_pointer, right);
	return (left_pointer);
}

static void			q_sort(int left, int right, t_content *cont)
{
	int				partition_point;
	long long		pivot;
	struct stat		statbuf;

	if (right - left <= 0)
		return ;
	else
	{
		stat(get_path(cont->location, cont->arr[right].d_name), &statbuf);
		pivot = statbuf.st_mtime;
		partition_point = partition(left, right, pivot, cont);
		q_sort(left, partition_point - 1, cont);
		q_sort(partition_point + 1, right, cont);
	}
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
		q_sort(0, cont->size - 1, cont);
}
