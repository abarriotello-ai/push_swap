/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 11:54:23 by abarrio           #+#    #+#             */
/*   Updated: 2026/03/25 15:11:55 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_positions(t_stack *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos;
		stack = stack->next;
		pos++;
	}
}

static int	find_target_position(t_stack *stack, int value)
{
	int		target_pos;
	int		best_match;
	t_stack	*tmp;

	target_pos = 0;
	best_match = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value > value && tmp->value < best_match)
		{
			best_match = tmp->value;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (best_match == INT_MAX)
		target_pos = find_min_pos(stack);
	return (target_pos);
}

void	assign_target_positions(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = stack_b;
	while (tmp_b)
	{
		target_pos = find_target_position(stack_a, tmp_b->value);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
