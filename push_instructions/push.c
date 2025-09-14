/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:31:28 by rafreire          #+#    #+#             */
/*   Updated: 2025/09/13 21:08:26 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// function push b e push a
// recebe 4 ponteiros sendo stack a, stack b, size a, size b
// coloca a primeira posicao da stack selecionada na outra ex: (a)[0] = (b)[0]
// size a ou b decrementa 1
// size b ou a incrementa 1

void	push_b(long *stack_a, long *stack_b, int *size_a, int *size_b)
{
	int	temp;

	temp = stack_a[0];
	stack_b[0] = temp;
	size_a--;
	size_b++;
}

void	push_a(long *stack_a, long *stack_b, int *size_a, int *size_b)
{
	int	temp;

	temp = stack_b[0];
	stack_a[0] = temp;
	size_a++;
	size_b--;
}
