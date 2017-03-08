#include "../ft_ls.h"

void		get_path(char *path, char *name, char *d_name)
{
    ft_memset(path, 0, 1024);
	ft_strcpy(path, name);
	if (name[ft_strlen(name) -1] != '/')
		ft_strcat(path, "/");
    ft_strcat(path, d_name);
}