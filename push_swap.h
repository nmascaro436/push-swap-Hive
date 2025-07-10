/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascaro <nmascaro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 09:55:34 by nmascaro          #+#    #+#             */
/*   Updated: 2025/06/25 10:10:28 by nmascaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// Input validation and stack initialization
bool					stack_initializing(int argc, int *numbers,
							t_stack_node **stack_a);
bool					input_validation(int argc, char *argv[], int *numbers);
int						get_position(t_stack_node *stack, t_stack_node *target);

// Stack operations
void					sa(t_stack_node **stack_a);
void					sb(t_stack_node **stack_b);
void					ss(t_stack_node **stack_a, t_stack_node **stack_b);
void					pa(t_stack_node **stack_a, t_stack_node **stack_b);
void					pb(t_stack_node **stack_a, t_stack_node **stack_b);
void					ra(t_stack_node **stack_a);
void					rb(t_stack_node **stack_b);
void					rr(t_stack_node **stack_a, t_stack_node **stack_b);
void					rra(t_stack_node **stack_a);
void					rrb(t_stack_node **stack_b);
void					rrr(t_stack_node **stack_a, t_stack_node **stack_b);

// Stack utility functions
t_stack_node			*find_min(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);
int						stack_len(t_stack_node *stack);

// Sorting algorithms
void					sort_three_nodes(t_stack_node **stack_a);
void					sort_small_stack(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					sort_large_stack(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					push_swap(t_stack_node **stack_a,
							t_stack_node **stack_b);

// Stack analysis functions
void					assign_target_nodes_a_to_b(t_stack_node *stack_a,
							t_stack_node *stack_b);
void					assign_target_nodes_b_to_a(t_stack_node *stack_a,
							t_stack_node *stack_b);
void					push_cost(t_stack_node *stack_a, t_stack_node *stack_b);
void					find_cheapest(t_stack_node *stack_a);

// Movement and execution functions
void					move_to_top(t_stack_node **stack, t_stack_node *target,
							char stack_name);
void					move_both_to_top(t_stack_node **stack_a,
							t_stack_node *target_a, t_stack_node **stack_b,
							t_stack_node *target_b);
void					execute_push_of_cheapest(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					push_to_b(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					push_to_a(t_stack_node **stack_a,
							t_stack_node **stack_b);

// Final sorting and cleanup
void					final_sort(t_stack_node **stack_a);
void					free_stack(t_stack_node **stack);
bool					is_sorted(t_stack_node *stack_a);

#endif
