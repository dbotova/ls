/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:43:24 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 16:49:39 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_putline(char *width, char *prefix, char *c, t_flags *flags)
{
	if (flags->width > 0)
		ft_putstr(width);
	if (flags->is_space)
		ft_putchar(' ');
	if (flags->is_plus && *c != '-')
		ft_putchar('+');
	if (*c == '-')
	{
		ft_putchar(*c);
		c++;
	}
	ft_putstr(prefix);
	ft_putstr(c);
	if (flags->width < 0)
		ft_putstr(width);
}

static int	ft_getsize(char *c, char *prefix, char *width, t_flags *flags)
{
	int		size;

	size = (int)ft_strlen(c) + (int)ft_strlen(prefix) +
		(int)ft_strlen(width) + flags->is_plus + flags->is_space;
	ft_putline(width, prefix, c, flags);
	if (prefix)
		SMART_FREE(prefix);
	if (width)
		SMART_FREE(width);
	return (size);
}

static char	*ft_mread(va_list ap, union u_types tp, t_flags *flags)
{
	if (flags->is_cl == 1)
	{
		tp.lf = va_arg(ap, long double);
		if (tp.lf < 0)
			tp.lf = 0;
		if (flags->is_dot && !flags->cutoff)
			return (ft_itoa_base((int)tp.lf, 10));
		return (ft_ftoa_precision(tp.lf, MAX(6, flags->cutoff)));
	}
	tp.f = va_arg(ap, double);
	if (flags->is_dot && !flags->cutoff)
		return (ft_itoa_base((int)tp.f, 10));
	return (ft_ftoa_precision(tp.f, MAX(6, flags->cutoff)));
}

int			ft_float_print(va_list ap, union u_types tp, t_flags *flags)
{
	int		size;
	char	*str;
	char	*prefix;
	char	*width;

	size = 0;
	width = NULL;
	prefix = NULL;
	str = ft_mread(ap, tp, flags);
	if (flags->is_separete)
		str = ft_num_separete(str);
	ft_float_read(str, flags, &prefix, &width);
	size = ft_getsize(str, prefix, width, flags);
	SMART_FREE(str);
	return (size);
}
