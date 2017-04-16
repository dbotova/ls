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

static	void		print_time(t_content *cont, int i, char *options)
{
	time_t			raw_time;
	time_t			cur_time;
	char			r_time[25];
	char			c_time[25];

	if (has_option(options, 'u'))
		raw_time = cont->arr[i].atime;
	if (!has_option(options, 'c'))
		raw_time = cont->arr[i].mtime;
	else
		raw_time = cont->arr[i].ctime;
	cur_time = time(NULL);
	ft_strcpy(r_time, ctime(&raw_time));
	ft_strcpy(c_time, ctime(&cur_time));
	ft_printf("%.3s %.2s ", r_time + 4, r_time + 8);
	if (ft_strcmp(c_time + 20, r_time + 20) == 0)
		ft_printf("%.5s ", r_time + 11);
	else
		ft_printf("%s", r_time + 20);
}

static	void		print_lnk_user_group_size(struct stat buf, char *options)
{
	struct group	*grp;
	struct passwd	*pwd;

	grp = getgrgid(buf.st_gid);
	pwd = getpwuid(buf.st_uid);
	ft_printf("%3d ", buf.st_nlink);
	if (!has_option(options, 'g'))
		ft_printf("%s ", pwd->pw_name);
	ft_printf(" %s %7d ", grp->gr_name, buf.st_size);
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

static void			print_link(struct stat buf, int i, t_content *cont)
{
	char			*lname;

	lname = NULL;
	lname = malloc(sizeof(char) * (buf.st_size + 1));
	if ((readlink(cont->arr[i].item.d_name, lname, buf.st_size + 1)) < 0)
		perror("ft_ls");
	else
	{
		lname[buf.st_size] = 0;
		ft_printf("%s -> %s\n", cont->arr[i].item.d_name, lname);
	}
	SMART_FREE(lname);
}

void				print_long_format(char *location, char *options,
					t_content *cont)
{
	struct stat		buf;
	int				i;

	i = 0;
	ft_printf("total %d\n", cont->total);
	while (i < cont->size)
	{
		if (lstat(get_path(location, cont->arr[i].item.d_name), &buf) == -1)
		{
			perror(get_path(location, cont->arr[i].item.d_name));
			exit(1);
		}
		print_perms(buf);
		print_lnk_user_group_size(buf, options);
		print_time(cont, i, options);
		if (S_ISLNK(buf.st_mode))
			print_link(buf, i, cont);
		else
			ft_printf("%s\n", cont->arr[i].item.d_name);
		i++;
	}
}
