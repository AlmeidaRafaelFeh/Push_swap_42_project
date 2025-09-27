/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:20:07 by rafreire          #+#    #+#             */
/*   Updated: 2025/09/26 20:29:14 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*numbers_valid(char *str, int len_numbers)
{
	long	*numbers;
	int		*integer_nbs;
	int		i;

	i = 0;
	numbers = (long *)malloc(sizeof(long) * len_numbers);
	if (!numbers)
		return (0);
	clean_copy_arr(numbers, str);
	if (is_min_max(numbers, len_numbers) == 1)
		mensage_error_free_long(numbers);
	if (ft_check_duplicates(numbers, len_numbers) == 1)
		mensage_error_free_long(numbers);
	integer_nbs = (int *)malloc(sizeof(int) * len_numbers);
	if (!integer_nbs)
		return (0);
	while (i < len_numbers)
	{
		integer_nbs[i] = (int)numbers[i];
		i++;
	}
	free(numbers);
	return (integer_nbs);
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
