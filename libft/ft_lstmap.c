/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 13:16:03 by dbotova           #+#    #+#             */
/*   Updated: 2016/10/02 13:16:04 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *tmp;
	t_list *prev;

	result = NULL;
	if (lst)
	{
		result = f(lst);
		prev = result;
		lst = lst->next;
		while (lst)
		{
			tmp = f(lst);
			prev->next = tmp;
			prev = tmp;
			lst = lst->next;
		}
		prev->next = NULL;
	}
	return (result);
}
