/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:41:11 by abarrio           #+#    #+#             */
/*   Updated: 2026/03/05 18:05:47 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_top(t_stack **s, int pos,
				void (*rot)(t_stack **), void (*rrot)(t_stack **))
{
	int	size;

	size = stack_size(*s);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rot(s);
	}
	else
	{
		while (pos++ < size)
			rrot(s);
	}
}

static int	find_best_pos_in_range(t_stack *a, int low, int high)
{
	int	pos;
	int	best_pos;
	int	size;
	int	best_cost;

	pos = 0;
	best_pos = -1;
	size = stack_size(a);
	best_cost = size + 1;
	while (a)
	{
		if (a->index >= low && a->index <= high)
		{
			if (pos <= size / 2 && pos < best_cost)
			{
				best_cost = pos;
				best_pos = pos;
			}
			else if (pos > size / 2 && (size - pos) < best_cost)
			{
				best_cost = size - pos;
				best_pos = pos;
			}
		}
		pos++;
		a = a->next;
	}
	return (best_pos);
}

static void	push_chunks(t_stack **a, t_stack **b, int chunk)
{
	int	low;
	int	high;
	int	pos;

	low = 0;
	high = chunk - 1;
	while (*a)
	{
		pos = find_best_pos_in_range(*a, low, high);
		if (pos == -1)
		{
			high += chunk;
			continue ;
		}
		rotate_to_top(a, pos, ra, rra);
		pb(a, b);
		if ((*b)->index < low + (chunk / 2))
			rb(b);
		low++;
		high++;
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		pos;
	int		best_pos;
	int		max;

	while (*b)
	{
		tmp = *b;
		max = tmp->index;
		pos = 0;
		best_pos = 0;
		while (tmp)
		{
			if (tmp->index > max)
			{
				max = tmp->index;
				best_pos = pos;
			}
			pos++;
			tmp = tmp->next;
		}
		rotate_to_top(b, best_pos, rb, rrb);
		pa(a, b);
	}
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	chunk;

	if (!stack_a || !*stack_a || is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	chunk = size / 10 + 5;
	push_chunks(stack_a, stack_b, chunk);
	push_back_to_a(stack_a, stack_b);
}
