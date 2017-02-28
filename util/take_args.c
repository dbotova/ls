/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:32:21 by dbotova           #+#    #+#             */
/*   Updated: 2017/02/27 16:32:22 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static DIR	*check_location(char *arg1, char *arg2)
{
	DIR *dir;
	int flag;

	flag = 0;
	if (!arg1 && !arg2)
		dir = opendir(".");
	else if (!arg2 && arg1[0] != '-')
	{
		dir = opendir(arg1);
		flag = 1;
	}
	else
	{
		dir = opendir(arg2);
		flag = 2;
	}
	if (!dir)
	{
		ft_printf("ft_ls: %s ", (flag == 1 ? arg1 : arg2));
		perror("");
		exit(1);
	}
	return (dir);
}

static char	*check_options(char *arg1, char *arg2)
{
	int i;

	i = 1;
	if (!arg1 && !arg2)
		return (NULL);
	else if (arg1 && *arg1 == '-')
	{
		while (arg1[i] != 0)
		{
			if (!ft_strchr(OPTINOS, arg1[i]))
				exit(1);
			else
				i++;
		}
		return (arg1 + 1);
	}
	else
		return (NULL);
}

t_args	*take_args(char *arg1, char *arg2)
{
	t_args *new;
	char *tmp;

	new = malloc(sizeof(t_args));
	if (new)
	{
		new->options = (char *)malloc(sizeof(char) * OPTIONS_SIZE + 1);
		ft_memset(new->options, 0, OPTIONS_SIZE + 1);
		new->dir = check_location(arg1, arg2);
		tmp = check_options(arg1, arg2);
		if (tmp)
			ft_strcpy(new->options, tmp);
	}
	return (new);
}
