/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:03:29 by abarrio           #+#    #+#             */
/*   Updated: 2025/10/24 01:03:04 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	tmp = (char *)malloc(s1len + s2len + 1);
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, s1, s1len);
	ft_memcpy(tmp + s1len, s2, s2len);
	tmp[s1len + s2len] = '\0';
	return (tmp);
}

// int main(void)
// {
// 	char *s = ft_strjoin("libft", "42");
// 	printf("%s\n", s);
// 	free(s);
// 	return (0);
// }