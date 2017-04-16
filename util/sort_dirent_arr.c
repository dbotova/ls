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

void				sort_dirent_array(char *options, t_content *cont)
{
	if (has_option(options, 'r'))
		sort_dirent_array_rev(options, cont);
	else if (has_option(options, 'u'))
		partition(0, cont->size - 1, cont, &compare_atime);
	else if (has_option(options, 'c'))
		partition(0, cont->size - 1, cont, &compare_ctime);
	else
		partition(0, cont->size - 1, cont, &compare_mtime);
}
