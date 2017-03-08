/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 20:17:35 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/28 20:17:37 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *tmp;

	tmp = s;
	while (n--)
	{
		if ((unsigned char)c == *tmp)
			return ((void *)tmp);
		else
			tmp++;
	}
	return (NULL);
}
