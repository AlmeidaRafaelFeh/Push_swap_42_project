/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:30:42 by rafreire          #+#    #+#             */
/*   Updated: 2025/09/27 10:29:29 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stacks *stacks)
{
	int	temp1;
	int	temp2;

	temp1 = stacks->stack_a[0];
	temp2 = stacks->stack_b[0];
	stacks->stack_a[0] = temp2;
	stacks->stack_b[0] = temp1;
}

// #include <stdio.h>
// int main (void)
// {
// 	long testA[4] = {10, 2 , 4, 6};
// 	long testB[4] = {12, 2 , 4, 6};
// 	int size = 4;
// 	int i = 0;
// 	int j = 0;
// 	t_stacks	stacks;
// 	stacks.stack_a = malloc(sizeof(int) * size);
// 	stacks.stack_b = malloc(sizeof(int) * size);

// 	while (i < size)
// 	{
// 		stacks.stack_a[i] = testA[i];
// 		i++;
// 	}
// 	while (j < size)
// 	{
// 		stacks.stack_b[j] = testB[j];
// 		j++;
// 	}
// 	stacks.size_a = size;
//     stacks.size_b = size;
// 	swap(&stacks);
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