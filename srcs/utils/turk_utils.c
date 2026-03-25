/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 19:05:50 by abarrio           #+#    #+#             */
/*   Updated: 2026/03/25 12:01:01 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	find_highest_value_pos(t_stack *stack)
{
	int		highest_value;
	int		highest_pos;
	t_stack	*tmp;

	if (!stack)
		return (0);
	highest_value = INT_MIN;
	highest_pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value > highest_value)
		{
			highest_value = tmp->value;
			highest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (highest_pos);
}

void	shift_stack(t_stack **stack_a)
{
	int	min_pos;
	int	size;

	size = stack_size(*stack_a);
	min_pos = find_min_pos(*stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(stack_a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(stack_a);
			min_pos++;
		}
	}
}
