/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:04:18 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 15:04:21 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(wchar_t *str)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (*str)
		{
			if (*str <= 0x7F)
				i++;
			else if (*str <= 0x7FF)
				i += 2;
			else if (*str <= 0xFFFF)
				i += 3;
			else if (*str <= 0x10FFFF)
				i += 4;
			str++;
		}
	}
	return (i);
}
