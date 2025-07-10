/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascaro <nmascaro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:58:23 by nmascaro          #+#    #+#             */
/*   Updated: 2025/06/25 12:18:06 by nmascaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_max_cost(int cost_a, int cost_b)
{
	if (cost_a > cost_b)
		return (cost_a);
	return (cost_b);
}

static int	calculate_combined_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = cost_a;
	abs_b = cost_b;
	if (abs_a < 0)
		abs_a = -abs_a;
	if (abs_b < 0)
		abs_b = -abs_b;
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
		return (get_max_cost(abs_a, abs_b));
	else
		return (abs_a + abs_b);
}

static int	get_cost_a(t_stack_node *node, int position, int len_a)
{
	int	cost_a;

	if (position < len_a / 2)
	{
		cost_a = position;
		node->above_median = true;
	}
	else
	{
		cost_a = len_a - position;
		node->above_median = false;
	}
	if (!node->above_median)
		cost_a = -cost_a;
	return (cost_a);
}

static int	get_cost_b(t_stack_node *node, t_stack_node *stack_b, int len_b)
{
	int	pos_b;
	int	cost_b;

	cost_b = 0;
	if (!node->target_node || !stack_b || len_b <= 0)
		return (cost_b);
	pos_b = get_position(stack_b, node->target_node);
	if (pos_b < len_b / 2)
	{
		cost_b = pos_b;
		node->target_node->above_median = true;
	}
	else
	{
		cost_b = len_b - pos_b;
		node->target_node->above_median = false;
	}
	if (!node->target_node->above_median)
		cost_b = -cost_b;
	return (cost_b);
}

void	push_cost(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int				len_a;
	int				len_b;
	int				position;
	t_stack_node	*current_a;
	int				temp_cost;

	if (!stack_a)
		return ;
	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	current_a = stack_a;
	position = 0;
	while (current_a)
	{
		temp_cost = get_cost_a(current_a, position, len_a);
		current_a->push_cost = calculate_combined_cost(temp_cost,
				get_cost_b(current_a, stack_b, len_b));
		current_a = current_a->next;
		position++;
	}
}
