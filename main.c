/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:33:53 by dbotova           #+#    #+#             */
/*   Updated: 2017/02/27 15:33:55 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main (int argc, char **argv)
{
	t_args *args;
	
	// args = take_args(arg1, arg2);

	if (argc == 1)
		args = take_args(NULL, NULL);
	else if (argc == 2)
		args = take_args(argv[1], NULL);
	else if (argc == 3)
		args = take_args(argv[1], argv[2]);
	else
		exit(1);

	ft_ls(args);
	return (0);
}
