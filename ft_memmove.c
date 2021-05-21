/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaruk-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:18:53 by jkaruk-m          #+#    #+#             */
/*   Updated: 2021/05/21 16:19:00 by jkaruk-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_cpy;
	unsigned char	*dst_cpy;
	size_t			i;

	src_cpy = (unsigned char *)src;
	dst_cpy = (unsigned char *)dst;
	i = 0;
	if (src == dst)
		return (dst);
	if (dst_cpy < src_cpy)
	{
		while (i < len)
		{
			dst_cpy[i] = src_cpy[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			len--;
			dst_cpy[len] = src_cpy[len];
		}
	}
	return (dst);
}
