/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaruk-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:23:27 by jkaruk-m          #+#    #+#             */
/*   Updated: 2021/05/31 17:16:42 by jkaruk-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstok;
	t_list	*lsttier;

	lsttier = NULL;
	if (lst)
	{
		while (lst)
		{
			lstok = ft_lstnew((*f)(lst->content));
			if (!lstok)
			{
				ft_lstclear(&lsttier, del);
				return (NULL);
			}
			ft_lstadd_back(&lsttier, lstok);
			lst = lst->next;
		}
	}
	return (lsttier);
}
