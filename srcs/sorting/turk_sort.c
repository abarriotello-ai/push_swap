/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 11:46:02 by abarrio           #+#    #+#             */
/*   Updated: 2026/03/14 11:50:45 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_all_but_three(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;

	size = stack_size(*stack_a);
	pushed = 0;
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_but_three(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		assign_positions(*stack_a);
		assign_positions(*stack_b);
		assign_target_positions(*stack_a, *stack_b);
		calculate_costs(*stack_a, *stack_b);
		execute_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
