/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nixs0 <nixs0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:44:42 by nixs0             #+#    #+#             */
/*   Updated: 2021/05/31 02:33:39 by nixs0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*to_clear;
	t_list	*next;

	to_clear = NULL;
	next = NULL;
	if (!lst)
		return ;
	to_clear = *lst;
	next = to_clear->next;
	while (to_clear != NULL)
	{
		next = to_clear->next;
		del(to_clear->content);
		free(to_clear);
		to_clear = next;
	}
	*lst = NULL;
}
