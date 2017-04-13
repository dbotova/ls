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

static int			partition(int left, int right, char *pivot,
					t_content *cont)
{
	int				left_pointer;
	int				right_pointer;

	left_pointer = left - 1;
	right_pointer = right;
	while (42)
	{
		while (ft_strcmp(cont->arr[++left_pointer].d_name, pivot) < 0)
			;
		while (right_pointer > 0 &&
			ft_strcmp(cont->arr[--right_pointer].d_name, pivot) > 0)
			;
		if (left_pointer >= right_pointer)
			break ;
		else
			swap(cont, left_pointer, right_pointer);
	}
	swap(cont, left_pointer, right);
	return (left_pointer);
}

void				sort_by_name(int left, int right, t_content *cont)
{
	int				partition_point;
	char			*pivot;

	if (right - left <= 0)
		return ;
	else
	{
		pivot = ft_strdup(cont->arr[right].d_name);
		partition_point = partition(left, right, pivot, cont);
		sort_by_name(left, partition_point - 1, cont);
		sort_by_name(partition_point + 1, right, cont);
	}
	SMART_FREE(pivot);
}
