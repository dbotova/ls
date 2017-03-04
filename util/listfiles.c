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

static int	is_dir(char *path)
{
	struct stat statbuf;
	if (stat(path, &statbuf) == -1)
    {
        perror(path);
        exit(1);
    }
	if (S_ISDIR(statbuf.st_mode))
		return (1);
	else
		return (0);
}

static int	get_row_num(int count)
{
	float result;
	struct winsize screen_size;

	ioctl(STDIN_FILENO, TIOCGWINSZ, (char *) &screen_size);
	result = 16 * count / screen_size.ws_col;
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

	j = 0;
	len = 0;
	
	colums = get_row_num(count);
	while (j < colums)
	{
		i = j;
		while (i < count || i < count / colums)
		{
			ft_printf("%-16s", arr[i].d_name);
			i += colums;
		}
		j++;
		ft_printf("\n");
	}
	exit(0);
}
