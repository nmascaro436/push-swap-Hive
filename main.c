/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascaro <nmascaro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:05:40 by nmascaro          #+#    #+#             */
/*   Updated: 2025/06/18 13:59:40 by nmascaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	process_arguments(int argc, char *argv[], t_stack_node **stack_a)
{
	int	*numbers;

	numbers = malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		return (0);
	if (!input_validation(argc, argv, numbers))
	{
		free(numbers);
		write(2, "Error\n", 6);
		return (0);
	}
	if (!stack_initializing(argc, numbers, stack_a))
	{
		free(numbers);
		free_stack(stack_a);
		write(2, "Error\n", 6);
		return (0);
	}
	free(numbers);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!process_arguments(argc, argv, &stack_a))
		return (1);
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
