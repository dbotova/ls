/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:43:50 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/26 16:43:52 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	int		len;
	char	*result;

	len = 0;
	len = (int)ft_strlen(string);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result)
		result = ft_strcpy(result, string);
	return (result);
}
