/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:37:39 by rafreire          #+#    #+#             */
/*   Updated: 2025/11/06 10:51:56 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_numbers(t_stacks *stacks)
{
	if (stacks->stack_a[0] > stacks->stack_a[1])
		swap_a(stacks);
	else
		return ;
}

void	three_numbers(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->stack_a[0];
	b = stacks->stack_a[1];
	c = stacks->stack_a[2];
	if (a < b && b < c)
		return ;
	else if (a > b && b < c && a < c)
		swap_a(stacks);
	else if (a > b && b > c)
	{
		swap_a(stacks);
		rrotate_a(stacks);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stacks);
	else if (a < b && b > c && a < c)
	{
		swap_a(stacks);
		rotate_a(stacks);
	}
	else if (a < b && b > c && a > c)
		rrotate_a(stacks);
}

void	five_numbers(t_stacks *stacks)
{
	while (stacks->size_b < 2)
	{
		if (stacks->stack_a[0] == 0 || stacks->stack_a[0] == 1)
			push_b(stacks);
		else
			rotate_a(stacks);
	}
	if (stacks->stack_b[0] < stacks->stack_b[1])
		swap_b(stacks);
	if (stacks->size_a == 2)
		two_numbers(stacks);
	else
		three_numbers(stacks);
	while (stacks->size_b != 0)
	{
		push_a(stacks);
	}
}

void	base_cases(t_stacks *stacks)
{
	if (stacks->size_a <= 2)
		two_numbers(stacks);
	else if (stacks->size_a == 3)
		three_numbers(stacks);
	else if (stacks->size_a <= 5)
		five_numbers(stacks);
}
