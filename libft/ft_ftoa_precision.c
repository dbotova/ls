/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 20:45:42 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 15:03:41 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int					ft_get_size(long long n)
{
	int size;

	size = 1;
	while (n >= (long long)10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void					ft_nbrstr(long long n, char *str, int idx,
							int size)
{
	if (n == 0)
	{
		while (size)
		{
			str[idx--] = '0';
			size--;
		}
	}
	else
	{
		while (n)
		{
			str[idx--] = n % 10 + '0';
			n /= 10;
		}
	}
}

static char					*ft_get_result(int fsize, long long fpart,
							long long nb, int isneg)
{
	char			*result;
	int				isize;

	isize = 1;
	isize += ft_get_size(nb) + isneg;
	result = NULL;
	result = (char *)malloc(sizeof(char) * (isize + fsize + 1));
	if (result)
	{
		if (isneg)
			result[0] = '-';
		result[isize + fsize] = '\0';
		result[isize - 1] = '.';
		ft_nbrstr(nb, result, isize - 2, isize - 1);
		ft_nbrstr(fpart, result, isize + fsize - 1, fsize);
	}
	return (result);
}

static unsigned long long	ft_get_precision(long double n, int precision)
{
	long long				nb;
	long double				tmp;
	long double				num;
	unsigned long long		res;
	long long				ipart;

	nb = (long long)n;
	num = n;
	res = 0;
	while (precision)
	{
		ipart = num;
		num = num * 10;
		tmp = num - ipart * 10;
		res = res * 10 + (int)tmp;
		num = num - res;
		num = num - (long long)(num - nb);
		precision--;
	}
	return (res);
}

char						*ft_ftoa_precision(long double n, int precision)
{
	int						isneg;
	long long				nb;
	unsigned long long		fpart;
	int						min_pr;

	isneg = 0;
	min_pr = MIN(precision, 16);
	nb = (long long)n;
	if (n < 0)
	{
		isneg = 1;
		nb *= -1;
		n *= -1;
	}
	fpart = ft_get_precision(n, min_pr + 1);
	if (fpart == ft_power(10, min_pr + 1))
	{
		fpart = 0;
		nb++;
	}
	else
		fpart = ROUND(fpart) / 10;
	return (ft_get_result(min_pr, fpart, nb, isneg));
}
