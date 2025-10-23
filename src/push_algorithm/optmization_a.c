/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optmization_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:58:51 by rafreire          #+#    #+#             */
/*   Updated: 2025/10/23 19:38:18 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cheaper(t_stacks *stacks)
{
	int	count_start;
	int	count_end;

	count_start = find_at_start(stacks);
	count_end = find_at_end(stacks);
	if (count_start <= count_end)
		return (count_start);
	else
	{
		count_end *= -1;
		return (count_end);
	}
}

int	find_at_start(t_stacks *stacks)
{
	int	count_start;
	int	to_find;
	int	i;

	i = 0;
	to_find = stacks->stack_a[0] - 1;
	count_start = 0;
	while (i < stacks->size_b)
	{
		if (stacks->stack_b[i] == to_find)
			break ;
		count_start++;
		i++;
	}
	return (count_start);
}

int	find_at_end(t_stacks *stacks)
{
	int	count_end;
	int	to_find;
	int	i;

	i = stacks->size_b - 1;
	to_find = stacks->stack_a[0] - 1;
	count_end = 0;
	while (i >= 0)
	{
		if (stacks->stack_b[i] == to_find)
			break ;
		count_end++;
		i--;
	}
	return (count_end);
}

// void	move_cheaper_first(t_stacks *stacks, int location, int min, int max)
// {
// 	int	moves;

// 	moves = find_cheaper(stacks, min, max);
// 	while (moves != 0)
// 	{
// 		if (moves > 0)
// 		{
// 			rotate_chunk(stacks, location);
// 			moves--;
// 		}
// 		else
// 		{
// 			if (location == TOP_A)
// 				rrotate_a(stacks);
// 			else if (location == TOP_B)
// 				rrotate_b(stacks);
// 			moves++;
// 		}
// 	}
// }
