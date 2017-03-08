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

void	create_cont(t_content *cont)
{
	cont = malloc(sizeof(t_content));
	cont->size = 0;
	cont->max = 0;
	cont->rows = 0; 
}
