/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 10:18:10 by dbotova           #+#    #+#             */
/*   Updated: 2017/02/11 10:27:25 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char *line;
	int res;
	int fd;
	int n;

	n = 1;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY | S_IRUSR);
       
		while((res = get_next_line(fd, &line)) > 0)
		{
			printf("#%d\n", n++);
			printf("LINE: %s\n", line);
			printf("RES:  %d\n", res);
			printf("LEN:  %zu\n\n\n", strlen(line));
			if (*line)
				free(line);
			line = NULL;
		}
//		 printf("LINE: %s\n", line);
//		 printf("RES: %d\n", res);
//		 printf("LEN:  %zu\n", strlen(line));
//		 if (*line)
//		 	free(line);
//		 line = NULL;
//		 close(fd);
	}
	else if (argc == 1)
	{
		 // fd = open("some.txt", O_RDONLY | S_IRUSR);
		 // printf("FD: \n", fd);
		 while ((res = get_next_line(0, &line) > 0))
		 {
		 	printf("LINE: %s\n", line);
		 	printf("RES:  %d\n", res);
		 	free(line);
		 }
		printf("RES:  %d\n", get_next_line(-3, &line));
	}
	else
	{
		int fd1 = open(argv[1], O_RDONLY | S_IRUSR);
		int fd2 = open(argv[2], O_RDONLY | S_IRUSR);
		get_next_line(fd1, &line);
		printf("LN1:%s FD: %d\n", line, fd1);
		if (*line)
				free(line);
		get_next_line(fd2, &line);
		printf("LN2: %s FD: %d\n", line, fd2);
		if (*line)
				free(line);
		get_next_line(fd1, &line);
		printf("LN1:%s FD: %d\n", line, fd1);
		if (*line)
				free(line);
	}

	ft_printf("I did it!!!!");
	return (0);
}
