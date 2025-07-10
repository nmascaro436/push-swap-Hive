/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascaro <nmascaro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:16:50 by nmascaro          #+#    #+#             */
/*   Updated: 2025/06/25 11:44:17 by nmascaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static t_stack_node	*find_target_in_b(t_stack_node *stack_b, int value)
{
	t_stack_node	*current;
	t_stack_node	*target;
	long			best_match;

	best_match = LONG_MIN;
	target = NULL;
	current = stack_b;
	while (current)
	{
		if (current->value < value && current->value > best_match)
		{
			best_match = current->value;
			target = current;
		}
		current = current->next;
	}
	if (!target && stack_b)
		target = find_max(stack_b);
	return (target);
}

void	assign_target_nodes_a_to_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*current;

	if (!stack_a)
		return ;
	current = stack_a;
	while (current)
	{
		current->target_node = find_target_in_b(stack_b, current->value);
		current = current->next;
	}
}

static t_stack_node	*find_target_in_a(t_stack_node *stack_a, int value)
{
	t_stack_node	*current;
	t_stack_node	*target;
	long			best_match;

	best_match = LONG_MAX;
	target = NULL;
	current = stack_a;
	while (current)
	{
		if (current->value > value && current->value < best_match)
		{
			best_match = current->value;
			target = current;
		}
		current = current->next;
	}
	if (!target)
		target = find_min(stack_a);
	return (target);
}

void	assign_target_nodes_b_to_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*current;

	if (!stack_b || !stack_a)
		return ;
	current = stack_b;
	while (current)
	{
		current->target_node = find_target_in_a(stack_a, current->value);
		current = current->next;
	}
}

void	find_cheapest(t_stack_node *stack_a)
{
	t_stack_node	*cheapest_node;
	long			cheapest_value;
	t_stack_node	*current;

	if (!stack_a)
		return ;
	cheapest_node = NULL;
	cheapest_value = LONG_MAX;
	current = stack_a;
	while (current)
	{
		current->cheapest = false;
		if (current->push_cost < cheapest_value)
		{
			cheapest_value = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}
