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

static int				ft_getsize(unsigned long long n, int base)
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

static void				ft_nbrstr(unsigned long long n, char *str,
						int idx, int base)
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

char					*ft_ltoa_base(long long n, int base)
{
	char				*result;
	int					size;
	int					is_neg;
	unsigned long long	nb;

	size = 0;
	nb = n;
	is_neg = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (n < 0)
	{
		nb = n * -1;
		is_neg = 1;
	}
	size += ft_getsize(nb, base) + is_neg;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result)
	{
		if (is_neg)
			result[0] = '-';
		ft_nbrstr(nb, result, size - 1, base);
		result[size] = '\0';
	}
	return (result);
}
