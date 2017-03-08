/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:30:13 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/22 19:31:19 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (ft_strncmp((char *)haystack, (char *)needle,
			(unsigned int)ft_strlen(needle)) == 0)
			return ((char *)haystack);
		else
			haystack++;
	}
	return (NULL);
}
