/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:19:41 by rafreire          #+#    #+#             */
/*   Updated: 2025/09/13 15:48:00 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_only_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (ft_ispace(str[i]))
			i++;
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
			return (1);
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] && !ft_ispace(str[i]))
			return (1);
	i++;
	}
	return (0);
}
