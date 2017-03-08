/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 20:45:42 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/30 20:45:43 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getsize(unsigned long long n, int base)
{
	int size;

	size = 1;
	while (n >= (unsigned long long)base)
	{
		n = n / base;
		size++;
	}
	return (size);
}

static void	ft_nbrstr(unsigned long long n, char *str, int idx, int base)
{
	if (n == 0)
		str[idx] = '0';
	else
		while (n)
		{
			str[idx--] = "0123456789abcdef"[n % base];
			n /= base;
		}
}

char		*ft_ultoa_base(unsigned long long nb, int base)
{
	char			*result;
	int				size;

	size = 0;
	if (base < 2 || base > 16)
		return (NULL);
	size += ft_getsize(nb, base);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result)
	{
		ft_nbrstr(nb, result, size - 1, base);
		result[size] = '\0';
	}
	return (result);
}
