/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:39:43 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 17:23:48 by dbotova          ###   ########.fr       */
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
	ft_putstr(prefix);
	if (!(*c == '0' && flags->is_dot && !flags->cutoff))
		ft_putstr(c);
	if (flags->width > 0)
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
	if (flags->is_plus)
		size++;
	if (flags->is_space && !flags->is_minus && !flags->is_plus)
		size++;
	ft_putline(width, prefix, c, flags);
	if (prefix)
		SMART_FREE(prefix);
	if (width)
		SMART_FREE(width);
	return (size);
}

static char	*ft_mread(va_list ap, union u_types tp)
{
	char	*str;

	str = NULL;
	tp.ul = va_arg(ap, unsigned long);
	return (ft_ltoa_base(tp.ul, 10));
}

int			ft_cint_print(va_list ap, union u_types tp, t_flags *flags)
{
	int		size;
	char	*str;
	char	*width;
	char	*prefix;

	size = 0;
	str = NULL;
	width = NULL;
	prefix = NULL;
	str = ft_mread(ap, tp);
	ft_num_read(str, flags, &prefix, &width);
	size = ft_getsize(str, prefix, width, flags);
	SMART_FREE(str);
	return (size);
}
