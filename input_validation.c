/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascaro <nmascaro@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:09:51 by nmascaro          #+#    #+#             */
/*   Updated: 2025/06/25 10:05:27 by nmascaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static bool	is_numeric_string(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (false);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

static bool	has_duplicates(int *numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static bool	is_valid_argument(char *arg, long *out_value)
{
	if (!is_numeric_string(arg))
		return (false);
	*out_value = ft_atol(arg);
	if (*out_value < INT_MIN || *out_value > INT_MAX)
		return (false);
	return (true);
}

bool	input_validation(int argc, char *argv[], int *numbers)
{
	int		i;
	long	value;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_argument(argv[i], &value))
			return (false);
		numbers[i - 1] = (int)value;
		i++;
	}
	if (has_duplicates(numbers, argc - 1))
		return (false);
	return (true);
}
