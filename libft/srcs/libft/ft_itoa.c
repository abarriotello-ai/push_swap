/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:47:46 by abarrio           #+#    #+#             */
/*   Updated: 2025/10/24 00:57:43 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	char	*s;

	nb = (long)n;
	len = ft_numlen(nb);
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (nb < 0)
	{
		nb = -nb;
		s[0] = '-';
	}
	if (nb == 0)
		s[--len] = '0';
	while (nb)
	{
		s[--len] = (char)((nb % 10) + '0');
		nb /= 10;
	}
	return (s);
}

// int main(void)
// {
// 	char *s = ft_itoa(-12345);
// 	printf("%s\n", s);
// 	free(s);
// 	return (0);
// }