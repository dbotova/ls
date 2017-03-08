/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 07:56:11 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 16:51:57 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_putline(char *width_left, char *prefix, char *c,
		char *width_right)
{
	ft_putstr(width_left);
	ft_putstr(prefix);
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

int			ft_print(union u_types tp, t_flags *flags)
{
	int		size;
	char	*prefix;
	char	*width;

	size = 0;
	width = NULL;
	prefix = NULL;
	tp.s = "%\0";
	ft_char_read(tp.s, flags, &prefix, &width);
	size = ft_getsize(tp.s, prefix, width, flags);
	return (size);
}
