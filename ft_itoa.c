/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaruk-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:16:39 by jkaruk-m          #+#    #+#             */
/*   Updated: 2021/05/31 17:36:33 by jkaruk-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * (-1);
		len++;
	}
	if (n == 0)
		len++;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_handle_nbr(long nbr, char *res, long len)
{
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = nbr * (-1);
	}
	while (nbr > 0)
	{
		res[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	long	nbr;
	long	len;
	char	*res;

	nbr = n;
	len = ft_len(nbr);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (nbr == 0)
		res[0] = '0';
	ft_handle_nbr(nbr, res, len);
	return (res);
}
