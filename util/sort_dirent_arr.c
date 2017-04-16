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
// 		partition_point = t_items_qsort(left, right, pivot, cont->arr, &compare_mtime);
// 		partition(left, partition_point - 1, cont);
// 		partition(partition_point + 1, right, cont);
// 	}
// }

// static int compare_time(const void *m1, const void *m2)
// {
//      t_items *item1 = (t_items*) m1;
//      t_items *item2 = (t_items*) m2;

//      if (item1->mtime > item2->mtime)
//      	return -1;
//      if (item1->mtime < item2->mtime)
//      	return 1;

//      return 0;
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
		//qsort(cont->arr, cont->size, sizeof(t_items), compare_time);
		partition(0, cont->size - 1, cont, &compare_mtime);
}
