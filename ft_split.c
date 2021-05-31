/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaruk-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:43:36 by jkaruk-m          #+#    #+#             */
/*   Updated: 2021/05/31 14:44:00 by jkaruk-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sep(char c, char str)
{
	if (str == c)
		return (1);
	else
		return (0);
}

int	get_table_len(char *str, char c)
{
	size_t	words_len;
	int		i;
	int		letters;

	i = 0;
	words_len = 0;
	while (str[i] && is_sep(str[i], c))
		i++;
	while (str[i])
	{
		letters = 0;
		while (str[i + letters] && !is_sep(str[i + letters], c))
			letters++;
		if (letters != 0)
		{
			i += letters;
			words_len++;
			continue ;
		}
		i++;
	}
	return (words_len);
}

char	*ft_strdupp(char *str, int index, int len)
{
	int		i;
	char	*copied;

	i = 0;
	copied = (char *)malloc(sizeof(char) * (len + 1));
	if (!copied)
		return (NULL);
	while (i < len)
		copied[i++] = str[index++];
	copied[i] = 0;
	return (copied);
}

void	fill_words(char ***tab, char *str, char c)
{
	int	i;
	int	word_len;
	int	tab_index;

	i = 0;
	tab_index = 0;
	while (str[i] && is_sep(str[i], c))
		i++;
	while (str[i])
	{
		word_len = 0;
		while (str[word_len + i] && !is_sep(str[word_len + i], c))
			word_len++;
		if (word_len != 0)
		{
			(*tab)[tab_index] = ft_strdupp(str, i, word_len);
			i += word_len;
			tab_index++;
			continue ;
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		table_len;
	char	**tab;
	char	*str;

	if (!s || !c)
		return (NULL);
	str = (char *)s;
	table_len = get_table_len(str, c);
	tab = (char **)malloc(sizeof(char *) * (table_len + 1));
	if (!tab)
		return (NULL);
	fill_words(&tab, str, c);
	tab[table_len] = NULL;
	return (tab);
}
