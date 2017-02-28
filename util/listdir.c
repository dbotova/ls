/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:05:28 by dbotova           #+#    #+#             */
/*   Updated: 2017/02/27 18:05:30 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void listdir(char *name, int level)
{
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(name)))
        return;
    if (!(entry = readdir(dir)))
        return;

    do {
        if (entry->d_type == DT_DIR) 
        {
            char path[1024];
            int len = snprintf(path, sizeof(path)-1, "%s/%s", name, entry->d_name);
            path[len] = 0;
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            printf("%*s[%s]\n", level*2, "", entry->d_name);
            listdir(path, level + 1);
        }
        else
        {
        	 printf("%*s- %s\n", level*2, "", entry->d_name);
   //      	//while ((entry = readdir(dir)) != NULL)
			// {
			// 	if (entry->d_name[0] != '.')
			// 		ft_printf("%s\n", entry->d_name);
			// }
        }
    } while ((entry = readdir(dir)) != NULL);
    closedir(dir);
}