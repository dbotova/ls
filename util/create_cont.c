#include "../ft_ls.h"

void	create_cont(t_content *cont)
{
	cont = malloc(sizeof(t_content));
	cont->size = 0;
	cont->max = 0;
	cont->rows = 0; 
}