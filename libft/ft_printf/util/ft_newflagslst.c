/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newflagslst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 07:51:46 by dbotova           #+#    #+#             */
/*   Updated: 2016/11/22 07:51:48 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_flags	*ft_newflagslst(void)
{
	t_flags *flags;

	flags = malloc(sizeof(t_flags));
	flags->is_minus = 0;
	flags->is_hash = 0;
	flags->is_dot = 0;
	flags->width = 0;
	flags->is_zero = 0;
	flags->is_plus = 0;
	flags->cutoff = 0;
	flags->is_l = 0;
	flags->is_j = 0;
	flags->is_h = 0;
	flags->is_o = 0;
	flags->is_space = 0;
	flags->is_z = 0;
	flags->is_cl = 0;
	flags->is_separete = 0;
	flags->target = NULL;
	return (flags);
}
