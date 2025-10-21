/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:30:42 by rafreire          #+#    #+#             */
/*   Updated: 2025/10/20 18:22:55 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_a >= 2)
	{
		temp = stacks->stack_a[0];
		stacks->stack_a[0] = stacks->stack_a[1];
		stacks->stack_a[1] = temp;
		ft_putstr_fd("sa\n", 1);
	}
	else
		return ;
}

void	swap_b(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_b >= 2)
	{
		temp = stacks->stack_b[0];
		stacks->stack_b[0] = stacks->stack_b[1];
		stacks->stack_b[1] = temp;
		ft_putstr_fd("sb\n", 1);
	}
	else
		return ;
}

void	swap_ss(t_stacks *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}
