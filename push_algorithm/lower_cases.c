/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:37:39 by rafreire          #+#    #+#             */
/*   Updated: 2025/10/10 12:40:46 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lower_cases(t_stacks *stacks)
{
	if (stacks->size_a <= 2)
		two_numbers(stacks);
	else if (stacks->size_a == 3)
		three_numbers(stacks);
	else
		five_numbers(stacks);
}

void	two_numbers(t_stacks *stacks)
{
	if (stacks->stack_a[0] > stacks->stack_a[1])
		swap_a(stacks);
	else
		return ;
}

void	three_numbers(t_stacks *stacks)
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
		two_numbers(stacks);
	else
		three_numbers(stacks);
	while (stacks->size_b != 0)
	{
		push_a(stacks);
	}
}

// #include <stdio.h>
// int main(void)
// {
// 	long testA[5] = {2, 1, 0, 4, 3};
// 	int size = 5;
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
// 	stacks.size_a = size;
//     stacks.size_b = 0;
// 	i = 0;
// 	printf("before A:\n");
// 	while (i < stacks.size_a)
// 	{
// 		printf("%d\n", stacks.stack_a[i]);
// 		i++;
// 	}
// 	lower_cases(&stacks);
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
