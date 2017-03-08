/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:03:11 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/22 18:19:07 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	size;
	int		idx;

	size = 0;
	idx = 0;
	if (str)
	{
		while (str[idx] != '\0')
		{
			size++;
			idx++;
		}
	}
	return (size);
}
