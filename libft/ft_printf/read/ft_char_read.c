/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:30:43 by dbotova           #+#    #+#             */
/*   Updated: 2016/11/22 10:30:45 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_creat_str(int size, char **prefix, char c)
{
	(*prefix) = (char*)malloc(size + 1);
	ft_memset(*prefix, 0, size + 1);
	ft_memset(*prefix, c, size);
}

char		*ft_char_read(char *target, t_flags *flags, char **prefix,
		char **width)
{
	int size;
	int w;

	size = 0;
	w = ABS(flags->width);
	if (flags->is_zero && flags->width)
	{
		if (!*target)
			size = w - 1;
		else
			size = w - (int)ft_strlen(target);
		ft_creat_str(size, prefix, '0');
	}
	if (w > ((int)ft_strlen(*prefix) + 1))
	{
		if (!*target)
			size = w - 1;
		else
			size = w - (int)ft_strlen(target) - (int)ft_strlen(*prefix);
		ft_creat_str(size, width, ' ');
	}
	return (target);
}
