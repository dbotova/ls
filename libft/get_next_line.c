/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 10:26:15 by dbotova           #+#    #+#             */
/*   Updated: 2016/10/11 17:10:14 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_file	*ft_flnew(int fd)
{
	t_file *file;

	file = (t_file*)malloc(sizeof(t_file));
	file->buf = ft_strnew(1);
	file->fd = fd;
	file->next = NULL;
	return (file);
}
static char	*ft_strappend(char *dest, char *src)
{
	size_t k;
	size_t m;
	char *result;

	k = ft_strlen(dest);
	m = ft_strlen(src);
	result = ft_strnew(m + k + 1);
	result = ft_strcpy(result, dest);
	result = ft_strcat(result, src);
	free(dest);
	return(result);	
}

static int	read_line(t_file *file, char **line)
{
	char *nline;

    nline = ft_strstr(file->buf, "\n");
	if (nline)
	{
		*line = ft_strsub(file->buf, 0, nline - file->buf);
		ft_strncpy(file->buf, nline + 1, ft_strlen(nline) - 1);
		file->buf[ft_strlen(nline) - 1] = 0;
		return (1);
	}
    else if (file->buf[0])
    {
        *line = ft_strdup(file->buf);
        file->buf[0] = 0;
        return (1);
    }
    return (0);
}

t_file *get_file(int fd)
{
    static t_file *files;
    t_file *tmp;

    if (!files)
    {
        files = ft_flnew(fd);
        tmp = files;
    }
    else
    {
        tmp = files;
        while (tmp->next && tmp->fd != fd)
            tmp = tmp->next;
        if (tmp->fd != fd)
        {
            tmp->next = ft_flnew(fd);
            tmp = tmp->next;
        }
    }
    return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	ssize_t res;
    char str[BUFF_SIZE + 1];
    t_file *file;

    file = get_file(fd);
	if (fd < 0 || !line)
		return (-1);

    while (ft_strstr(file->buf, "\n") == NULL)
    {
        res = read(file->fd, str, BUFF_SIZE);
        if (res < 0)
            return -1;
        if (res == 0)
            break;
        str[res] = 0;
        file->buf = ft_strappend(file->buf, str);
    }
    
    return read_line(file, line);
}
