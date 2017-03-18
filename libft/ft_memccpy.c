/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:59:52 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/26 18:00:23 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	unsigned char		*dest;
	const unsigned char *src;

	dest = str1;
	src = str2;
	while (n--)
	{
		*dest = *src;
		if ((unsigned char)c == *src)
			return (++dest);
		dest++;
		src++;
	}
	return (NULL);
}
