/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 20:27:04 by abarrio           #+#    #+#             */
/*   Updated: 2026/03/02 12:59:41 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_top(t_stack **stack_a, int size)
{
	int	min_position;

	min_position = find_min_position(*stack_a);
	if (min_position <= size / 2)
	{
		while (min_position > 0)
		{
			ra(stack_a);
			min_position--;
		}
	}
	else
	{
		while (min_position < size)

		{
			rra(stack_a);
			min_position++;
		}
	}
}

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 4)
	{
		move_min_to_top(stack_a, size);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
	else if (size == 5)
	{
		move_min_to_top(stack_a, size);
		pb(stack_a, stack_b);
		move_min_to_top(stack_a, size - 1);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}
