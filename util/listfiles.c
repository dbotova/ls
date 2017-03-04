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

static int	get_row_num(int count, int size)
{
	float result;

	result = 16 * count / size;
	if (result / (int)result > 0)
		return ((int)result + 1);
	else
		return ((int)result);
}
void	listfiles(char *location, char *options, struct dirent arr[], int count)
{
	int i;
	int j;
	int len;
	int colums;
	struct winsize screen_size;

	j = 0;
	len = 0;
	ioctl(STDIN_FILENO, TIOCGWINSZ, (char *) &screen_size);
	colums = get_row_num(count, screen_size.ws_col);
	while (j < colums)
	{
		i = j;
		while (i < count || i < count / colums)
		{
			ft_printf("%-16s", arr[i + colums].d_name);
			i += colums;
		}
		j++;
		ft_printf("\n");
	}
	exit(0);
}
