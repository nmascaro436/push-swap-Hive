/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascaro <nmascaro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:57:22 by nmascaro          #+#    #+#             */
/*   Updated: 2025/06/25 12:31:00 by nmascaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	sort_four(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*min;

	min = find_min(*stack_a);
	move_to_top(stack_a, min, 'a');
	pb(stack_a, stack_b);
	sort_three_nodes(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*min;
	int				i;

	i = 0;
	while (i < 2)
	{
		min = find_min(*stack_a);
		move_to_top(stack_a, min, 'a');
		pb(stack_a, stack_b);
		i++;
	}
	sort_three_nodes(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_small_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	if (len == 4)
		sort_four(stack_a, stack_b);
	else if (len == 5)
		sort_five(stack_a, stack_b);
}
