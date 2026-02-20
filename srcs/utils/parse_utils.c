/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:56:02 by abarrio           #+#    #+#             */
/*   Updated: 2026/02/20 19:55:51 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atol(char *str, long *num)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + (str[i++] - '0');
		if ((result * 10 + (str[i] - '0')) > LONG_MAX)
			return (0);
	}
	*num = result * sign;
	return (1);
}

int	validate_number(char *str, long *num)
{
	int			i;

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
	return (ft_atol(str, &num));
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
