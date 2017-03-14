/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:50:37 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/29 20:50:43 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*str_new;
	size_t	len;
	size_t	counter;

	str = (char*)s;
	if (!str)
		return (NULL);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	len = ft_strlen(str) - 1;
	if (ft_strlen(str) == 0)
		return (str_new = ft_strnew(0));
	while (str[len] == ' ' || str[len] == '\t' || str[len] == '\n')
		len--;
	if (!(str_new = ft_strnew(len + 1)))
		return (NULL);
	counter = 0;
	while (counter <= len)
	{
		str_new[counter] = str[counter];
		counter++;
	}
	str_new[counter] = 0;
	return (str_new);
}
