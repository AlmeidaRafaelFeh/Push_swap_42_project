/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optmization.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:58:51 by rafreire          #+#    #+#             */
/*   Updated: 2025/10/22 21:48:49 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cheaper(t_stacks *stacks, int min, int max)
{
	int	count_start;
    int count_end;

    count_start = find_at_start(stacks, min, max);
    count_end = find_at_end(stacks, min, max);
	if (count_start <= count_end)
        return (count_start);
    else 
        return (count_end);
}

int find_at_start(t_stacks *stacks, int min, int max)
{
    int	count_start;
    int i;

    i = 0;
    count_start = 0;
	while (i < stacks->size_a)
	{
		if (stacks->stack_a[i] >= min && stacks->stack_a[i] <= max)
			break ;
        count_start++;
        i++;
	}
    return (count_start);
}

int find_at_end(t_stacks *stacks, int min, int max)
{
    int count_end;
    int i;

    i = stacks->size_a - 1;
    count_end = 0;
    while (i >= 0)
    {
        if (stacks->stack_a[i] >= min && stacks->stack_a[i] <= max)
            break;
        count_end++;
        i--;
    }
    return (count_end);
}