/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:28:00 by rafreire          #+#    #+#             */
/*   Updated: 2025/10/21 20:28:56 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_top_value(t_stacks *stacks, int location)
{
	if (location == TOP_A)
		return (stacks->stack_a[0]);
	else if (location == BOT_A)
		return (stacks->stack_a[stacks->size_a - 1]);
	else if (location == TOP_B)
		return (stacks->stack_b[0]);
	else if (location == BOT_B)
		return (stacks->stack_b[stacks->size_b - 1]);
	return (0);
}

void	rotate_location(t_stacks *stacks, int location)
{
	if (location == TOP_A)
		rotate_a(stacks);
	else if (location == TOP_B)
		rotate_b(stacks);
	else if (location == BOT_A)
		rrotate_a(stacks);
	else if (location == BOT_B)
		rrotate_b(stacks);
}

void	push_to(int from, int to, t_stacks *stacks)
{
	if (from == TOP_A && (to == TOP_B || to == BOT_B))
		push_b(stacks);
	else if (from == TOP_B && (to == TOP_A || to == BOT_A))
		push_a(stacks);
	else if (from == BOT_A && (to == TOP_B || to == BOT_B))
	{
		rrotate_a(stacks);
		push_b(stacks);
	}
	else if (from == BOT_B && (to == TOP_A || to == BOT_A))
	{
		rrotate_b(stacks);
		push_a(stacks);
	}
}

void	lower_cases(t_stacks *stacks, int location, int min, int max)
{
	int	chunk_size;

	chunk_size = max - min;
	if (location == TOP_A || location == BOT_A)
	{
		if (chunk_size == 2)
			two_numbers_a(stacks);
		else if (chunk_size == 3)
			three_numbers_a(stacks);
		else if (chunk_size == 1)
			return ;
	}
	else
	{
		if (chunk_size == 2)
			two_numbers_b(stacks);
		else if (chunk_size == 3)
			three_numbers_b(stacks);
		else if (chunk_size == 1)
			return ;
	}
}

void	base_cases(t_stacks *stacks)
{
	if (stacks->size_a <= 2)
		two_numbers_a(stacks);
	else if (stacks->size_a == 3)
		three_numbers_a(stacks);
	else if (stacks->size_a <= 5)
		five_numbers(stacks);
}
