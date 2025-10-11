/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:36:05 by rafreire          #+#    #+#             */
/*   Updated: 2025/10/10 20:46:37 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_chunk_info	get_chunk_info(int min, int max)
{
	t_chunk_info info;
	int	range;

	range = max - min + 1;
	info.chunk_size = range / 3;
	info.min_value = min;
	info.med_value = min + info.chunk_size;
	info.max_value = min + info.chunk_size * 2;
	return (info);
}

void	recursive_sort(t_stacks *stacks, int min, int max, int location)
{
	t_chunk_info info;

	info = get_chunk_info(min, max);
	if (max - min <= 2)
		lower_cases(stacks);
	//split_chunk(stacks, info, location);
	recursive_sort(stacks, info.med_value + 1, info.max_value, BOT_A);
	recursive_sort(stacks, info.min_value + 1, info.med_value, TOP_B);
	recursive_sort(stacks, info.min_value, info.med_value - 1, BOT_B);
}
