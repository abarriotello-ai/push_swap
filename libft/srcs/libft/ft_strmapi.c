/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:45:48 by abarrio           #+#    #+#             */
/*   Updated: 2025/10/24 01:03:32 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*out;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}

// static char add_i(unsigned int i, char c)
// {
// 	return (c + i);
// }

// int main(void)
// {
// 	char *s = ft_strmapi("abcd", add_i);
// 	printf("%s\n", s); // "aceg"
// 	free(s);
// 	return (0);
// }