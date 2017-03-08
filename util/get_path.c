#include "../ft_ls.h"

char		*get_path(char *name, char *d_name)
{
	char	*path;

	path = (char*)malloc(sizeof(char) * 1024);
    ft_memset(path, 0, 1024);
	ft_strcpy(path, name);
	if (name[ft_strlen(name) -1] != '/')
		ft_strcat(path, "/");
    ft_strcat(path, d_name);
    return(path);
}