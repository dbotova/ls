/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:04:17 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/28 19:04:19 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t len)
{
	char		*dest;
	const char	*src;

	dest = str1;
	src = str2;
	if (src < dest)
	{
		dest = dest + (len - 1);
		src = src + (len - 1);
		while (len > 0)
		{
			*dest-- = *src--;
			len--;
		}
	}
	else
	{
		while (len--)
			*dest++ = *src++;
	}
	return (str1);
}
