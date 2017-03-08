/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Sprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:31:38 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 16:02:47 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static wchar_t	*ft_nullstr(void)
{
	return (L"(null)");
}

static void		ft_putline(char *width, char *prefix, wchar_t *c,
				t_flags *flags)
{
	if (flags->width > 0)
		ft_putstr(width);
	ft_putstr(prefix);
	ft_putwstr(c, (flags->is_dot ? flags->cutoff : (int)ft_wstrlen(c)));
	if (flags->width < 0)
		ft_putstr(width);
}

static int		ft_getsize(wchar_t *c, char *prefix, char *width,
				t_flags *flags)
{
	int			size;

	if (!c)
		size = -1;
	if (c && *c == '\0')
		size = (int)ft_strlen(prefix) + (int)ft_strlen(width);
	else
	{
		if (flags->is_dot && (int)ft_wstrlen(c) > flags->cutoff)
			size = flags->cutoff + (int)ft_strlen(prefix) +
				(int)ft_strlen(width);
		else
			size = (int)ft_wstrlen(c) + (int)ft_strlen(prefix) +
				(int)ft_strlen(width);
	}
	ft_putline(width, prefix, c, flags);
	if (prefix)
		SMART_FREE(prefix);
	if (width)
		SMART_FREE(width);
	return (size);
}

int				ft_cstr_print(va_list ap, union u_types tp, t_flags *flags)
{
	int			size;
	char		*prefix;
	char		*width;

	size = 0;
	prefix = NULL;
	width = NULL;
	tp.ws = va_arg(ap, wchar_t*);
	if (!tp.ws)
		tp.ws = ft_nullstr();
	if ((int)ft_wstrlen(tp.ws) > flags->cutoff &&
			flags->cutoff % (int)ft_wcharlen(*tp.ws) != 0)
		flags->cutoff -= flags->cutoff % (int)ft_wcharlen(*tp.ws);
	ft_wstr_read(tp.ws, flags, &prefix, &width);
	size = ft_getsize(tp.ws, prefix, width, flags);
	return (size);
}
