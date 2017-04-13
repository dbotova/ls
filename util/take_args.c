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

static void	check_location(int argc, char **argv, char **location)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (!argv[i])
		location[j] = ft_strdup("./");
	else
	{
		while (i < argc && argv[i][0] == '-')
			i++;
		while (i < argc)
		{
			location[j] = ft_strdup(argv[i]);
			i++;
			j++;
		}
	}
	if (j == 0)
		location[j] = ft_strdup("./");
}

static void	check_options(int argc, char **argv, char **options)
{
	int		i;
	int		j;
	int		m;

	i = 1;
	m = 0;
	*options = (char*)malloc(sizeof(char) * ft_strlen(OPTINOS));
	ft_memset(*options, 0, ft_strlen(OPTINOS));
	while (i < argc && argv[i][0] == '-')
	{
		j = 1;
		while (argv[i][j] != 0)
			(*options)[m++] = argv[i][j++];
		i++;
	}
}

void		take_args(int argc, char **argv, char **location, char **options)
{
	check_options(argc, argv, options);
	check_location(argc, argv, location);
}
