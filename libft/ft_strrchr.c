/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:17:15 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/22 19:29:44 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = ft_strlen(str);
	while (str && i >= 0)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
