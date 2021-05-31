/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaruk-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:44:48 by jkaruk-m          #+#    #+#             */
/*   Updated: 2021/05/31 17:32:41 by jkaruk-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*s_str;
	size_t	i;
	size_t	j;

	i = -1;
	if (!s)
		return (NULL);
	s_str = (char *)s;
	j = ft_strlen(s_str);
	if (!len || j <= start)
		return (ft_strdup(""));
	if (j < len)
		len = j;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (s[++i] && j < len)
	{
		if (i >= start)
			str[j++] = s[i];
	}
	str[j] = 0;
	return (str);
}
