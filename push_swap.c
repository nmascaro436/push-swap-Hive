/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascaro <nmascaro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:52:52 by nmascaro          #+#    #+#             */
/*   Updated: 2025/06/25 10:12:46 by nmascaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	final_sort(t_stack_node **stack_a)
{
	t_stack_node	*min_node;
	int				position;
	int				len;

	min_node = find_min(*stack_a);
	len = stack_len(*stack_a);
	position = get_position(*stack_a, min_node);
	if (position < len / 2)
	{
		while (*stack_a != min_node)
			ra(stack_a);
	}
	else
	{
		while (*stack_a != min_node)
			rra(stack_a);
	}
}

void	sort_large_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	if (len > 3)
		pb(stack_a, stack_b);
	if (len > 4)
		pb(stack_a, stack_b);
	while (stack_len(*stack_a) > 3)
	{
		assign_target_nodes_a_to_b(*stack_a, *stack_b);
		push_cost(*stack_a, *stack_b);
		find_cheapest(*stack_a);
		execute_push_of_cheapest(stack_a, stack_b);
	}
	sort_three_nodes(stack_a);
	while (*stack_b)
	{
		assign_target_nodes_b_to_a(*stack_a, *stack_b);
		move_both_to_top(stack_a, (*stack_b)->target_node, stack_b, *stack_b);
		pa(stack_a, stack_b);
	}
	final_sort(stack_a);
}

void	push_swap(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	len;

	if (!stack_a || !(*stack_a))
		return ;
	if (is_sorted(*stack_a))
		return ;
	len = stack_len(*stack_a);
	if (len == 2 && (*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
	else if (len == 3)
		sort_three_nodes(stack_a);
	else if (len <= 5)
		sort_small_stack(stack_a, stack_b);
	else
		sort_large_stack(stack_a, stack_b);
}
