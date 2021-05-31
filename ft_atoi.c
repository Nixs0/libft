/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaruk-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:48:51 by jkaruk-m          #+#    #+#             */
/*   Updated: 2021/05/31 01:03:25 by nixs0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_ws(char **str)
{
	while ((**str >= 9 && **str <= 13) || **str == ' ')
		(*str)++;
}

void	ft_handle_sign(char **str, int *sign)
{
	if (**str == '+')
		(*str)++;
	else if (**str == '-')
	{
		*sign = -*sign;
		(*str)++;
	}
}

int	ft_atoi(char *str)
{
	long long	res;
	int	sign;
	int 		compteur;

	res = 0;
	sign = 1;
	compteur = 0;
	
	check_ws(&str);
	ft_handle_sign(&str, &sign);
	while (*str >= '0' && *str <= '9')
	{
		++compteur;
		if (compteur > 17 || res > 9223372036854775807)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		res = res * 10 + *str - '0';
		str++;
	}
	return (sign * res);
}
