/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:26:14 by abarrio           #+#    #+#             */
/*   Updated: 2026/03/05 13:53:41 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_min_position(t_stack *stack)
{
	int	min;
	int	position;
	int	min_position;

	if (!stack)
		return (0);
	min = stack_min(stack);
	position = 0;
	min_position = 0;
	while (stack)
	{
		if (stack->value == min)
		{
			min_position = position;
			break ;
		}
		position++;
		stack = stack->next;
	}
	return (min_position);
}
