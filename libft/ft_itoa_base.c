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

static int	ft_getsize(long long n, int base)
{
	int size;

	size = 1;
	while (n >= (long long)base)
	{
		n = n / base;
		size++;
	}
	return (size);
}

static void	ft_nbrstr(long long n, char *str, int idx, int base)
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

static int	ft_get_strsize(int *isneg, int n, int base, long long *nb)
{
	int size;

	size = 0;
	if (n < 0)
	{
		if (base == 10)
		{
			*isneg = 1;
			size++;
		}
		*nb *= -1;
	}
	size += ft_getsize(*nb, base);
	return (size);
}

char		*ft_itoa_base(int n, int base)
{
	char			*result;
	int				size;
	int				isneg;
	long long		nb;

	isneg = 0;
	size = 0;
	nb = n;
	if (base < 2 || base > 16)
		return (NULL);
	size = ft_get_strsize(&isneg, n, base, &nb);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result)
	{
		if (isneg)
			result[0] = '-';
		ft_nbrstr(nb, result, size - 1, base);
		result[size] = '\0';
	}
	return (result);
}
