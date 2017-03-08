/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:04:10 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 14:04:12 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwstr(wchar_t *str, size_t size)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (*str && i < size)
		{
			if (*str <= 0x7F)
				i++;
			else if (*str <= 0x7FF)
				i += 2;
			else if (*str <= 0xFFFF)
				i += 3;
			else if (*str <= 0x10FFFF)
				i += 4;
			if (i <= size)
				ft_putwchar(*str);
			str++;
		}
	}
}
