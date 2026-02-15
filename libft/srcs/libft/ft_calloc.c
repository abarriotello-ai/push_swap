/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:25:04 by abarrio           #+#    #+#             */
/*   Updated: 2025/11/17 11:53:19 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nmemb != 0 && size != 0 && nmemb > ((size_t) - 1) / size)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

// int main(void)
// {
// 	int *p = ft_calloc(5, sizeof(int));
// 	for (int i = 0; i < 5; i++)
// 		printf("%d ", p[i]);
// 	free(p);
// 	return (0);
// }