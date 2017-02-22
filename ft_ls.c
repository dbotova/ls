#include "ft_ls.h"

void	ft_ls(char *args, ...)
{
	char *ptr;
	char *spec;
	va_list ap;
	t_flags *flags;

	va_start(ap, args);
	ptr = args;
	spec = NULL;
	size = 0;
	undef = NULL;
	while (*ptr)
	{
		if (*ptr == '-')
		{
			ptr += ft_spec(ptr + 1, &spec);
			if (spec || undef)
			{
				//ft_sread(spec, ap, &flags, undef);
				if (spec)
					SMART_FREE(spec);
				if (flags)
					SMART_FREE(flags);
			}
		}
		else
		{
			ft_putchar(*ptr);
		}
		ptr++;
	}
	va_end(ap);
}