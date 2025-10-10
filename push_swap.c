/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:05:18 by rafreire          #+#    #+#             */
/*   Updated: 2025/10/10 15:17:57 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	new_stack_index(stack, size);
	create_struct_stacks(&stacks, stack, size);	
}

t_chunk_info	get_chunk_info(t_stacks *stacks)
{
	int	chunk_size;
	int	chunk_count;
	int	remainder;

	chunk_size = 0;
	chunk_count = 0;
	remainder = 0;
	if (stacks->size_a <= 5)
		lower_cases(stacks);
	else if (stacks->size_a <= 19)
		chunk_size = stacks->size_a / 2;
	else if (stacks->size_a <= 100)
		chunk_size = 20;
	else
		chunk_size = stacks->size_a / 25;
	chunk_count = stacks->size_a / chunk_size;
	remainder = stacks->size_a % chunk_size;
}

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
