/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 20:06:25 by abarrio           #+#    #+#             */
/*   Updated: 2026/03/25 12:02:30 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/includes/libft.h"

/*
** Stack node structure
** value:      The actual integer value
** pos:        Current position in stack (0 = top)
** target_pos: Target position in the other stack
** cost_a:     Rotations needed in stack A (positive = ra, negative = rra)
** cost_b:     Rotations needed in stack B (positive = rb, negative = rrb)
** next:       Pointer to next node
*/
typedef struct s_stack
{
	int				value;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* ========================================================================== */
/*                           ARGUMENT PARSING                                 */
/* ========================================================================== */

/* Parse command line arguments into stack A */
t_stack	*parse_arguments(int argc, char **argv);

/* Check if string is a valid integer within INT_MIN to INT_MAX */
int		validate_number(char *str, long *num);

/* Check if stack contains duplicate values */
int		has_duplicates(t_stack *stack);

/* ========================================================================== */
/*                          STACK OPERATIONS                                  */
/* ========================================================================== */

/* Push top of B to top of A */
void	pa(t_stack **stack_a, t_stack **stack_b);

/* Push top of A to top of B */
void	pb(t_stack **stack_a, t_stack **stack_b);

/* Swap first two elements of stack A */
void	sa(t_stack **stack_a);

/* Swap first two elements of stack B */
void	sb(t_stack **stack_b);

/* Swap first two elements of both stacks */
void	ss(t_stack **stack_a, t_stack **stack_b);

/* Rotate stack A up (first becomes last) */
void	ra(t_stack **stack_a);

/* Rotate stack B up (first becomes last) */
void	rb(t_stack **stack_b);

/* Rotate both stacks up */
void	rr(t_stack **stack_a, t_stack **stack_b);

/* Reverse rotate stack A down (last becomes first) */
void	rra(t_stack **stack_a);

/* Reverse rotate stack B down (last becomes first) */
void	rrb(t_stack **stack_b);

/* Reverse rotate both stacks down */
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* ========================================================================== */
/*                          SORTING ALGORITHMS                                */
/* ========================================================================== */

/* Sort 3 elements using hardcoded optimal solution (max 2 ops) */
void	sort_three(t_stack **stack);

/* Sort 4-5 elements by moving minimums to B (max 12 ops) */
void	sort_small(t_stack **stack_a, t_stack **stack_b);

/* Sort 6+ elements using cost-based Turk algorithm */
void	turk_sort(t_stack **stack_a, t_stack **stack_b);

/* ========================================================================== */
/*                      TURK ALGORITHM HELPERS                                */
/* ========================================================================== */

/* Assign current position (0 to n-1) to each node in stack */
void	assign_positions(t_stack *stack);

/* Calculate where each element in B should go in A */
void	assign_target_positions(t_stack *stack_a, t_stack *stack_b);

/* Calculate rotation costs (cost_a, cost_b) for each element in B */
void	calculate_costs(t_stack *stack_a, t_stack *stack_b);

/* Find element with lowest total cost and execute the move */
void	execute_cheapest_move(t_stack **stack_a, t_stack **stack_b);

/* Rotate stack A until smallest element is on top */
void	shift_stack(t_stack **stack_a);

/* Return absolute value of an integer */
int		ft_abs(int n);

/* ========================================================================== */
/*                           STACK UTILITIES                                  */
/* ========================================================================== */

/* Create new stack node with given value */
t_stack	*stack_new(int value);

/* Add node to the end of stack */
void	stack_add_back(t_stack **stack, t_stack *new);

/* Count number of elements in stack */
int		stack_size(t_stack *stack);

/* Get last node of stack */
t_stack	*stack_last(t_stack *stack);

/* Find minimum value in stack */
int		stack_min(t_stack *stack);

/* Check if stack is sorted in ascending order */
int		is_sorted(t_stack *stack);

/* Find position of minimum value in stack */
int		find_min_pos(t_stack *stack);

/* Find position of maximum value in stack */
int		find_highest_value_pos(t_stack *stack);

/* ========================================================================== */
/*                        MEMORY & ERROR HANDLING                             */
/* ========================================================================== */

/* Free all nodes in stack */
void	free_stack(t_stack **stack);

/* Free array of strings (from ft_split) */
void	free_split(char **split);

/* Print "Error" to stderr, free stack, and exit */
void	ft_error(t_stack **stack);

/* Free both stacks and exit normally */
void	exit_program(t_stack **stack_a, t_stack **stack_b);

#endif