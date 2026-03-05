/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:28:28 by abarrio           #+#    #+#             */
/*   Updated: 2026/03/05 13:25:52 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int stack_size)
{
	int	max_bits;
	int	max_num;

	max_bits = 0;
	max_num = stack_size - 1;
	while (max_num > 0)
	{
		max_num >>= 1;
		max_bits++;
	}
	return (max_bits);
}

static int	get_bit(int index, int bit)
{
	return ((index >> bit) & 1);
}

static void	sort_by_bit(t_stack **stack_a, t_stack **stack_b, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (get_bit((*stack_a)->index, bit) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bits;
	int	size;
	int	bit;

	if (!*stack_a)
		return ;
	size = stack_size(*stack_a);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		sort_by_bit(stack_a, stack_b, bit, size);
		while (*stack_b)
			pa(stack_a, stack_b);
		bit++;
	}
}
