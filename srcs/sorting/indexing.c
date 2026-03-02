/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:03:03 by abarrio           #+#    #+#             */
/*   Updated: 2026/03/02 20:16:13 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack *stack, int size)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
	return (arr);
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	find_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	index_stack(t_stack *stack)
{
	int		*sorted_array;
	int		size;
	t_stack	*tmp;

	if (!stack)
		return ;
	size = stack_size(stack);
	sorted_array = stack_to_array(stack, size);
	if (!sorted_array)
		return ;
	sort_array(sorted_array, size);
	tmp = stack;
	while (tmp)
	{
		tmp->index = find_index(sorted_array, size, tmp->value);
		tmp = tmp->next;
	}
	free(sorted_array);
}
