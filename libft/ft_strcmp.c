/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:37:14 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/22 21:15:05 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	int idx;

	idx = 0;
	while (str1[idx] != '\0' || str2[idx] != '\0')
	{
		if (str1[idx] != str2[idx])
			return ((unsigned char)str1[idx] - (unsigned char)str2[idx]);
		else
			idx++;
	}
	return (0);
}
