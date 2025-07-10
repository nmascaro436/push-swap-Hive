/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascaro <nmascaro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:35:53 by nmascaro          #+#    #+#             */
/*   Updated: 2025/06/25 09:32:38 by nmascaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_to_push;

	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->next = *dest;
	if (*dest)
		(*dest)->prev = node_to_push;
	node_to_push->prev = NULL;
	*dest = node_to_push;
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
