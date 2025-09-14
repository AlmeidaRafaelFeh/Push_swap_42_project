/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:05:18 by rafreire          #+#    #+#             */
/*   Updated: 2025/09/13 20:49:05 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char *av[])
{
	char	*args;
	long	*stack_a;
	long	*stack_b;
	int		size_a;
	int		size_b;

	if (ac < 2)
		mensage_error();
	args = parse_args(ac, av);
	if (ft_only_number(args) == 1)
		mensage_error();
	size_a = numbers_len(args);
	size_b = 0;
	stack_a = numbers_valid(args, size_a);
	stack_b = (long *)malloc(sizeof(long) * size_a);
	free(stack_a);
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
