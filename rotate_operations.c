/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascaro <nmascaro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:57:52 by nmascaro          #+#    #+#             */
/*   Updated: 2025/06/12 15:20:22 by nmascaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rotate(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	first->next = NULL;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
}

void	ra(t_stack_node **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
