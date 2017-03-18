/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:50:22 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/29 18:50:23 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	size_t	size;
	size_t	idx;

	idx = 0;
	if (s)
	{
		size = ft_strlen(s);
		result = (char *)malloc(sizeof(char) * (size + 1));
		if (result)
		{
			while (idx < size)
			{
				result[idx] = f(s[idx]);
				idx++;
			}
			result[size] = '\0';
			return (result);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
