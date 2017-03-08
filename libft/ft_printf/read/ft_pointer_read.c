/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:30:43 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 18:31:51 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_creat_str(int size, char **prefix, char c)
{
	(*prefix) = (char*)malloc(size + 1);
	ft_memset(*prefix, 0, size + 1);
	ft_memset(*prefix, c, size);
}

static void	ft_dot(char *target, t_flags *flags, char **prefix)
{
	int		size;

	size = 0;
	if (*target == '0')
		size = flags->cutoff;
	size = flags->cutoff - ft_strlen(target);
	ft_creat_str(size, prefix, '0');
}

static void	ft_zero(char *target, char **prefix, t_flags *flags,
		int is_cutoff)
{
	int size;
	int w;

	size = 0;
	w = ABS(flags->width);
	if (!target)
		size = w - 1;
	else
		size = w - (is_cutoff ? flags->cutoff : ((int)ft_strlen(target) + 2));
	ft_creat_str(size, prefix, '0');
}

static void	ft_width(char *target, char **width, t_flags *flags,
		char **prefix)
{
	int		size;
	int		w;

	size = 0;
	w = ABS(flags->width);
	if (!target)
		size = w - 1;
	else
		size = w - ((int)ft_strlen(target) + 2) - (int)ft_strlen(*prefix);
	ft_creat_str(size, width, ' ');
}

char		*ft_pointer_read(char *target, t_flags *flags, char **prefix,
			char **width)
{
	int		is_cutoff;
	int		res_size;
	int		w;

	is_cutoff = 0;
	w = ABS(flags->width);
	res_size = (int)ft_strlen(target) + 2;
	if (flags->is_dot)
	{
		if (flags->cutoff < res_size)
			is_cutoff = 1;
		else
			ft_dot(target, flags, prefix);
	}
	if (flags->is_zero && flags->width >
			(is_cutoff ? flags->cutoff : res_size) && !*prefix)
		ft_zero(target, prefix, flags, is_cutoff);
	if (w > ((is_cutoff ? flags->cutoff : res_size) +
				(int)ft_strlen(*prefix)))
		ft_width(target, width, flags, prefix);
	return (target);
}
