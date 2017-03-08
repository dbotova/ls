/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:04:19 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 16:07:15 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void		ft_putline(char *width, char *prefix, char *c,
				t_flags *flags)
{
	if (flags->width > 0)
		ft_putstr(width);
	ft_putstr(prefix);
	if (!(*c == '0' && (flags->is_dot || flags->cutoff || flags->width)))
		ft_putstr(c);
	if (flags->width > 0)
		ft_putstr(width);
}

static int		ft_getsize(char *c, char *prefix, char *width, t_flags *flags)
{
	int			size;

	size = 0;
	if (*c == '0' && flags->is_dot)
		size = (int)ft_strlen(prefix) + (int)ft_strlen(width);
	else
		size = (int)ft_strlen(c) + (int)ft_strlen(prefix) +
			(int)ft_strlen(width);
	ft_putline(width, prefix, c, flags);
	if (prefix)
		SMART_FREE(prefix);
	if (width)
		SMART_FREE(width);
	return (size);
}

static char		*ft_mread(va_list ap, union u_types tp)
{
	tp.ul = va_arg(ap, unsigned long long);
	return (ft_ultoa_base(tp.ul, 10));
}

int				ft_cunsigned_print(va_list ap, union u_types tp, t_flags *flags)
{
	int			size;
	char		*prefix;
	char		*width;

	size = 0;
	width = NULL;
	prefix = NULL;
	flags->target = ft_mread(ap, tp);
	ft_hex_read(flags, &prefix, &width, NULL);
	size = ft_getsize(flags->target, prefix, width, flags);
	SMART_FREE(flags->target);
	return (size);
}
