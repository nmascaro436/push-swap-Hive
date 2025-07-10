/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cleaning.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascaro <nmascaro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:48:44 by nmascaro          #+#    #+#             */
/*   Updated: 2025/06/25 09:52:33 by nmascaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*temp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

bool	is_sorted(t_stack_node *stack_a)
{
	if (!stack_a)
		return (true);
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}
