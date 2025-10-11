/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:43:56 by rafreire          #+#    #+#             */
/*   Updated: 2025/10/10 20:23:24 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*parse_args(int ac, char *av[])
{
	char	*nums_string;
	int		i;

	i = 1;
	nums_string = ft_calloc(1, 1);
	if (!nums_string)
		return (0);
	while (i < ac)
	{
		if (ft_strlen(av[i]) == 0)
			mensage_error();
		nums_string = ft_strjoin_and_free(nums_string, av[i]);
		nums_string = ft_strjoin_and_free(nums_string, " ");
		i++;
	}
	return (nums_string);
}

void	new_stack_index(int *stack, int *size)
{
	int	*aux;
	int	i;
	int	j;
	int	count;

	aux = malloc(sizeof(int) * *size);
	if (!aux)
		mensage_error_free(stack);
	i = 0;
	while (i < *size)
	{
		j = 0;
		count = 0;
		while (j < *size)
		{
			if (stack[j] < stack[i])
				count++;
		j++;
		}
		aux[i] = count;
		i++;
	}
	copy_stack_aux(stack, aux, size);
}

void	copy_stack_aux(int *stack, int *aux, int *size)
{
	int	i;

	i = 0;
	while (i < *size)
	{
		stack[i] = aux[i];
		i++;
	}
	free(aux);
}

void	create_struct_stacks(t_stacks *stacks, int *stack, int size)
{
	int	i;

	i = 0;
	stacks->stack_a = (int *)malloc(sizeof(int) * size);
	if (!stacks->stack_a)
		mensage_error_free(stack);
	stacks->stack_b = (int *)malloc(sizeof(int) * size);
	if (!stacks->stack_b)
		mensage_error_free(stack);
	while (i < size)
	{
		stacks->stack_a[i] = stack[i];
		i++;
	}
	stacks->size_a = size;
	stacks->size_b = 0;
	free(stack);
}

// #include <stdio.h>

// int main(void)
// {
//     int test[8] = {10, -2, 0, 126, 12, 8, 7, 5};
//     int size = 8;
//     int i = 0;

// 	new_stack_index(test, &size);
//     while (i < size)
//     {
//         printf("%d\n", test[i]);
//         i++;
//     }
// }
