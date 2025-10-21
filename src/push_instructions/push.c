/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:31:28 by rafreire          #+#    #+#             */
/*   Updated: 2025/10/20 18:24:34 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->size_a == 0)
		return ;
	temp = stacks->stack_a[0];
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	i = stacks->size_b;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = temp;
	stacks->size_a--;
	stacks->size_b++;
	ft_putstr_fd("pb\n", 1);
}

void	push_a(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->size_b == 0)
		return ;
	temp = stacks->stack_b[0];
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	i = stacks->size_a;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = temp;
	stacks->size_a++;
	stacks->size_b--;
	ft_putstr_fd("pa\n", 1);
}
