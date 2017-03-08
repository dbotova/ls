/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 13:56:11 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/02 13:56:13 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_flag_is_minus(char *ptr, t_flags **flags)
{
	if (*(ptr + 1) == '+')
		(*flags)->is_minus = 1;
	if (*(ptr + 1) == 0 && !(*flags)->is_dot)
		(*flags)->is_zero = 1;
	if (ft_isdigit(*(ptr + 1)) || *(ptr + 1) == '+')
	{
		if (!(*flags)->is_dot)
			return (ft_getnum(ptr, &(*flags)->width));
		else
			return (ft_getnum(ptr, &(*flags)->cutoff));
	}
	else
		(*flags)->is_minus = 1;
	return (1);
}

static int	ft_flag_is_ast(t_flags **flags, va_list ap)
{
	int i;

	i = va_arg(ap, int);
	if (!(*flags)->is_dot)
	{
		if (i < 0)
			(*flags)->is_minus = 1;
		(*flags)->width = i;
	}
	else
		(*flags)->cutoff = i;
	return (1);
}

static int	ft_flag_is_digit(char *ptr, t_flags **flags)
{
	int size;

	size = 0;
	if (!(*flags)->is_dot)
	{
		size = ft_getnum(ptr, &(*flags)->width);
		if ((*flags)->is_minus && (*flags)->width > 0)
			(*flags)->width *= -1;
	}
	else
		size = ft_getnum(ptr, &(*flags)->cutoff);
	return (size);
}

static void	ft_get_extra(char *ptr, t_flags **flags)
{
	if (*ptr == '#')
		(*flags)->is_hash = 1;
	if (*ptr == 'l')
		(*flags)->is_l += 1;
	if (*ptr == 'h')
		(*flags)->is_h += 1;
	if (*ptr == 'j')
		(*flags)->is_j = 1;
	if (*ptr == 'z')
		(*flags)->is_z = 1;
	if (*ptr == '+')
		(*flags)->is_plus = 1;
	if (*ptr == 'L')
		(*flags)->is_cl = 1;
}

char		*ft_getflags(char *ptr, t_flags **flags, va_list ap)
{
	if (ft_strchr(FLAGS, *ptr) != NULL)
	{
		ft_get_extra(ptr, flags);
		if (*ptr == '-')
			return (ft_getflags(ptr + ft_flag_is_minus(ptr, flags), flags, ap));
		if (*ptr == ' ')
			(*flags)->is_space = 1;
		if (*ptr == 39)
			(*flags)->is_separete = 1;
		if (*ptr == '*')
			return (ft_getflags(ptr + ft_flag_is_ast(flags, ap), flags, ap));
		if (*ptr == '0' && !(*flags)->is_dot)
			(*flags)->is_zero = 1;
		if (ft_isdigit(*ptr) && *ptr != '0')
			return (ft_getflags(ptr + ft_flag_is_digit(ptr, flags), flags, ap));
		if (*ptr == '.')
			(*flags)->is_dot = 1;
		return (ft_getflags(ptr + 1, flags, ap));
	}
	return (ptr);
}
