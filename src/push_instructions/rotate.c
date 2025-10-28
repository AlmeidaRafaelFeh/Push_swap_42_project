/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:33:26 by rafreire          #+#    #+#             */
/*   Updated: 2025/10/27 23:01:25 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->size_a >= 2)
	{
		temp = stacks->stack_a[0];
		i = 0;
		while (i < stacks->size_a - 1)
		{
			stacks->stack_a[i] = stacks->stack_a[i + 1];
			i++;
		}
		stacks->stack_a[i] = temp;
		ft_putstr_fd("ra\n", 1);
	}
	else
		return ;
}

void	rotate_b(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->size_b >= 2)
	{
		temp = stacks->stack_b[0];
		i = 0;
		while (i < stacks->size_b - 1)
		{
			stacks->stack_b[i] = stacks->stack_b[i + 1];
			i++;
		}
		stacks->stack_b[i] = temp;
		ft_putstr_fd("rb\n", 1);
	}
	else
		return ;
}

void	double_rotate(t_stacks	*stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
}