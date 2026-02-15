/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:56:10 by abarrio           #+#    #+#             */
/*   Updated: 2026/02/14 14:38:57 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (!dst && !src)
		return (NULL);
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	while (n--)
		*tmp_dst++ = *tmp_src++;
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*tmp;

	if (!s1 && !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	tmp = (char *)malloc(s1len + s2len + 1);
	if (!tmp)
		return (NULL);
	if (s1)
		ft_memcpy(tmp, s1, s1len);
	if (s2)
		ft_memcpy(tmp + s1len, s2, s2len);
	tmp[s1len + s2len] = '\0';
	if (s1)
		free(s1);
	return (tmp);
}
