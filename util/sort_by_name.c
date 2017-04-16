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

void				sort_by_name(char *options, t_content *cont)
{
	if (has_option(options, 'r'))
		partition(0, cont->size - 1, cont, &compare_name_rev);
	else
		partition(0, cont->size - 1, cont, &compare_name);
	// int				partition_point;
	// t_items			*pivot;

	// if (right - left <= 0)
	// 	return ;
	// else
	// {
	// 	pivot = &cont->arr[right];
	// 	partition_point = t_items_qsort(left, right, pivot, cont->arr, &compare_name);
	// 	sort_by_name(left, partition_point - 1, cont);
	// 	sort_by_name(partition_point + 1, right, cont);
	// }
}
