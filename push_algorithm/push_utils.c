/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:28:00 by rafreire          #+#    #+#             */
/*   Updated: 2025/10/11 19:37:24 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_top_value(t_stacks *stacks, int location)
{
	if (location == TOP_A)
		return (stacks->stack_a[0]);
	else if (location == BOT_A)
		return (stacks->stack_a[stacks->size_a - 1]);
	else if (location == TOP_B)
		return (stacks->stack_b[0]);
	else if (location == BOT_B)
		return (stacks->stack_b[stacks->size_a - 1]);
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
	if (to == TOP_A || to == BOT_A)
		push_a(stacks);
	else if (to == TOP_B || to == BOT_B)
		push_b(stacks); 
}
