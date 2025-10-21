/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:05:18 by rafreire          #+#    #+#             */
/*   Updated: 2025/10/21 20:26:29 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char *av[])
{
	char		*args;
	int			*stack;
	int			size;
	t_stacks	stacks;

	if (ac < 2)
		mensage_error();
	args = parse_args(ac, av);
	if (ft_only_number(args) == 1)
	{
		free(args);
		mensage_error();
	}
	size = numbers_len(args);
	stack = numbers_valid(args, size);
	new_stack_index(stack, &size);
	create_struct_stacks(&stacks, stack, size);
	if (stacks.size_a <= 5)
		base_cases(&stacks);
	else
		recursive_sort(&stacks, 0, stacks.size_a, TOP_A);
	free(stacks.stack_a);
	free(stacks.stack_b);
}
