/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascaro <nmascaro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:46:08 by nmascaro          #+#    #+#             */
/*   Updated: 2025/06/12 11:33:23 by nmascaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	swap(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*head = second;
}

void	sa(t_stack_node **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
