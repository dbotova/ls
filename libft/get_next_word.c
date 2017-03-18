/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 10:26:15 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/14 11:07:54 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			read_line(char *buf, char **word)
{
	char			*nword;

	nword = ft_strstr(buf, " ");
	if (nword)
	{
		*word = ft_strsub(buf, 0, nword - buf);
		ft_strncpy(buf, nword + 1, ft_strlen(nword) - 1);
		buf[ft_strlen(nword) - 1] = 0;
		SMART_FREE(buf);
		return (ft_strlen(*word) + 1);
	}
	return (0);
}

int					get_next_word(const char *line, char **word)
{
	char *str;

	str = ft_strdup(line);
	if (!word || !line)
		return (-1);
	if (*line == '\0')
		return (0);
	return (read_line(str, word));
}
