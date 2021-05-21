/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaruk-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:24:14 by jkaruk-m          #+#    #+#             */
/*   Updated: 2021/05/21 16:24:16 by jkaruk-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src || !dest)
		return (0);
	while (src[i] && ((i + 1) < size))
	{
		dest[i] = src[i];
		i++;
	}
	if (size >= 1)
		dest[i] = '\0';
	return (ft_strlen(src));
}
