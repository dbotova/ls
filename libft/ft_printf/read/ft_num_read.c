/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:30:43 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 18:15:35 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_creat_str(int size, char **prefix, char c)
{
	(*prefix) = (char*)malloc(size + 1);
	ft_memset(*prefix, 0, size + 1);
	ft_memset(*prefix, c, size);
}

static int	calcsize(char *target, t_flags *flags)
{
	int		size;

	size = (int)ft_strlen(target);
	if (*target == '-' && (*target == '0' || flags->is_dot))
		size--;
	if (flags->is_plus && *target != '-' && !flags->is_dot)
		size++;
	if (flags->is_space && !flags->is_minus && !flags->is_plus
			&& *target != '-' && !flags->is_dot)
		size++;
	return (size);
}

static void	ft_dot(char *target, char **prefix, t_flags *flags,
		int total_size)
{
	int	size;

	size = 0;
	if (*target == '0')
		size = flags->cutoff - 1;
	else
		size = flags->cutoff - total_size;
	ft_creat_str(size, prefix, '0');
}

static void	ft_width(char *target, char **width, t_flags *flags, char *prefix)
{
	int size;
	int	w;

	size = 0;
	w = ABS(flags->width);
	if (!target || *target == '0')
		size = w - 1;
	if (*target == '0' && !flags->cutoff && flags->is_dot)
		size = w;
	else
		size = w - (int)ft_strlen(target) - (int)ft_strlen(prefix) -
			(*target == '-' ? 0 : flags->is_plus) - flags->is_space;
	ft_creat_str(size, width, ' ');
}

char		*ft_num_read(char *target, t_flags *flags, char **prefix,
			char **width)
{
	int		size;
	int		total_size;
	int		is_cutoff;
	int		w;

	is_cutoff = 0;
	size = 0;
	total_size = calcsize(target, flags);
	w = ABS(flags->width);
	if (flags->is_dot && flags->cutoff > total_size)
		ft_dot(target, prefix, flags, total_size);
	if (flags->is_zero &&
			flags->width > total_size && !*prefix)
	{
		if (!target)
			size = w - 1;
		else
			size = w - total_size;
		ft_creat_str(size, prefix, '0');
	}
	if (w > (total_size + (int)ft_strlen(*prefix)))
		ft_width(target, width, flags, *prefix);
	return (target);
}
