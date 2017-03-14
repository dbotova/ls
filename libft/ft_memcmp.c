/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 21:31:24 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/28 21:31:26 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char str1;
	unsigned char str2;

	while (n--)
	{
		str1 = *(unsigned char *)s1++;
		str2 = *(unsigned char *)s2++;
		if (str1 != str2)
			return (str1 - str2);
	}
	return (0);
}
