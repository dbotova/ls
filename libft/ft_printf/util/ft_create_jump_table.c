/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_jump_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:29:32 by dbotova           #+#    #+#             */
/*   Updated: 2016/11/28 16:29:34 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_create_jump_table(int (*jump_table[])(va_list ap,
		union u_types, t_flags *flags))
{
	jump_table['c' - 65] = &ft_char_print;
	jump_table['C' - 65] = &ft_cchar_print;
	jump_table['s' - 65] = &ft_str_print;
	jump_table['S' - 65] = &ft_cstr_print;
	jump_table['d' - 65] = &ft_int_print;
	jump_table['D' - 65] = &ft_cint_print;
	jump_table['f' - 65] = &ft_float_print;
	jump_table['F' - 65] = &ft_float_print;
	jump_table['p' - 65] = &ft_pointer_print;
	jump_table['o' - 65] = &ft_octa_print;
	jump_table['i' - 65] = &ft_int_print;
	jump_table['O' - 65] = &ft_cocta_print;
	jump_table['u' - 65] = &ft_unsigned_print;
	jump_table['U' - 65] = &ft_cunsigned_print;
	jump_table['x' - 65] = &ft_hex_print;
	jump_table['X' - 65] = &ft_chex_print;
}
