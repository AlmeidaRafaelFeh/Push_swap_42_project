/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:37:39 by rafreire          #+#    #+#             */
/*   Updated: 2025/10/21 20:21:56 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_numbers_a(t_stacks *stacks)
{
	if (stacks->stack_a[0] > stacks->stack_a[1])
		swap_a(stacks);
	else
		return ;
}

void	three_numbers_a(t_stacks *stacks)
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

void	two_numbers_b(t_stacks *stacks)
{
	if (stacks->stack_b[0] > stacks->stack_b[1])
		swap_b(stacks);
	else
		return ;
}

void	three_numbers_b(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->stack_b[0];
	b = stacks->stack_b[1];
	c = stacks->stack_b[2];
	if (a < b && b < c)
		return ;
	else if (a > b && b < c && a < c)
		swap_b(stacks);
	else if (a > b && b > c)
	{
		swap_b(stacks);
		rrotate_b(stacks);
	}
	else if (a > b && b < c && a > c)
		rotate_b(stacks);
	else if (a < b && b > c && a < c)
	{
		swap_b(stacks);
		rotate_b(stacks);
	}
	else if (a < b && b > c && a > c)
		rrotate_b(stacks);
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
		two_numbers_a(stacks);
	else
		three_numbers_a(stacks);
	while (stacks->size_b != 0)
	{
		push_a(stacks);
	}
}
