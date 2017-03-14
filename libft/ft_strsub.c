/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 19:43:03 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/29 19:43:05 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *sub;

	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub && s)
	{
		sub = ft_strncpy(sub, s + start, len);
		sub[len] = 0;
		return (sub);
	}
	else
		return (NULL);
}
