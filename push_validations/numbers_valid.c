/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:20:07 by rafreire          #+#    #+#             */
/*   Updated: 2025/09/13 12:12:36 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

long	*numbers_valid(char *str)
{
	int		len_numbers;
	long	*numbers;

	if (ft_only_number(str) == 1)
		mensage_error();
	len_numbers = numbers_len(str);
	numbers = (long *)malloc(sizeof(long) * len_numbers);
	if (!numbers)
		return (0);
	clean_copy_arr(numbers, str);
	if (is_min_max(numbers, len_numbers) == 1)
	{
		free (numbers);
		mensage_error();
	}
	if (ft_check_duplicates(numbers, len_numbers) == 1)
	{
		free (numbers);
		mensage_error();
	}
	return (numbers);
}	

int	numbers_len(char *str)
{
	int	i;
	int	len_numbers;

	i = 0;
	len_numbers = 0;
	while (ft_ispace(str[i]))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (ft_isdigit(str[i]))
		{
			len_numbers++;
			while (ft_isdigit(str[i]))
				i++;
		}
	i++;
	}
	return (len_numbers);
}

void	clean_copy_arr(long *numbers, char *str)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (str[j])
	{
		numbers[i++] = ft_atol(&str[j]);
		if (str[j] == '+' || str[j] == '-')
			j++;
		while (ft_isdigit(str[j]))
			j++;
		while (ft_ispace(str[j]))
			j++;
	}
}
