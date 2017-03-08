/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 19:23:54 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/29 19:23:56 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else
	{
		while (*s1)
		{
			if ((*s1) != (*s2))
				return (0);
			s1++;
			s2++;
		}
	}
	return (1);
}
