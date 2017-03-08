/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:23:58 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/07 18:23:59 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static	void		print_time(struct stat buf)
{
	time_t raw_time;
	time_t cur_time;
	char r_time[25];
	char c_time[25];

	raw_time = buf.st_mtime;
	cur_time = time(NULL);
	ft_strcpy(r_time, ctime(&raw_time));
	ft_strcpy(c_time, ctime(&cur_time));
	ft_printf("%.3s %.2s ", r_time+4, r_time+8);
	if (ft_strcmp(c_time+20, r_time+20) == 0)
		ft_printf("%.5s ", r_time+11);
	else
		ft_printf("%s", r_time+20);
}

static	void		print_lnk_user_group_size(struct stat buf)
{
	struct group	*grp;
	struct passwd	*pwd;

	grp = getgrgid(buf.st_gid);
	pwd = getpwuid(buf.st_uid);
	ft_printf("%3d %s  %s %7d ", buf.st_nlink, pwd->pw_name,
		grp->gr_name, buf.st_size);
}

static	void		print_perms(struct stat buf)
{
	if (S_ISLNK(buf.st_mode))
		ft_printf("l");
	else 
		ft_printf((S_ISDIR(buf.st_mode)) ? "d" : "-");
    ft_printf((buf.st_mode & S_IRUSR) ? "r" : "-");
    ft_printf((buf.st_mode & S_IWUSR) ? "w" : "-");
    ft_printf((buf.st_mode & S_IXUSR) ? "x" : "-");
    ft_printf((buf.st_mode & S_IRGRP) ? "r" : "-");
    ft_printf((buf.st_mode & S_IWGRP) ? "w" : "-");
    ft_printf((buf.st_mode & S_IXGRP) ? "x" : "-");
    ft_printf((buf.st_mode & S_IROTH) ? "r" : "-");
    ft_printf((buf.st_mode & S_IWOTH) ? "w" : "-");
    ft_printf((buf.st_mode & S_IXOTH) ? "x  " : "-  ");
}

void			print_long_format(char *location, t_content *cont)
{
	struct		stat buf;
	int			total;
	int			i;

	total = 0;
	i = 0;
	while (i < cont->size)
	{
		if (stat(get_path(location, cont->arr[i].d_name), &buf) == -1)
	    {
	        perror(get_path(location, cont->arr[i].d_name));
	        exit(1);
	    }
	    total += buf.st_blocks;
	    print_perms(buf);
	    print_lnk_user_group_size(buf);
	    print_time(buf);
	    ft_printf("%s\n", cont->arr[i].d_name);
	    i++;
	}
	ft_printf("total %d\n", total); //fix
}
