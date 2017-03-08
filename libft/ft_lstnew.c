/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 11:45:19 by dbotova           #+#    #+#             */
/*   Updated: 2016/10/02 11:45:20 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = (t_list*)malloc(sizeof(t_list));
	if (list)
	{
		if (content)
		{
			if (!(list->content = (void *)malloc(sizeof(void) * content_size)))
				return (NULL);
			ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
			list->next = NULL;
		}
		else
		{
			list->content = NULL;
			list->content_size = 0;
		}
	}
	return (list);
}
