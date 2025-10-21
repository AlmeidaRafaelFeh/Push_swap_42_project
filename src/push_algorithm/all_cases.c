/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:36:05 by rafreire          #+#    #+#             */
/*   Updated: 2025/10/21 20:30:56 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_chunk_info	get_chunk_info(int min, int max)
{
	t_chunk_info	info;
	int				range;
	int				chunk;

	range = max - min + 1;
	chunk = range / 3;
	if (chunk == 0)
		chunk = 1;
	info.chunk_size = chunk;
	info.min_value = min;
	info.med_value = min + chunk - 1;
	info.max_value = min + (chunk * 2) - 1;
	if (info.med_value > max)
		info.med_value = max;
	if (info.max_value > max)
		info.max_value = max;
	return (info);
}

void	recursive_sort(t_stacks *stacks, int min, int max, int location)
{
	t_chunk_info	info;

	info = get_chunk_info(min, max);
	if (max - min + 1 <= 3)
	{
		lower_cases(stacks, location, min, max);
		return ;
	}
	split_chunk(stacks, info, location);
	if (info.max_value < max)
		recursive_sort(stacks, info.max_value + 1, max, BOT_A);
	if (info.med_value + 1 <= info.max_value)
		recursive_sort(stacks, info.med_value + 1, info.max_value, TOP_B);
	if (info.min_value <= info.med_value)
		recursive_sort(stacks, info.min_value, info.med_value, BOT_B);
	ordenate_stack_b(stacks, 0, stacks->size_b, TOP_B);
}

void	ordenate_stack_b(t_stacks *stacks, int min, int max, int location)
{
	int	top_value;
	int	current_number;
	int	safety;

	safety = 0;
	while (stacks->size_b >= 0)
	{
		current_number = stacks->stack_a[0] - 1;
		top_value = get_top_value(stacks, location);
		if (safety++ > stacks->size_a + stacks->size_b * 5)
			break ;
		if (exists_in_stack(stacks, TOP_B, min, max))
		{
			if (top_value >= min && top_value <= max)
			{
				if (top_value == current_number)
				{
					push_a(stacks);
					current_number -= 1;
				}
				else
					rotate_b(stacks);
			}
		}
	}
}

void	split_chunk(t_stacks *stacks, t_chunk_info info, int location)
{
	int	top_value;
	int	safety;

	safety = 0;
	while (exists_in_stack(stacks, location, info.min_value, info.max_value))
	{
		if (safety++ > stacks->size_a + stacks->size_b * 5)
			break ;
		top_value = get_top_value(stacks, location);
		if (top_value <= info.med_value)
		{
			push_to(location, TOP_B, stacks);
			rotate_location(stacks, TOP_B);
		}
		else if (top_value <= info.max_value)
			push_to(location, TOP_B, stacks);
		else
			rotate_location(stacks, location);
	}
}

int	exists_in_stack(t_stacks *stacks, int location, int min, int max)
{
	int	i;
	int	size;
	int	*stack;

	if (location == TOP_A || location == BOT_A)
	{
		stack = stacks->stack_a;
		size = stacks->size_a;
	}
	else
	{
		stack = stacks->stack_b;
		size = stacks->size_b;
	}
	i = 0;
	while (i < size)
	{
		if (stack[i] >= min && stack[i] <= max)
			return (1);
		i++;
	}
	return (0);
}
