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

static int	ft_getsize(long n)
{
	int size;

	size = 1;
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_nbrstr(long n, char *str, int idx)
{
	if (n == 0)
		str[idx] = '0';
	else
		while (n)
		{
			str[idx--] = n % 10 + '0';
			n /= 10;
		}
}

char		*ft_itoa(int n)
{
	char	*result;
	int		size;
	int		isneg;
	long	nb;

	isneg = 0;
	size = 0;
	nb = n;
	if (n < 0)
	{
		isneg = 1;
		nb *= -1;
		size++;
	}
	size += ft_getsize(nb);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result)
	{
		if (isneg)
			result[0] = '-';
		ft_nbrstr(nb, result, size - 1);
		result[size] = '\0';
	}
	return (result);
}
