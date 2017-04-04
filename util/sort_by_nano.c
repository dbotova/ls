/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_nano.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:58:59 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/01 20:59:00 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	get_buf(t_content *cont, int pointer, struct stat *statbuf, struct dirent *arr)
{
	char			*tmp;

	tmp = get_path(cont->location, arr[pointer].d_name);
	lstat(tmp, statbuf);
	SMART_FREE(tmp);
}

void	sort_by_nano_mtime(t_content *cont, int start, int end)
{
	struct stat		statbuf;
	struct stat		statbuf_next;
	int i;
	int j;

	i = start + 1;

	while (i < end)
}