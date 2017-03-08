/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:23:48 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 16:54:49 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_putline(char *width_left, char *prefix, char *c,
			char *width_right)
{
	ft_putstr(width_left);
	ft_putstr(prefix);
	if (*c == 0)
		ft_putchar(0);
	else
		ft_putstr(c);
	ft_putstr(width_right);
}

static int	ft_getsize(char *c, char *prefix, char *width, t_flags *flags)
{
	int		size;

	size = (int)ft_strlen(c) + (int)ft_strlen(prefix) + (int)ft_strlen(width);
	if (c[0] == 0)
		size++;
	if (flags->width > 0)
		ft_putline(width, prefix, c, NULL);
	else
		ft_putline(NULL, prefix, c, width);
	if (prefix)
		SMART_FREE(prefix);
	if (width)
		SMART_FREE(width);
	return (size);
}

int			ft_char_print(va_list ap, union u_types tp, t_flags *flags)
{
	char	c[2];
	int		size;
	char	*prefix;
	char	*width;

	size = 0;
	width = NULL;
	prefix = NULL;
	if (flags->is_l)
		return (ft_cchar_print(ap, tp, flags));
	else
	{
		tp.c = va_arg(ap, int);
		c[1] = 0;
		c[0] = tp.c;
		ft_char_read(c, flags, &prefix, &width);
		size = ft_getsize(c, prefix, width, flags);
	}
	return ((size != 0) ? size : 1);
}
