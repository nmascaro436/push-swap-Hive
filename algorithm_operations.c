/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascaro <nmascaro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:44:38 by nmascaro          #+#    #+#             */
/*   Updated: 2025/06/25 10:11:50 by nmascaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	do_rr_or_rrr(t_stack_node **stack_a, t_stack_node *node_a,
		t_stack_node **stack_b, t_stack_node *node_b)
{
	while (*stack_a != node_a && *stack_b != node_b)
	{
		if (node_a->above_median && node_b->above_median)
			rr(stack_a, stack_b);
		else if (!node_a->above_median && !node_b->above_median)
			rrr(stack_a, stack_b);
		else
			break ;
	}
}

void	move_both_to_top(t_stack_node **stack_a, t_stack_node *target_a,
		t_stack_node **stack_b, t_stack_node *target_b)
{
	if (!stack_a || !stack_b || !target_a || !target_b)
		return ;
	do_rr_or_rrr(stack_a, target_a, stack_b, target_b);
	while (*stack_a != target_a)
	{
		if (target_a->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
	while (*stack_b != target_b)
	{
		if (target_b->above_median)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

static void	rotate_up(t_stack_node **stack, char stack_name,
		t_stack_node *target)
{
	while (*stack != target)
	{
		if (stack_name == 'a')
			ra(stack);
		else
			rb(stack);
	}
}

static void	rotate_down(t_stack_node **stack, char stack_name,
		t_stack_node *target)
{
	while (*stack != target)
	{
		if (stack_name == 'a')
			rra(stack);
		else
			rrb(stack);
	}
}

void	move_to_top(t_stack_node **stack, t_stack_node *target, char stack_name)
{
	int	position;
	int	len;

	if (!stack || !*stack || !target)
		return ;
	len = stack_len(*stack);
	position = get_position(*stack, target);
	if (position < 0)
		return ;
	if (position < len / 2)
		rotate_up(stack, stack_name, target);
	else
		rotate_down(stack, stack_name, target);
}
