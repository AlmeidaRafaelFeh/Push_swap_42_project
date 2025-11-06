/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:28:00 by rafreire          #+#    #+#             */
/*   Updated: 2025/11/06 10:54:14 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_higher_index_b(t_stacks *stack)
{
	int	higher;
	int	index_higher;
	int	i;

	higher = stack->stack_b[0];
	index_higher = 0;
	i = 1;
	if (stack->size_b == 0)
		return (-1);
	while (i < stack->size_b)
	{
		if (stack->stack_b[i] > higher)
		{
			higher = stack->stack_b[i];
			index_higher = i;
		}
	i++;
	}
	return (index_higher);
}

int	find_index_a(t_stacks *stack, int start, int end)
{
	int	i;

	i = 0;
	while (i < stack->size_a)
	{
		if (stack->stack_a[i] >= start && stack->stack_a[i] <= end)
			return (i);
	i++;
	}
	return (-1);
}

t_chunk	get_chunk_info(t_stacks *stack, int chunks)
{
	t_chunk	chunk;

	chunk.att_size_a = stack->size_a;
	chunk.chunk_size = (chunk.att_size_a + chunks - 1) / chunks;
	chunk.chunk_start = 0;
	chunk.chunk_end = chunk.chunk_size - 1;
	if (chunk.chunk_end >= chunk.att_size_a)
		chunk.chunk_end = chunk.att_size_a - 1;
	return (chunk);
}

void	rotate_until_top_a(t_stacks *stack, int idx)
{
	int	steps;

	steps = 0;
	if (idx <= stack->size_a / 2)
	{
		while (idx > 0)
		{
			rotate_a(stack);
			idx--;
		}
	}
	else
	{
		steps = stack->size_a - idx;
		while (steps > 0)
		{
			rrotate_a(stack);
			steps--;
		}
	}
}

void	maybe_rotate_b(t_stacks *stack, t_chunk *chunk, int val_idx)
{
	int	chunk_mid;
	int	top_b;

	top_b = 0;
	chunk_mid = chunk->chunk_start + (chunk->chunk_size / 2);
	if (stack->size_b > 0)
		top_b = stack->stack_b[0];
	else
		top_b = -1;
	if (val_idx <= chunk_mid || val_idx > top_b)
		rotate_b(stack);
}
