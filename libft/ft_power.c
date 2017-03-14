/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:38:19 by dbotova           #+#    #+#             */
/*   Updated: 2016/11/25 13:38:20 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_power(int n, int pow)
{
	int count;
	int nb;

	count = 1;
	nb = n;
	if (pow == 0)
		return (1);
	while (count < pow)
	{
		nb = nb * n;
		count++;
	}
	return (nb);
}
