/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:36:05 by rafreire          #+#    #+#             */
/*   Updated: 2025/10/11 19:55:40 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_chunk_info	get_chunk_info(int min, int max)
{
	t_chunk_info	info;
	int				range;

	range = max - min + 1;
	info.chunk_size = range / 3;
	info.min_value = min;
	info.med_value = min + info.chunk_size;
	info.max_value = min + info.chunk_size * 2;
	return (info);
}

void	recursive_sort(t_stacks *stacks, int min, int max, int location)
{
	t_chunk_info	info;

	info = get_chunk_info(min, max);
	if (max - min <= 2)
		lower_cases(stacks);
	split_chunk(stacks, info, location);
	recursive_sort(stacks, info.med_value + 1, info.max_value, BOT_A);
	recursive_sort(stacks, info.min_value + 1, info.med_value, TOP_B);
	recursive_sort(stacks, info.min_value, info.med_value - 1, BOT_B);
}

void	split_chunk(t_stacks *stacks, t_chunk_info info, int location)
{
	int	move;
	int	top_value;

	move = 0;
	while (move < info.chunk_size)
	{
		top_value = get_top_value(stacks, location);
		if (top_value >= info.med_value + 1 && top_value <= info.max_value)
			rotate_location(location, stacks);
		else if (top_value >= info.min_value + 1 && top_value <= info.med_value)
			push_to(location, TOP_B, stacks);
		else if (top_value >= info.min_value && top_value <= info.med_value - 1)
		{
			push_to(location, TOP_B, stacks);
			rotate_location(TOP_B, stacks);
		}
	move++;
	}
}

