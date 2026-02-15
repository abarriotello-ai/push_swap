/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:13:31 by abarrio           #+#    #+#             */
/*   Updated: 2025/10/24 01:04:07 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	while (s[i] && in_set(s[i], set))
		i++;
	while (j > i && in_set(s[j - 1], set))
		j--;
	return (ft_substr(s, (unsigned int)i, j - i));
}

// int main(void)
// {
// 	char *s = ft_strtrim("  42Madrid  ", " ");
// 	printf("%s\n", s);
// 	free(s);
// 	return (0);
// }