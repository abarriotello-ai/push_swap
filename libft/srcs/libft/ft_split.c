/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:48:40 by abarrio           #+#    #+#             */
/*   Updated: 2025/10/24 01:02:08 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	n;
	int		in_word;

	n = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			n++;
		}
		if (*s == c)
			in_word = 0;
		s++;
	}
	return (n);
}

static void	ft_free_tab(char **tab, size_t k)
{
	while (k--)
		free (tab[k]);
	free (tab);
}

static int	ft_fill_split(char const *s, char c, char **tab)
{
	size_t	len;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		len = 0;
		while (s[i + len] && s[i + len] != c)
			len++;
		tab[k] = ft_substr(s, (unsigned int)i, len);
		if (!tab[k])
			return (ft_free_tab(tab, k), 0);
		i += len;
		k++;
	}
	tab[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**tab;
	size_t		words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	tab = (char **)malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!ft_fill_split(s, c, tab))
		return (NULL);
	return (tab);
}

// int main(void)
// {
// 	char **tab = ft_split("Hola mundo 42 Madrid", ' ');
// 	for (int i = 0; tab[i]; i++)
// 	{
// 		printf("%s\n", tab[i]);
// 		free(tab[i]);
// 	}
// 	free(tab);
// 	return (0);
// }