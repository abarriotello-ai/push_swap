/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:23:31 by abarrio           #+#    #+#             */
/*   Updated: 2025/10/24 01:04:24 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	total_len;
	char	*tmp;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	total_len = slen - start;
	if (len > total_len)
		len = total_len;
	tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, s + start, len);
	tmp[len] = '\0';
	return (tmp);
}

// int main(void)
// {
// 	char *s = ft_substr("Hola mundo", 5, 3);
// 	printf("%s\n", s); // "mun"
// 	free(s);
// 	return (0);
// }