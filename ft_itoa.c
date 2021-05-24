#include "libft.h"

int	ft_len(int n)
{
	int len;
	
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
		n = n/10;
		len++;
	}
	return(len);
}

char	*ft_itoa(int n)
{
	int nbr;
	int len;
	char *res;
	
	nbr = n;
	len = ft_len(nbr);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if(!res)
		return(NULL);
	res[len--] = '\0';
if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr == 0)
		res[0] = '0';
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
	return(res);
}
