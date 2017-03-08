/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:30:43 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 18:59:28 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_creat_str(int size, char **prefix, char c)
{
	(*prefix) = (char*)malloc(size + 1);
	ft_memset(*prefix, 0, size + 1);
	ft_memset(*prefix, c, size);
}

static void	ft_width(char *target, char **prefix, char **width, t_flags *flags)
{
	int		size;
	int		w;
	int		total_size;

	size = 0;
	w = ABS(flags->width);
	if (flags->is_dot && flags->cutoff > 0 &&
			flags->cutoff < (int)ft_strlen(target))
		total_size = flags->cutoff;
	else
		total_size = (int)ft_strlen(target);
	if (flags->is_dot && !flags->cutoff && *target != '\0')
		size = w;
	else
	{
		if (!target)
			size = w - 1;
		else
			size = w - total_size - (int)ft_strlen(*prefix);
	}
	ft_creat_str(size, width, ' ');
}

char		*ft_str_read(char *target, t_flags *flags, char **prefix,
			char **width)
{
	int		total_size;
	int		w;

	total_size = (int)ft_strlen(target);
	w = ABS(flags->width);
	if (flags->is_dot && flags->cutoff > 0 &&
			flags->cutoff < (int)ft_strlen(target))
		total_size = flags->cutoff;
	if (flags->is_zero && flags->width > total_size)
		ft_creat_str(w - total_size, prefix, '0');
	if ((w > (total_size + (int)ft_strlen(*prefix))) ||
			(flags->is_dot && !flags->cutoff))
		ft_width(target, prefix, width, flags);
	return (ft_strdup(target));
}
