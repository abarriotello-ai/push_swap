/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 19:04:49 by abarrio           #+#    #+#             */
/*   Updated: 2026/03/25 12:04:00 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_costs(t_stack *stack_a, t_stack *stack_b)
{
	int		size_a;
	int		size_b;
	t_stack	*tmp_b;

	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	tmp_b = stack_b;
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

static t_stack	*find_cheapest(t_stack *stack_b)
{
	t_stack	*tmp;
	t_stack	*cheapest;
	int		min_cost;
	int		total_cost;

	tmp = stack_b;
	cheapest = tmp;
	min_cost = INT_MAX;
	while (tmp)
	{
		total_cost = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	return (cheapest);
}

static void	do_double_rotations(t_stack **stack_a, t_stack **stack_b,
				t_stack *cheapest)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		rr(stack_a, stack_b);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		rrr(stack_a, stack_b);
		cheapest->cost_a++;
		cheapest->cost_b++;
	}
}

static void	do_individual_rotations(t_stack **stack_a, t_stack **stack_b,
				t_stack *cheapest)
{
	while (cheapest->cost_a > 0 && cheapest->cost_a--)
		ra(stack_a);
	while (cheapest->cost_a < 0 && cheapest->cost_a++)
		rra(stack_a);
	while (cheapest->cost_b > 0 && cheapest->cost_b--)
		rb(stack_b);
	while (cheapest->cost_b < 0 && cheapest->cost_b++)
		rrb(stack_b);
}

void	execute_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*stack_b);
	do_double_rotations(stack_a, stack_b, cheapest);
	do_individual_rotations(stack_a, stack_b, cheapest);
	pa(stack_a, stack_b);
}
