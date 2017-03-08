/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:45:58 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/26 16:46:30 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *result;

	result = dest;
	while (*dest)
		dest++;
	while (n-- && *src)
		*dest++ = *src++;
	*dest = 0;
	return (result);
}
