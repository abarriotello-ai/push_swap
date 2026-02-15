/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:41:50 by abarrio           #+#    #+#             */
/*   Updated: 2026/02/14 14:38:43 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dispatch(char specific, va_list arg)
{
	if (specific == 'c')
		return (ft_print_char(va_arg(arg, int)));
	else if (specific == 's')
		return (ft_print_str(va_arg(arg, char *)));
	else if (specific == 'p')
		return (ft_print_ptr(va_arg(arg, void *)));
	else if (specific == 'd' || specific == 'i')
		return (ft_print_nbr(va_arg(arg, int)));
	else if (specific == 'u')
		return (ft_print_unbr(va_arg(arg, unsigned int)));
	else if (specific == 'x')
		return (ft_print_hex(va_arg(arg, unsigned int), 0));
	else if (specific == 'X')
		return (ft_print_hex(va_arg(arg, unsigned int), 1));
	else if (specific == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(arg, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_dispatch(format[i], arg);
		}
		else
			count += ft_putchar_count(format[i]);
		if (format[i] != '\0')
			i++;
	}
	va_end(arg);
	return (count);
}
