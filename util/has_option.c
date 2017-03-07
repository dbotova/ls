#include "../ft_ls.h"

int	has_option(char *options, char c)
{
	char *tmp;

	tmp = options;
	if (ft_strchr(tmp, c))
		return (1);
	return (0);
}