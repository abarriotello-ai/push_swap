/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:02:37 by abarrio           #+#    #+#             */
/*   Updated: 2026/02/14 14:38:41 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putunbr_count(unsigned long n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putunbr_count(n / 10);
	count += ft_putchar_count((char)('0' + (n % 10)));
	return (count);
}

int	ft_print_unbr(unsigned int n)
{
	return (ft_putunbr_count((unsigned long)n));
}
