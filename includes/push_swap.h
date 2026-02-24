/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:41:21 by abarrio           #+#    #+#             */
/*   Updated: 2026/02/24 13:47:16 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/includes/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* Parsing */
t_stack	*parse_arguments(int argc, char **argv);
int		validate_number(char *str, long *num);
int		has_duplicates(t_stack *stack);

/* Stack Operations */
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* Sorting */
void	sort_three(t_stack **stack);
void	sort_small(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	index_stack(t_stack *stack);

/* Stack Utils - Custom implementations (safer than libft casting) */
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
int		stack_min(t_stack *stack);
int		stack_max(t_stack *stack);
int		is_sorted(t_stack *stack);
int		find_min_pos(t_stack *stack);

/* Memory & Error */
void	free_stack(t_stack **stack);
void	free_split(char **split);
void	ft_error(t_stack **stack);
void	exit_program(t_stack **stack_a, t_stack **stack_b);

/* Radix Utils */
int		get_max_bits(int stack_size);
int		get_bit(int num, int bit);

#endif
