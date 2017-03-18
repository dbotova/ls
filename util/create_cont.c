/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cont.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:24:39 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/07 18:24:40 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	create_cont(t_content **cont, char *location)
{
	(*cont) = malloc(sizeof(t_content));
	(*cont)->size = 0;
	(*cont)->max = 0;
	(*cont)->rows = 0;
	(*cont)->w_size = 0;
	(*cont)->total = 0;
	(*cont)->location = (char*)malloc(sizeof(char) * 1024);
	ft_memset((*cont)->location, 0, 1024);
	(*cont)->location = ft_strdup(location);
}
