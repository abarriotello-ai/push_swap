/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:41:21 by abarrio           #+#    #+#             */
/*   Updated: 2026/02/10 17:41:22 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

/* ************************************************************************** */
/*                                STRUCTURES                                  */
/* ************************************************************************** */

/**
 * @brief Node structure for the stack (doubly linked list)
 * @param value The integer value stored in the node
 * @param index The sorted index of this value (used for radix sort)
 * @param next Pointer to the next node
 * @param prev Pointer to the previous node
 */
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* ************************************************************************** */
/*                           PARSING & VALIDATION                             */
/* ************************************************************************** */

/**
 * @brief Parse command line arguments and create initial stack
 * @param argc Number of arguments
 * @param argv Array of argument strings
 * @return Pointer to stack A, or NULL on error
 */
t_stack	*parse_arguments(int argc, char **argv);

/**
 * @brief Validate a single number string
 * @param str String to validate
 * @return 1 if valid, 0 if invalid
 */
int		validate_number(char *str);

/**
 * @brief Check for duplicate values in stack
 * @param stack Stack to check
 * @return 1 if duplicates found, 0 otherwise
 */
int		has_duplicates(t_stack *stack);

/**
 * @brief Convert string to long and check for overflow
 * @param str String to convert
 * @param num Pointer to store result
 * @return 1 if valid, 0 if overflow/invalid
 */
int		ft_atol(char *str, long *num);

/* ************************************************************************** */
/*                            STACK OPERATIONS                                */
/* ************************************************************************** */

/* Push operations */
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

/* Swap operations */
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

/* Rotate operations */
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

/* Reverse rotate operations */
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* ************************************************************************** */
/*                            SORTING ALGORITHMS                              */
/* ************************************************************************** */

/**
 * @brief Main sorting dispatcher - chooses appropriate algorithm
 * @param stack_a Pointer to stack A
 * @param stack_b Pointer to stack B
 */
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

/**
 * @brief Sort exactly 3 elements (max 2 operations)
 * @param stack Stack to sort
 */
void	sort_three(t_stack **stack);

/**
 * @brief Sort 4-5 elements efficiently
 * @param stack_a Pointer to stack A
 * @param stack_b Pointer to stack B
 */
void	sort_small(t_stack **stack_a, t_stack **stack_b);

/**
 * @brief Radix sort algorithm for large inputs
 * @param stack_a Pointer to stack A
 * @param stack_b Pointer to stack B
 */
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

/**
 * @brief Assign sorted indices to stack values
 * @param stack Stack to index
 */
void	index_stack(t_stack *stack);

/* ************************************************************************** */
/*                             STACK UTILITIES                                */
/* ************************************************************************** */

/**
 * @brief Create new stack node
 * @param value Value for the node
 * @return Pointer to new node, or NULL on malloc failure
 */
t_stack	*stack_new(int value);

/**
 * @brief Add node to bottom of stack
 * @param stack Pointer to stack
 * @param new Node to add
 */
void	stack_add_bottom(t_stack **stack, t_stack *new);

/**
 * @brief Add node to top of stack
 * @param stack Pointer to stack
 * @param new Node to add
 */
void	stack_add_top(t_stack **stack, t_stack *new);

/**
 * @brief Get stack size
 * @param stack Stack to measure
 * @return Number of elements in stack
 */
int		stack_size(t_stack *stack);

/**
 * @brief Get last node in stack
 * @param stack Stack to check
 * @return Pointer to last node
 */
t_stack	*stack_last(t_stack *stack);

/**
 * @brief Get minimum value in stack
 * @param stack Stack to search
 * @return Minimum value
 */
int		stack_min(t_stack *stack);

/**
 * @brief Get maximum value in stack
 * @param stack Stack to search
 * @return Maximum value
 */
int		stack_max(t_stack *stack);

/**
 * @brief Check if stack is sorted in ascending order
 * @param stack Stack to check
 * @return 1 if sorted, 0 otherwise
 */
int		is_sorted(t_stack *stack);

/**
 * @brief Find position of minimum value in stack
 * @param stack Stack to search
 * @return Position (0-indexed) of minimum value
 */
int		find_min_position(t_stack *stack);

/* ************************************************************************** */
/*                          MEMORY & ERROR HANDLING                           */
/* ************************************************************************** */

/**
 * @brief Free entire stack
 * @param stack Stack to free
 */
void	free_stack(t_stack **stack);

/**
 * @brief Free array of strings
 * @param arr Array to free
 */
void	free_split(char **arr);

/**
 * @brief Print error message and exit
 * @param stack Stack to free before exit (can be NULL)
 */
void	ft_error(t_stack **stack);

/**
 * @brief Exit program and free all memory
 * @param stack_a Stack A to free
 * @param stack_b Stack B to free
 */
void	exit_program(t_stack **stack_a, t_stack **stack_b);

/* ************************************************************************** */
/*                              RADIX UTILITIES                               */
/* ************************************************************************** */

/**
 * @brief Get maximum number of bits needed for stack size
 * @param stack_size Size of the stack
 * @return Number of bits needed
 */
int		get_max_bits(int stack_size);

/**
 * @brief Get specific bit from number
 * @param num Number to extract bit from
 * @param bit Bit position (0 is rightmost)
 * @return 1 or 0
 */
int		get_bit(int num, int bit);

#endif