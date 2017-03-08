/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:47:45 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/26 16:47:51 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!*needle)
		return ((char *)haystack);
	while (len && *haystack)
	{
		if (ft_strncmp((char *)haystack, (char *)needle,
			(unsigned int)ft_strlen(needle)) == 0 && len >= ft_strlen(needle))
			return ((char *)haystack);
		else
			haystack++;
		len--;
	}
	return (NULL);
}
