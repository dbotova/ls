/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:21:07 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 18:07:57 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_putline(char *width, char *prefix, char *c, t_flags *flags)
{
	char	*hash;

	hash = "0x";
	if (flags->width > 0)
		ft_putstr(width);
	ft_putstr(hash);
	ft_putstr(prefix);
	if (flags->is_dot && *c == '0' && !flags->cutoff)
		ft_putstr("");
	else
		ft_putstr(c);
	if (flags->width < 0)
		ft_putstr(width);
}

static int	ft_getsize(char *c, char *prefix, char *width, t_flags *flags)
{
	int		size;
	char	*hash;

	hash = "0x";
	size = 0;
	if (c && *c == '0' && flags->is_dot && !flags->cutoff)
		size = (int)ft_strlen(prefix) + (int)ft_strlen(width) +
			ft_strlen(hash);
	else
		size = (int)ft_strlen(c) + (int)ft_strlen(prefix) +
			(int)ft_strlen(width) + ft_strlen(hash);
	ft_putline(width, prefix, c, flags);
	if (prefix)
		SMART_FREE(prefix);
	if (width)
		SMART_FREE(width);
	return (size);
}

int			ft_pointer_print(va_list ap, union u_types tp, t_flags *flags)
{
	int		size;
	char	*str;
	char	*width;
	char	*prefix;

	size = 0;
	str = NULL;
	width = NULL;
	prefix = NULL;
	tp.p = va_arg(ap, long long);
	str = ft_ultoa_base(tp.p, 16);
	ft_pointer_read(str, flags, &prefix, &width);
	size = ft_getsize(str, prefix, width, flags);
	SMART_FREE(str);
	return (size);
}
