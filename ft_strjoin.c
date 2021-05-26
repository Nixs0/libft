#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	char *joined;
	int len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (len + 1));
	if (!joined)
		return (NULL);
	str = joined;
	while (*s1)
		*joined++ = *s1++;
	while (*s2)
		*joined++ = *s2++;
	*joined = 0;
	return(str);
}
