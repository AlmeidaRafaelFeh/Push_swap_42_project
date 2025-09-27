/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mensage_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:18:41 by rafreire          #+#    #+#             */
/*   Updated: 2025/09/27 09:48:10 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	mensage_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	mensage_error_free(int *stack)
{
	free(stack);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	mensage_error_free_long(long *stack)
{
	free(stack);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	mensage_error_free_struct(t_stacks *stacks)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
