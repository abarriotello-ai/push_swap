/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:14:14 by abarrio           #+#    #+#             */
/*   Updated: 2025/10/24 00:56:27 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n--)
		*temp++ = 0;
}

// int main(void)
// {
// 	char s[10] = "abcdef";
// 	ft_bzero(s + 2, 3);
// 	printf("%s\n", s); // imprime "ab"
// 	return (0);
// }