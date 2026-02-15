/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:09:28 by abarrio           #+#    #+#             */
/*   Updated: 2025/10/24 00:59:42 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (!dst && !src)
		return (NULL);
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	if (tmp_dst < tmp_src)
	{
		while (n--)
			*tmp_dst++ = *tmp_src++;
	}
	else
	{
		while (n--)
			tmp_dst[n] = tmp_src[n];
	}
	return (dst);
}

// int main(void)
// {
// 	char s[] = "abcdef";
// 	ft_memmove(s + 2, s, 4);
// 	printf("%s\n", s); // imprime "ababcd"
// 	return (0);
// }