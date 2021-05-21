/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaruk-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:23:17 by jkaruk-m          #+#    #+#             */
/*   Updated: 2021/05/21 16:23:52 by jkaruk-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (size < len_dest)
		len_src = len_src + size;
	else
		len_src = len_src + len_dest;
	while (src[i] && (len_dest + i) < size - 1)
	{
		dest[i + len_dest] = src[i];
		i++;
	}
	dest[i + len_dest] = '\0';
	return (len_src);
}
