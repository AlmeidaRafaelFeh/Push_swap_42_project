/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_duplicates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:19:36 by rafreire          #+#    #+#             */
/*   Updated: 2025/09/13 11:09:46 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_duplicates(long *numbers, int len)
{
	int	i;
	int	j;

	i = 0;
	if (numbers[i] == numbers[i + 1])
		return (1);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (numbers[i] == numbers[j])
				return (1);
		j++;
		}
	i++;
	}
	return (0);
}
