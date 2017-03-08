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

static char	*check_location(char *arg1, char *arg2)
{
	if (!arg1 && !arg2)
		return (".");
	else if (!arg2 && arg1[0] != '-')
		return (arg1);
	else if (arg1[0] == '-' && !arg2)
		return (".");
	else
		return (arg2);
}

static char	*check_options(char *arg1, char *arg2)
{
	int		i;

	i = 1;
	if (!arg1 && !arg2)
		return (NULL);
	else if (arg1 && *arg1 == '-')
	{
		while (arg1[i] != 0)
		{
			if (!ft_strchr(OPTINOS, arg1[i]))
			{
				ft_printf("ft_ls: illegal options -- %c\n", arg1[i]);
				ft_printf("usage: ls [-%s] [file...]\n", OPTINOS);
				exit(1);
			}
			else
				i++;
		}
		return (arg1 + 1);
	}
	else
		return (NULL);
}

void		take_args(char *arg1, char *arg2, char **location, char **options)
{
	char	*tmp;
	
	*location = ft_strdup(check_location(arg1, arg2));
	tmp = check_options(arg1, arg2);
	if (tmp)
		*options = ft_strdup(tmp);
}
