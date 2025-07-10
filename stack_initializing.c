/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initializing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascaro <nmascaro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:25:35 by nmascaro          #+#    #+#             */
/*   Updated: 2025/06/27 08:18:01 by nmascaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_position(t_stack_node *stack, t_stack_node *target)
{
	int	position;

	if (!stack || !target)
		return (-1);
	position = 0;
	while (stack)
	{
		if (stack == target)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

static t_stack_node	*create_stack_element(int value)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static void	add_to_stack_bottom(t_stack_node **stack, t_stack_node *new_node)
{
	t_stack_node	*temp;

	if (!*stack)
		*stack = new_node;
	else
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
}

bool	stack_initializing(int argc, int *numbers, t_stack_node **stack_a)
{
	int				i;
	t_stack_node	*new_node;

	i = 0;
	while (i < argc - 1)
	{
		new_node = create_stack_element(numbers[i]);
		if (!new_node)
			return (false);
		add_to_stack_bottom(stack_a, new_node);
		i++;
	}
	return (true);
}
