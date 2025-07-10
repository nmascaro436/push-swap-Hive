/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascaro <nmascaro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:12:57 by nmascaro          #+#    #+#             */
/*   Updated: 2025/06/24 09:47:47 by nmascaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_three_nodes(t_stack_node **stack_a)
{
	t_stack_node	*biggest_node;

	if (!*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	biggest_node = find_max(*stack_a);
	if ((*stack_a)->value < (*stack_a)->next->value
		&& (*stack_a)->next->value < (*stack_a)->next->next->value)
		return ;
	if (biggest_node == *stack_a)
		ra(stack_a);
	else if (biggest_node == (*stack_a)->next)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}
