/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_separete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:04:22 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 15:08:21 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(char *str, int *i)
{
	char	*tmp;
	int		size;

	size = (int)ft_strlen(str);
	tmp = NULL;
	if ((tmp = ft_strchr(str, '.')) != NULL)
		size = (int)ft_strlen(str) - (int)ft_strlen(tmp);
	*i = size % 3;
	if (*i == 0)
		*i = 3;
	return (size);
}

char		*ft_num_separete(char *str)
{
	int		size;
	int		i;
	int		c;
	int		new_size;
	char	*result;

	size = ft_get_size(str, &i);
	c = 0;
	result = NULL;
	new_size = (int)ft_strlen(str) + (size / 3) + ((i != 3) ? 1 : 0) - 1;
	result = (char*)malloc(new_size + 1);
	while (c < new_size)
	{
		if (*str != '.' && i && (c == i || (c - i) % 4 == 0))
			result[c++] = ',';
		if (*str == '.')
			while (*str)
				result[c++] = *str++;
		else
			result[c++] = *str++;
	}
	result[new_size] = 0;
	return (result);
}
