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

// static void				partition(int left, int right, t_content *cont)
// {
// 	int				partition_point;
// 	t_items			*pivot;

// 	if (right - left <= 0)
// 		return ;
// 	else
// 	{
// 		pivot = &cont->arr[right];
// 		partition_point = t_items_qsort(left, right, pivot, cont->arr, &compare_ctime_rev);
// 		partition(left, partition_point - 1, cont);
// 		partition(partition_point + 1, right, cont);
// 	}
// }

void				sort_dirent_array_rev_c(t_content *cont)
{
	partition(0, cont->size - 1, cont, &compare_ctime_rev);
}
