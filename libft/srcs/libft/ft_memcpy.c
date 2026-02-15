/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:17:35 by abarrio           #+#    #+#             */
/*   Updated: 2025/10/24 00:58:58 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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

// int main(void)
// {
// 	char src[] = "12345";
// 	char dst[10];
// 	ft_memcpy(dst, src, 6);
// 	printf("%s\n", dst);
// 	return (0);
// }