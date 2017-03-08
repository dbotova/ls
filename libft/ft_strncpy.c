/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:44:26 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/26 16:45:35 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *result;

	result = dest;
	while (*src && n)
	{
		*dest = *src;
		src++;
		dest++;
		n--;
	}
	if (n > 0)
		ft_bzero(dest, (int)n);
	return (result);
}
