/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaruk-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:23:27 by jkaruk-m          #+#    #+#             */
/*   Updated: 2021/05/31 14:39:26 by jkaruk-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*start_lst;

	start_lst = NULL;
	if (lst)
	{
		while (lst)
		{
			new_lst = ft_lstnew((*f)(lst->content));
			if (!new_lst)
			{
				ft_lstclear(&start_lst, del);
				return (NULL);
			}
			ft_lstadd_back(&start_lst, new_lst);
			lst = lst->next;
		}
	}
	return (new_lst);
}
