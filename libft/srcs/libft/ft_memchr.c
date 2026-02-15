/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:54 by abarrio           #+#    #+#             */
/*   Updated: 2025/10/24 00:58:25 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (n--)
	{
		if (*tmp == (unsigned char)c)
			return ((void *)tmp);
		tmp++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char s[] = "hola mundo";
// 	printf("%s\n", (char *)ft_memchr(s, 'm', 10));
// 	return (0);
// }