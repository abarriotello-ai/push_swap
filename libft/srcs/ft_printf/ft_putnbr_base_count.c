/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:20:28 by abarrio           #+#    #+#             */
/*   Updated: 2026/02/14 14:38:48 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_count(unsigned long n, char *base)
{
	unsigned long	base_len;
	int				count;

	base_len = (unsigned long)ft_strlen(base);
	count = 0;
	if (n >= base_len)
		count += ft_putnbr_base_count(n / base_len, base);
	count += ft_putchar_count(base[n % base_len]);
	return (count);
}
