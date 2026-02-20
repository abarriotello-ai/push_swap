/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:03:52 by abarrio           #+#    #+#             */
/*   Updated: 2026/02/20 14:06:02 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static t_stack	*parse_split_args(char **split)
{
	t_stack	*stack;
	t_stack	*new;
	long	num;
	int		i;

	stack = NULL;
	i = 0;
	while (split[i])
	{
		if (!validate_number(split[i], &num))
			return (free_split(split), free_stack(&stack), NULL);
		new = stack_new((int)num);
		if (!new)
			return (free_split(split), free_stack(&stack), NULL);
		ft_lstadd_back((t_list **)&stack, (t_list *)new);
		i++;
	}
	free_split(split);
	return (stack);
}

static t_stack	*create_node_and_add(t_stack **stack, char *str)
{
	t_stack	*new;
	long	num;

	if (!validate_number(str, &num))
		return (free_stack(stack), NULL);
	new = stack_new((int)num);
	if (!new)
		return (free_stack(stack), NULL);
	ft_lstadd_back((t_list **)stack, (t_list *)new);
	return (*stack);
}

t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack;
	char	**split;
	int		i;

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split || !split[0])
		{
			if (split)
				free_split(split);
			return (NULL);
		}
		return (parse_split_args(split));
	}
	stack = NULL;
	i = 0;
	while (++i < argc)
	{
		if (!create_node_and_add(&stack, argv[i]))
			return (NULL);
	}
	return (stack);
}
