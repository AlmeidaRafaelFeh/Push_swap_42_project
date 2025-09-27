/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:05:18 by rafreire          #+#    #+#             */
/*   Updated: 2025/09/27 09:48:39 by rafreire         ###   ########.fr       */
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
		mensage_error();
	size = numbers_len(args);
	stack = numbers_valid(args, size);
	new_stack_index(stack, size);
	create_struct_stacks(&stacks, stack, size);
	free(stacks.stack_a);
	free(stacks.stack_b);
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
