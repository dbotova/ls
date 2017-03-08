/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:30:43 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 18:36:27 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_creat_str(int size, char **prefix, char c)
{
	(*prefix) = (char*)malloc(size + 1);
	ft_memset(*prefix, 0, size + 1);
	ft_memset(*prefix, c, size);
}

wchar_t		*ft_wstr_read(wchar_t *target, t_flags *flags, char **prefix,
			char **width)
{
	int		size;
	int		is_c;
	int		w;

	is_c = 0;
	w = ABS(flags->width);
	if (flags->is_dot && flags->cutoff < (int)ft_wstrlen(target))
		is_c = 1;
	if (flags->is_zero &&
			flags->width > (is_c ? flags->cutoff : (int)ft_wstrlen(target)))
	{
		size = w - (is_c ? flags->cutoff : (int)ft_wstrlen(target));
		ft_creat_str(size, prefix, '0');
	}
	if (flags->width != 0 && w > ((is_c ? flags->cutoff :
					(int)ft_wstrlen(target)) + (int)ft_strlen(*prefix)))
	{
		if (!target)
			size = w - 1;
		else
			size = w - (is_c ? flags->cutoff : (int)ft_wstrlen(target))
				- (int)ft_strlen(*prefix);
		ft_creat_str(size, width, ' ');
	}
	return (target);
}
