/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:39:43 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 17:43:03 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_putline(char *width, char *prefix, char *c, t_flags *flags)
{
	if (flags->width > 0)
		ft_putstr(width);
	if (flags->is_plus && *c != '-')
		ft_putchar('+');
	if (flags->is_space && *c != '-' && !flags->is_plus)
		ft_putchar(' ');
	if (*c == '-')
	{
		ft_putchar(*c);
		c++;
	}
	ft_putstr(prefix);
	if (!(*c == '0' && flags->is_dot && !flags->cutoff))
		ft_putstr(c);
	if (flags->width < 0)
		ft_putstr(width);
}

static int	ft_getsize(char *c, char *prefix, char *width, t_flags *flags)
{
	int		size;

	if (*c == '0' && flags->is_dot && !flags->cutoff)
		size = (int)ft_strlen(prefix) + (int)ft_strlen(width);
	else
		size = (int)ft_strlen(c) + (int)ft_strlen(prefix) +
			(int)ft_strlen(width);
	if (flags->is_plus && *c != '-')
		size++;
	if (flags->is_space && !flags->is_minus && !flags->is_plus
			&& *c != '-')
		size++;
	ft_putline(width, prefix, c, flags);
	if (prefix)
		SMART_FREE(prefix);
	if (width)
		SMART_FREE(width);
	return (size);
}

static char	*ft_mread(va_list ap, union u_types tp, t_flags *flags)
{
	char	*str;

	str = NULL;
	if (flags->is_l || flags->is_j || flags->is_z)
	{
		tp.ll = va_arg(ap, long long);
		return (ft_ltoa_base(tp.ll, 10));
	}
	if (flags->is_h == 1)
	{
		tp.d = va_arg(ap, int);
		return (ft_ltoa_base((short)tp.d, 10));
	}
	if (flags->is_h == 2)
	{
		tp.d = va_arg(ap, int);
		return (ft_ltoa_base((char)tp.d, 10));
	}
	tp.d = va_arg(ap, int);
	return (ft_itoa_base(tp.d, 10));
}

int			ft_int_print(va_list ap, union u_types tp, t_flags *flags)
{
	int		size;
	char	*str;
	char	*width;
	char	*prefix;

	size = 0;
	str = NULL;
	width = NULL;
	prefix = NULL;
	str = ft_mread(ap, tp, flags);
	if (flags->is_separete)
		str = ft_num_separete(str);
	ft_num_read(str, flags, &prefix, &width);
	size = ft_getsize(str, prefix, width, flags);
	SMART_FREE(str);
	return (size);
}
