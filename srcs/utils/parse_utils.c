/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:56:02 by abarrio           #+#    #+#             */
/*   Updated: 2026/03/25 13:16:51 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atol_check(char *str, long *num)
{
	int	sign;
	int	digit;

	*num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		digit = *str - '0';
		if ((sign == 1 && *num > (INT_MAX - digit) / 10)
			|| (sign == -1 && *num > (-(long)INT_MIN - digit) / 10))
			return (0);
		*num = *num * 10 + digit;
		str++;
	}
	*num *= sign;
	return (1);
}

int	validate_number(char *str, long *num)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (ft_atol_check(str, num));
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*check;

	tmp = stack;
	while (tmp)
	{
		check = tmp->next;
		while (check)
		{
			if (tmp->value == check->value)
				return (1);
			check = check->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
