/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 13:52:14 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/02 13:52:17 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getnum(char *str, int *value)
{
	int size;
	int i;

	size = 0;
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] == '0')
	{
		i++;
		size++;
	}
	*value = ft_atoi(str);
	size += ft_nbrsize(*value);
	return (size);
}
