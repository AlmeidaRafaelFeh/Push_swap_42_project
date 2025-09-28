/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:37:39 by rafreire          #+#    #+#             */
/*   Updated: 2025/09/27 19:32:25 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two_numbers(t_stacks *stacks)
{
	if (stacks->stack_a[0] > stacks->stack_a[1])
		swap_a(stacks);
	else
		return ;
}

void	three_numbers(t_stacks *stacks)
{
	if (stacks->stack_a[0] == 2 && stacks->stack_a[1] == 1)
	{
		swap_a(stacks);
		rrotate_a(stacks);
	}
	if (stacks->stack_a[0] == 1 && stacks->stack_a[1] == 2)
	{
		rrotate_a(stacks);
		swap_a(stacks);
	}
	if (stacks->stack_a[0] == 2 && stacks->stack_a[1] == 0)
		rotate_a(stacks);
	if (stacks->stack_a[0] == 0 && stacks->stack_a[1] == 2)
		rrotate_a(stacks);
	if (stacks->stack_a[0] == 1 && stacks->stack_a[1] == 0)
		swap_a(stacks);
}

void	five_numbers(t_stacks *stacks)
{
	
}

// #include <stdio.h>
// int main(void)
// {
// 	long testA[4] = {1, 2 , 0};
// 	long testB[4] = {0, 2 , 1};
// 	int size = 3;
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
// 	i = 0;
// 	printf("before A:\n");
// 	while (i < stacks.size_a)
// 	{
// 		printf("%d\n", stacks.stack_a[i]);
// 		i++;
// 	}
// 	three_cases(&stacks);
// 	i = 0;
// 	j = 0;
// 	printf("stack A:\n");
// 	while (i < stacks.size_a)
// 	{
// 		printf("%d\n", stacks.stack_a[i]);
// 		i++;
// 	}
// 	three_cases(&stacks);
// 	printf("stack B:\n");
// 	while (j < stacks.size_a)
// 	{
// 		printf("%d\n", stacks.stack_a[j]);
// 		j++;
// 	}
// 	free(stacks.stack_a);
// 	free(stacks.stack_b);
// }
