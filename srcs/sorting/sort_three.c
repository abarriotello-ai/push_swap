/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 20:31:10 by abarrio           #+#    #+#             */
/*   Updated: 2026/03/01 20:26:53 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	if (!*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (c > a && a > b)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > c && c > b)
		ra(stack);
	else if (b > c && c > a)
	{
		sa(stack);
		ra(stack);
	}
	else if (b > a && a > c)
		rra(stack);
}
