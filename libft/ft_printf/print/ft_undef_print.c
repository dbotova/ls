/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:17:52 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 17:46:21 by dbotova          ###   ########.fr       */
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

	if (!c)
		size = -1;
	if (c && *c == '\0')
		size = (int)ft_strlen(prefix) + (int)ft_strlen(width);
	else
	{
		if (flags->is_dot && (int)ft_strlen(c) > flags->cutoff &&
				flags->cutoff)
			size = flags->cutoff + (int)ft_strlen(prefix) +
				(int)ft_strlen(width);
		else
			size = (int)ft_strlen(c) + (int)ft_strlen(prefix) +
				(int)ft_strlen(width);
	}
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

int			ft_undef_print(char *ptr, t_flags *flags)
{
	int		size;
	char	*prefix;
	char	*width;

	size = 0;
	prefix = NULL;
	width = NULL;
	ft_undef_read(ptr, flags, &prefix, &width);
	size = ft_getsize(ptr, prefix, width, flags);
	return (size);
}
