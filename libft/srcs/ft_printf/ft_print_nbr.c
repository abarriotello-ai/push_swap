/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:50:37 by abarrio           #+#    #+#             */
/*   Updated: 2026/02/14 14:38:34 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_count(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar_count('-');
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr_count(n / 10);
	count += ft_putchar_count((char)('0' + (n % 10)));
	return (count);
}

int	ft_print_nbr(int n)
{
	return (ft_putnbr_count((long)n));
}
