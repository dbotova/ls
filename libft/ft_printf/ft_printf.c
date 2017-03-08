/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:22:24 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 19:44:57 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_sread(char *ptr, va_list ap, t_flags **flags, char *undef)
{
	union u_types	tp;
	int				(*jump_table[58])(va_list, union u_types tp, t_flags*);

	ft_create_jump_table(jump_table);
	*flags = ft_newflagslst();
	tp.d = 0;
	if (undef)
	{
		undef = ft_getflags(undef, flags, ap);
		return (ft_undef_print(undef, *flags));
	}
	if (ptr)
	{
		ptr = ft_getflags(ptr, flags, ap);
		if (*ptr == '%')
			return (ft_print(tp, *flags));
		if (ft_strchr(SPECS, *ptr) != NULL)
			return (jump_table[*ptr - 65](ap, tp, *flags));
	}
	return (0);
}

static int	ft_spec(char *str, char **result, char **undef)
{
	int		i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (ft_strchr(SPECS, str[i]) == NULL && str[i])
	{
		if (ft_strchr(STR, str[i]) == NULL && str[i])
		{
			while (str[i] != '%' && str[i] && ft_isalpha(str[i]))
				i++;
			if (i == 0)
				return (0);
			*undef = ft_strsub(str, 0, i);
			return ((int)ft_strlen(*undef));
		}
		i++;
	}
	if (ft_strchr(SPECS, str[i]) == NULL)
		return (0);
	*result = ft_strsub(str, 0, i + 1);
	return ((int)ft_strlen(*result));
}

static int	ft_parse(char **spec, char **undef, va_list ap)
{
	int		size;
	t_flags	*flags;

	size = ft_sread(*spec, ap, &flags, *undef);
	if (*spec)
		SMART_FREE(*spec);
	if (flags)
		SMART_FREE(flags);
	if (*undef)
		SMART_FREE(*undef);
	return (size);
}

int			ft_printf(char *args, ...)
{
	char	*spec;
	char	*undef;
	va_list	ap;
	int		size;

	va_start(ap, args);
	spec = NULL;
	size = 0;
	undef = NULL;
	while (*args)
	{
		if (*args == '%')
		{
			args += ft_spec(args + 1, &spec, &undef);
			size += (spec || undef) ? ft_parse(&spec, &undef, ap) : 0;
		}
		else
		{
			ft_putchar(*args);
			size++;
		}
		args++;
	}
	va_end(ap);
	return (size);
}
