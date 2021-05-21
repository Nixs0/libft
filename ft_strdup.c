/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaruk-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:22:56 by jkaruk-m          #+#    #+#             */
/*   Updated: 2021/05/21 16:23:05 by jkaruk-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*copied;

	i = 0;
	copied = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (copied == NULL)
		return (NULL);
	while (*s1)
		copied[i++] = *s1++;
	copied[i] = '\0';
	return (copied);
}
