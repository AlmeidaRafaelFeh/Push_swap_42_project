/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:05:18 by rafreire          #+#    #+#             */
/*   Updated: 2025/09/13 12:13:41 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	char	*args;
	long	*numbers;

	if (ac < 2)
		mensage_error();
	args = parse_args(ac, av);
	numbers = numbers_valid(args);
	free(numbers);
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
