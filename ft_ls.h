/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:34:09 by dbotova           #+#    #+#             */
/*   Updated: 2017/02/27 15:34:11 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <grp.h>
# define OPTINOS "alrRt"
# define OPTIONS_SIZE 10

typedef struct	s_args
{
	DIR			*dir;
	char		*options;
	char		*name;
}				t_args;

void	ft_ls(char *location, char *oprtions);
void 	listdir(char *name, int level);
void	listfiles(char *location, char *oprtions);
void	take_args(char *arg1, char *arg2, char **location, char **options);

#endif
