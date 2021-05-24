#include "libft.h"

int		is_sep(char c, char str)
{
	int i;

	i = 0;
	if (str == c)
		return (1);
	else
		return (0);
}

int get_table_len(char *str, char c)
{
	size_t words_len;
	int i;
	int letters;

	i = 0;
	words_len = 0;
	while(str[i] && is_sep(*str, c))
		i++;
	while (str[i])
	{
		letters = 0;
		while (str[i + letters] && !is_sep(str[i + letters], c))
			letters++;
		if (letters != 0)
		{
			i += letters;
			words_len++;
			continue;
		}
		i++;
	}
	return words_len;
}

char *ft_strdupp(char *str, int index, int len)
{
	int i;
	char *ret;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
		ret[i++] = str[index++];
	ret[i] = 0;
	return ret;
}

void fill_words(char ***tab, char *str, char c)
{
	int i;
	int word_len;
	int tab_index;

	i = 0;
	tab_index = 0;
	while(str[i] && is_sep(str[i], c))
		i++;
	while (str[i])
	{
		word_len = 0;
		while (str[word_len + i] && !is_sep(str[word_len + i], c))
			word_len++;
		if (word_len != 0)
		{
			(*tab)[tab_index] = ft_strdupp(str, i, word_len);
			i += word_len;
			tab_index++;
			continue;
		}
		i++;
	}
}

char **ft_split(char const *s, char c)
{
	int table_len;
	char **tab;
	char *str;

	if (!s || !c)
		return(NULL);
	str = (char *)s;
	table_len = get_table_len(str, c);
	//printf("%d\n", table_len);
	if (!(tab = (char **)malloc(sizeof(char *) * (table_len + 1))))
		return (NULL);
	fill_words(&tab, str, c);
	tab[table_len] = NULL;
	return tab;
}

/*int main(int ac, char **av)
{
	(void)ac;
	char **tab = ft_split(av[1], av[2][0]);
	int index = 0;
	while (tab[index])
	{
		printf("mot numero %d : |%s|\n", index, tab[index]);
		free(tab[index]);
		index++;
	}
	//free(tab);
	return 0;
}*/
