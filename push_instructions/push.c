/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:31:28 by rafreire          #+#    #+#             */
/*   Updated: 2025/09/27 11:04:49 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
}

// #include <stdio.h>
// int main (void)
// {
// 	int test[10] = {10, 2, 4, 6};
// 	int test2[10] = {12, 3, 5, 7};
// 	int size = 4;
// 	int size_b = 4;
// 	int i = 0;
// 	int j = 0;
// 	t_stacks	stacks;

// 	stacks.stack_a = malloc(sizeof(int) * size);
//  	stacks.stack_b = malloc(sizeof(int) * size_b);
// 	while (i < size)
// 	{
// 		stacks.stack_a[i] = test[i];
// 		i++;
// 	}
// 	while (j < size)
// 	{
// 		stacks.stack_b[j] = test2[j];
// 		j++;
// 	}
// 	stacks.size_a = size;
//     stacks.size_b = size_b;
// 	push_a(&stacks);
// 	i = 0;
// 	j = 0;
// 	printf("Stack A:\n");
// 	while (i < stacks.size_a)
// 	{
// 		printf("%d\n", stacks.stack_a[i]);
// 		i++;
// 	}
// 	printf("Stack B:\n");
// 	while (j < stacks.size_b)
// 	{
// 		printf("%d\n", stacks.stack_b[j]);
// 		j++;
// 	}
// 	free(stacks.stack_a);
// 	free(stacks.stack_b);
// }