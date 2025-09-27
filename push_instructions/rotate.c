/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:33:26 by rafreire          #+#    #+#             */
/*   Updated: 2025/09/27 10:43:36 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	}
	else
		return ;
}
// #include <stdio.h>
// int main (void)
// {
// 	long test[4] = {0, -2 , 4, 10};
// 	int size = 4;
// 	int i = 0;
// 	int j = 0;
// 	t_stacks	stacks;

// 	stacks.stack_a = (int *)malloc(sizeof(int) * size);
// 	stacks.stack_b = (int *)malloc(sizeof(int) * size);
// 	while (i < size)
// 	{
// 		stacks.stack_a[i] = test[i];
// 		i++; 
// 	}
// 	while (j < size)
// 	{
// 		stacks.stack_b[j] = test[j];
// 		j++;
// 	}
// 	stacks.size_a = size;
// 	stacks.size_b = size;
// 	rotate_a(&stacks);
// 	rotate_b(&stacks);
// 	i = 0;
// 	j = 0;
// 	printf("stack A:\n");
// 	while (i < stacks.size_a)
// 	{
// 		printf("%d\n", stacks.stack_a[i]);
// 		i++;
// 	}
// 	printf("stack B:\n");
// 	while (j < stacks.size_b)
// 	{
// 		printf("%d\n", stacks.stack_b[j]);
// 		j++;
// 	}
// 	free(stacks.stack_a);
// 	free(stacks.stack_b);
// }
