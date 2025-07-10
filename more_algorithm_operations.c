/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_algorithm_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascaro <nmascaro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:28:59 by nmascaro          #+#    #+#             */
/*   Updated: 2025/06/25 11:32:32 by nmascaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	while (*stack_b)
	{
		assign_target_nodes_b_to_a(*stack_a, *stack_b);
		move_both_to_top(stack_a, (*stack_b)->target_node, stack_b, *stack_b);
		pa(stack_a, stack_b);
	}
}

void	push_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!stack_a || !*stack_a || !stack_b)
		return ;
	while (stack_len(*stack_a) > 3)
	{
		assign_target_nodes_a_to_b(*stack_a, *stack_b);
		push_cost(*stack_a, *stack_b);
		find_cheapest(*stack_a);
		execute_push_of_cheapest(stack_a, stack_b);
	}
}

void	execute_push_of_cheapest(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	cheapest = *stack_a;
	while (cheapest && !cheapest->cheapest)
		cheapest = cheapest->next;
	if (!cheapest)
		return ;
	if (cheapest->target_node)
		move_both_to_top(stack_a, cheapest, stack_b, cheapest->target_node);
	else
		move_to_top(stack_a, cheapest, 'a');
	pb(stack_a, stack_b);
}
