/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:17:52 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 16:45:08 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	*ft_nullstr(void)
{
	return ("(null)");
}

static void	ft_putline(char *width, char *prefix, char *c, t_flags *flags)
{
	if (flags->width > 0)
		ft_putstr(width);
	ft_putstr(prefix);
	if (flags->is_dot)
	{
		if (flags->cutoff > 0 && flags->cutoff < (int)ft_strlen(c))
			ft_putnstr(c, flags->cutoff);
		else if (!(flags->is_dot && !flags->cutoff))
			ft_putstr(c);
	}
	else
		ft_putstr(c);
	if (flags->width < 0)
		ft_putstr(width);
}

static int	ft_getsize(char *c, char *prefix, char *width, t_flags *flags)
{
	int		size;

	if (!c)
		size = -1;
	if (c && *c == '\0')
		size = (int)ft_strlen(prefix) + (int)ft_strlen(width);
	else
	{
		if (flags->is_dot && (int)ft_strlen(c) > flags->cutoff &&
			flags->cutoff > 0)
			size = flags->cutoff + (int)ft_strlen(prefix) +
				(int)ft_strlen(width);
		else if (flags->is_dot && !flags->cutoff)
			size = (int)ft_strlen(prefix) + (int)ft_strlen(width);
		else
			size = (int)ft_strlen(c) + (int)ft_strlen(prefix) +
				(int)ft_strlen(width);
	}
	ft_putline(width, prefix, c, flags);
	if (prefix)
		SMART_FREE(prefix);
	if (width)
		SMART_FREE(width);
	return (size);
}

int			ft_str_print(va_list ap, union u_types tp, t_flags *flags)
{
	int		size;
	char	*prefix;
	char	*width;
	char	*str;

	size = 0;
	prefix = NULL;
	width = NULL;
	str = NULL;
	if (flags->is_l)
		return (ft_cstr_print(ap, tp, flags));
	else
	{
		tp.s = va_arg(ap, char *);
		if (!tp.s)
			tp.s = (!flags->is_dot) ? ft_nullstr() : "\0";
		str = ft_str_read(tp.s, flags, &prefix, &width);
		size = ft_getsize(str, prefix, width, flags);
		SMART_FREE(str);
	}
	return (size);
}
