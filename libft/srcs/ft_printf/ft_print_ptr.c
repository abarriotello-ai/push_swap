/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:08:59 by abarrio           #+#    #+#             */
/*   Updated: 2026/02/14 14:38:36 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_ptr(void *ptr)
{
	unsigned long	address;
	int				count;

	if (!ptr)
		return (ft_putstr_count("(nil)"));
	address = (unsigned long)ptr;
	count = 0;
	count += ft_putstr_count("0x");
	count += ft_putnbr_base_count(address, "0123456789abcdef");
	return (count);
}
