/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:32:56 by abarrio           #+#    #+#             */
/*   Updated: 2026/03/05 14:38:59 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_small(stack_a, stack_b);
	else
	{
		index_stack(*stack_a);
		radix_sort(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
		ft_error(NULL);
	if (has_duplicates(stack_a))
		ft_error(&stack_a);
	stack_b = NULL;
	sort_stack(&stack_a, &stack_b);
	exit_program(&stack_a, &stack_b);
	return (0);
}
