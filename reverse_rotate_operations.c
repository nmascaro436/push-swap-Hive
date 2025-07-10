/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascaro <nmascaro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:20:39 by nmascaro          #+#    #+#             */
/*   Updated: 2025/06/25 09:33:28 by nmascaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	reverse_rotate(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	while (first->next->next)
		first = first->next;
	last = first->next;
	first->next = NULL;
	last->next = *head;
	(*head)->prev = last;
	last->prev = NULL;
	*head = last;
}

void	rra(t_stack_node **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
