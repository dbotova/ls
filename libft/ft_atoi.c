/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:40:11 by dbotova           #+#    #+#             */
/*   Updated: 2016/10/12 16:18:12 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int idx;
	int result;
	int negative;

	idx = 0;
	result = 0;
	negative = 0;
	while (str[idx] == '\f' || str[idx] == '\n' || str[idx] == '\r'
			|| str[idx] == '\t' || str[idx] == '\v' || str[idx] == ' ')
		idx++;
	if (str[idx] == '-')
		negative = 1;
	if (str[idx] == '+' || str[idx] == '-')
		idx++;
	while (str[idx] <= '9' && str[idx] >= '0')
	{
		result = result * 10 + str[idx] - '0';
		idx++;
	}
	if (negative == 1)
		return (-result);
	else
		return (result);
}
