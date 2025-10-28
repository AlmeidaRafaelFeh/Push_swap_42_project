/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:36:05 by rafreire          #+#    #+#             */
/*   Updated: 2025/10/27 23:35:10 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks_to_b(t_stacks *stack, int chunks)
{
	t_chunk	chunk;
	int		c;
	int		idx;
	int		val_idx;

	chunk = get_chunk_info(stack, chunks);
	c = 1;
    while (c <= chunks)
    {   
        while ((idx = find_index_a(stack, chunk.chunk_start, chunk.chunk_end)) != -1)
        {
			rotate_until_top_a(stack, idx);
            val_idx = stack->stack_a[0];
            push_b(stack);
			maybe_rotate_b(stack, &chunk, val_idx);
        }
		chunk.chunk_start = chunk.chunk_end + 1;
		chunk.chunk_end = chunk.chunk_start + chunk.chunk_size - 1;
		if (chunk.chunk_end >= chunk.att_size_a)
			chunk.chunk_end = chunk.att_size_a - 1;
	c++;
    }
}

void	push_back_to_a(t_stacks *stack)
{
	int	idx;
	int	steps;

	while (stack->size_b > 0)
	{
		idx = find_higher_index_b(stack);
		if (idx == -1)
			break;
		if (idx <= stack->size_b / 2)
			while (idx > 0)
			{
				rotate_b(stack);
				idx--;
			}
		else
		{
			steps = stack->size_b - idx;
			while (steps > 0)
			{
				rrotate_b(stack);
				steps--;
			}
		}
	push_a(stack);
	}
}

void	sort_main(t_stacks *stack)
{
	int	num_chunks;

	if (stack->size_a <= 5)
	{
		base_cases(stack);
		return ;
	}
	if (stack->size_a <= 10)
		num_chunks = 1;
	else if (stack->size_a <= 100)
		num_chunks = 5;
	else
		num_chunks = 8;	
	push_chunks_to_b(stack, num_chunks);
	push_back_to_a(stack);
}
