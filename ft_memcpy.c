/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaruk-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:18:33 by jkaruk-m          #+#    #+#             */
/*   Updated: 2021/05/21 17:49:02 by jkaruk-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*src_cpy;
	unsigned char		*dst_cpy;
	size_t		i;

	i = 0;
	src_cpy = (unsigned char*)src;
	dst_cpy = (unsigned char*)dst;
	if (src == dst || !n)
		return (dst);
	while (i < n)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	return (dst);
}
