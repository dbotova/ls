/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 20:11:03 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/30 20:34:12 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cpy(char const *s, char *result, char c)
{
	while (*s && *s != c)
		*result++ = *s++;
	*result = '\0';
}

static int	ft_wdcnt(char const *s, char c)
{
	int size;

	if (!s)
		return (-1);
	size = 0;
	while (s && *s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			size++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (size);
}

static int	ft_numchars(const char *s, char c)
{
	int result;

	result = 0;
	while (*s && *s != c)
	{
		s++;
		result++;
	}
	return (result);
}

static char	**ft_alloc_array(int count)
{
	char **result;

	result = (char **)malloc(sizeof(char*) * count);
	if (result)
	{
		result[count - 1] = NULL;
	}
	return (result);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		idx;
	int		size;
	size_t	malloc_size;

	idx = 0;
	result = NULL;
	if ((size = ft_wdcnt(s, c)) < 0)
		return (NULL);
	if ((result = ft_alloc_array(size + 1)) == NULL)
		return (NULL);
	while (idx < size)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			malloc_size = ft_numchars(s, c);
			if ((result[idx] = (char *)malloc(malloc_size + 1)))
				ft_cpy(s, result[idx], c);
			s += malloc_size;
		}
		idx++;
	}
	return (result);
}
