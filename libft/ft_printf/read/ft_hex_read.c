/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:30:43 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 19:25:34 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_creat_str(int size, char **prefix, char c)
{
	(*prefix) = (char*)malloc(size + 1);
	ft_memset(*prefix, 0, size + 1);
	ft_memset(*prefix, c, size);
}

static void	ft_width(char **width, char *prefix,
			t_flags *flags, int res_size)
{
	int		size;
	int		w;

	size = 0;
	w = ABS(flags->width);
	if (!flags->target)
		size = w - 1;
	if ((*flags->target) == '0')
		size = w - (int)ft_strlen(prefix) - (flags->is_dot ? 0 :
				(int)ft_strlen(flags->target));
	else
		size = w - res_size - (int)ft_strlen(prefix);
	ft_creat_str(size, width, ' ');
}

static void	ft_dot(char *target, t_flags *flags, int res_size, char **prefix)
{
	int		size;

	size = 0;
	if (*target == '0')
		size = flags->cutoff - 1;
	else
		size = flags->cutoff - (flags->is_o ? res_size :
				(int)ft_strlen(target));
	ft_creat_str(size, prefix, '0');
}

static void	ft_zero(char **prefix, t_flags *flags,
			int res_size, int is_cutoff)
{
	int		size;
	int		w;

	size = 0;
	w = ABS(flags->width);
	if (!flags->target)
		size = w - 1;
	else
		size = w - (is_cutoff ? flags->cutoff : (res_size));
	ft_creat_str(size, prefix, '0');
}

char		*ft_hex_read(t_flags *flags, char **prefix, char **width,
			char *hash)
{
	int		is_cutoff;
	int		res_size;
	int		w;

	is_cutoff = 0;
	w = ABS(flags->width);
	res_size = (int)ft_strlen(flags->target) + (int)ft_strlen(hash);
	if (flags->is_dot)
	{
		if (flags->cutoff < res_size)
			is_cutoff = 1;
		else
			ft_dot(flags->target, flags, res_size, prefix);
	}
	if (flags->is_zero &&
			flags->width > (is_cutoff ? flags->cutoff : res_size) && !*prefix)
		ft_zero(prefix, flags, res_size, is_cutoff);
	if (w > (((*flags->target) == '0' ? 1 : res_size) +
				(int)ft_strlen(*prefix)))
		ft_width(width, *prefix, flags, res_size);
	return (flags->target);
}
