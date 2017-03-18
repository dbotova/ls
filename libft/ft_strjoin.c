/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:39:56 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/29 20:39:57 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*result;
	size_t	idx1;
	size_t	idx2;

	result = NULL;
	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
		result = (char *)malloc(sizeof(char) * size);
		idx1 = 0;
		idx2 = 0;
		if (result)
		{
			while (s1[idx1] != '\0')
			{
				result[idx1] = s1[idx1];
				idx1++;
			}
			while (s2[idx2] != '\0')
				result[idx1++] = s2[idx2++];
			result[idx1] = 0;
		}
	}
	return (result);
}
