/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:46:46 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/26 16:47:29 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	while (dst[idx] && idx < size)
		idx++;
	len = idx;
	while (src[idx - len] && idx < size - 1)
	{
		dst[idx] = src[idx - len];
		idx++;
	}
	if (len < size)
		dst[idx] = '\0';
	return (len + ft_strlen(src));
}
