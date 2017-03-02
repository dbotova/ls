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

static int	is_dir(char *path)
{
	struct stat statbuf;
	if (stat(path, &statbuf) == -1)
    {
        perror(path);
        exit(1);
    }
	if (S_ISDIR(statbuf.st_mode))
		return (1);
	else
		return (0);
}

static void get_path(char *path, char *name, char *d_name)
{
    ft_memset(path, 0, 1024);
    ft_strcpy(path, name);
    ft_strcat(path, "/");
    ft_strcat(path, d_name);
}

int listdir(char *name, struct dirent arr[], int i)
{
    DIR *dir;
    struct dirent *entry;
    char path[1024];

    if (!(dir = opendir(name)))
    {
        ft_printf("ft_ls: %s ", name);
        perror("");
        exit(1);
    }
    if (!(entry = readdir(dir)))
    {
        ft_printf("ft_ls: %s ", name);
        perror("");
        exit(1);
    }
    while ((entry = readdir(dir)) != NULL)
    {
        get_path(path, name, entry->d_name);
        arr[i] = *entry;

        printf("name: %s\n", arr[i].d_name);

        if (is_dir(path))
        {
            listdir(path, arr, i);
            closedir(dir);
        }
        i++;
    }
    closedir(dir);
    return (i);
}

// void listdir(char *name, int level)
// {
//     DIR *dir;
//     struct dirent *entry;
//     char path[1024];

//     if (!(dir = opendir(name)))
//     {
//         ft_printf("ft_ls: %s ", name);
//         perror("");
//         exit(1);
//     }
//     if (!(entry = readdir(dir)))
//     {
//         ft_printf("ft_ls: %s ", name);
//         perror("");
//         exit(1);
//     }
//     while ((entry = readdir(dir)) != NULL)
//     {
//         get_path(path, name, entry->d_name);
//         if (is_dir(path))
//         {
//             if (entry->d_name[0] == '.')
//                 continue ;
//             ft_printf("%s./%s\n", "", entry->d_name);
//             listdir(path, level + 1);
//         }
//         else
//         {
//             if (entry->d_name[0] == '.')
//                 continue ;
//             ft_printf("%s%s\n", "", entry->d_name);
//         }
//     }
//     closedir(dir);
// }