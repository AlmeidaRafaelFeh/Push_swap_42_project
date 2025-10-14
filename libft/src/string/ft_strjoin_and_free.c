/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:10:13 by rafreire          #+#    #+#             */
/*   Updated: 2025/09/12 19:18:10 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_and_free(char *s1, char const *s2)
{
	char		*newstr;
	size_t		real_len;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	real_len = ft_strlen(s1) + ft_strlen(s2);
	newstr = ft_calloc(real_len + 1, sizeof(char));
	if (!newstr)
		return (0);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i + j] = s2[j];
		j++;
	}
	free(s1);
	newstr[i + j] = '\0';
	return (newstr);
}

// int	verify_strings(char *s1, char const *s2)
// {
// 	if (!s1 && !s2)
// 		return (NULL);
// 	if (!s1)
// 		return (ft_strdup(s2));
// 	if (!s2)
// 		return (s1);
// }
