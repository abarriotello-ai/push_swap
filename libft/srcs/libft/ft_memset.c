/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:00:39 by abarrio           #+#    #+#             */
/*   Updated: 2025/10/24 00:59:39 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n--)
		*temp++ = (unsigned char) c;
	return (s);
}

// int main(void)
// {
// 	char s[10] = "hola";
// 	ft_memset(s, 'x', 3);
// 	printf("%s\n", s);
// 	return (0);
// }