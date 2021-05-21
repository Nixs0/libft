/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaruk-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:22:07 by jkaruk-m          #+#    #+#             */
/*   Updated: 2021/05/21 16:22:28 by jkaruk-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_total_len(char *s, char c)
{
	int i;
	int letters;
	int words;

	i = 0;
	words = 0;
	while (s[i] && is_a_c(s, c))
		i++;
	while(s[i + letters] && !is_a_c(s[i + letters], c))
		letters++;
	{
		letters = 0;
		if(letters != 0)
		{
			i = i + letters;
			words++;
			continue;
		}
		i++;
	}
	return(words);
}

char **ft_split(const char *s, char c)
{
	int total_len;
	char **tab;

	total_len = ft_get_total_len;
	tab = (char **)malloc(sizeof(char*) * (total_len + 1));
	if (!tab)
		return(NULL);
	ft_fill_tab(*s, c, &tab);
	tab[len] = NULL;
	return (tab);
}
