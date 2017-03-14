/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:05:38 by dbotova           #+#    #+#             */
/*   Updated: 2017/02/27 19:05:39 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static	void		find_max(t_content *cont)
{
	int				max;
	int				i;
	int				etalon;

	i = 0;
	etalon = 16;
	max = (int)ft_strlen(cont->arr[i].d_name);
	while (i < cont->size)
	{
		if ((int)ft_strlen(cont->arr[i].d_name) > max)
			max = (int)ft_strlen(cont->arr[i].d_name);
		i++;
	}
	while (max > etalon)
	{
		etalon += 16;
	}
	cont->max = etalon;
}

static void			get_row_num(t_content *cont)
{
	float			result;
	struct winsize	screen_size;
	int				etalon;

	find_max(cont);
	etalon = 32;
	ioctl(STDIN_FILENO, TIOCGWINSZ, (char *)&screen_size);
	while (screen_size.ws_col > etalon + 16)
		etalon += 16;
	result = (float)(cont->max * cont->size) / etalon;
	if (result > cont->size)
		cont->rows = cont->size;
	else if (result / (int)result > 0)
		cont->rows = ((int)result + 1);
	else
		cont->rows = ((int)result);
}

void				listfiles(char *location, char *options, t_content *cont)
{
	int				i;
	int				j;
	int				len;

	j = 0;
	len = 0;
	get_row_num(cont);
	if (has_option(options, 'u') || has_option(options, 'c'))
	{
		if (has_option(options, 'r'))
			sort_by_name_rev(cont);
		else
			sort_by_name(cont);
	}
	while (j < cont->rows)
	{
		i = j;
		while (i < cont->size || i < cont->size / cont->rows)
		{
			ft_printf("%*s", cont->max * -1, cont->arr[i].d_name);
			i += cont->rows;
		}
		j++;
		ft_printf("\n");
	}
}
